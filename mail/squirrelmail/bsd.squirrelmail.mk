# $FreeBSD$
#
# $LastChangedDate: 2010-02-01 22:21:34 -0500 (Mon, 01 Feb 2010) $
#
# To create a plugin, put the following at the bottom of your makefile:
#
# .include <bsd.port.pre.mk>
# .include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
# .include <bsd.port.post.mk>
#
# Variables you can set:
# USE_SM_COMPAT = creates a dependency on mail/squirrelmail-compatibility-plugin
# USE_GENERIC_PKGMESSAGE = to use a default message about editing config.php
# 	*****NOTE this clobbers FILESDIR, so you cannot use this if you have any files/patch-*
# SQUIRREL_PLUGIN_NAME = defaults to PORTNAME
# SQUIRREL_PLUGIN_CONFIG = the config file name (for the PKGMESSAGE)
# _SMSRCDIR = WRKSRC=${WRKDIR}/${_SMSRCDIR}
#
#
# Created & tested by 
# Thomas Abthorpe <tabthorpe@FreeBSD.org>
# Philippe Audeoud <jadawin@FreeBSD.org>
# Some enhancements by
# Ion-Mihai "IOnut" Tetcu <itetcu@FreeBSD.org>
# Adam Weinberger <adamw@FreeBSD.org>
#
# This code is still a work in progress, and will likely need further
# tweaking. Feedback is always welcome.
#

MASTER_SITES?=	http://www.squirrelmail.org/plugins/
PKGNAMEPREFIX?=	squirrelmail-
PKGNAMESUFFIX?=	-plugin
DIST_SUBDIR?=	squirrelmail

RUN_DEPENDS+=	${SQUIRRELDIR}/index.php:${PORTSDIR}/mail/squirrelmail

.ifdef USE_SM_COMPAT
RUN_DEPENDS+=	${SQUIRRELDIR}/plugins/compatibility:${PORTSDIR}/mail/squirrelmail-compatibility-plugin
.endif

.ifndef WITHOUT_ACTIVATE
USES+=		perl5
USE_PERL5+=	install
.endif

NO_BUILD=		yes
NO_WRKSUBDIR=	yes
USE_PHP?=		yes
WANT_PHP_WEB=	yes

SQUIRREL_PLUGIN_NAME?=   ${PORTNAME}
PLIST_SUB+=     SQUIRREL_PLUGIN_NAME=${SQUIRREL_PLUGIN_NAME}
SUB_LIST+=		SQUIRREL_PLUGIN_NAME=${SQUIRREL_PLUGIN_NAME}

# As with mail/squirreldir, if you were using WITHOUT_WWWDIR=yes,
# set SQUIRRELDIR=${PREFIX}/squirrelmail
SQUIRRELDIR?=	${PREFIX}/www/squirrelmail
PLIST_SUB+=		SQUIRRELDIR=${SQUIRRELDIR:S,${PREFIX}/,,}
SUB_LIST+=		SQUIRRELDIR=${SQUIRRELDIR}

SQUIRREL_PLUGIN_CONFIG?=	config.php
PLIST_SUB+=		SQUIRREL_PLUGIN_CONFIG=${SQUIRREL_PLUGIN_CONFIG}
SUB_LIST+=		SQUIRREL_PLUGIN_CONFIG=${SQUIRREL_PLUGIN_CONFIG}

.if defined(USE_GENERIC_PKGMESSAGE)
# NOTE: we have to change FILESDIR to make this work...
FILESDIR=	${.CURDIR}/../squirrelmail/files
SUB_FILES+=	plugin-pkg-message
PKGMESSAGE=	${WRKDIR}/plugin-pkg-message
.elif exists(${FILESDIR}/pkg-message.in)
SUB_FILES+=	pkg-message
.endif

.if !target(pre-everything)
pre-everything::
	@${ECHO_CMD} ""
.ifndef WITHOUT_ACTIVATE
	@${ECHO_CMD} "Activating plug-in in SquirrelMail after installation."
	@${ECHO_CMD} "If you don't want to automatically activate the plug-in set"
	@${ECHO_CMD} "WITHOUT_ACTIVATE=yes"
.else
	@${ECHO_CMD} "NOT Activating plug-in in SquirrelMail after installation."
	@${ECHO_CMD} "If you want to automatically activate the plug-in unset"
	@${ECHO_CMD} "WITHOUT_ACTIVATE"
.endif
	@${ECHO_CMD} ""
.endif

_SMSRCDIR?=	${SQUIRREL_PLUGIN_NAME}

.if !target(do-install)
do-install:
	cd ${WRKSRC}/${_SMSRCDIR} && ${FIND} -d . | \
		${CPIO} -dump ${SQUIRRELDIR}/plugins/${SQUIRREL_PLUGIN_NAME} >/dev/null 2>&1 && \
	${FIND} ${SQUIRRELDIR}/plugins/${SQUIRREL_PLUGIN_NAME} \
		-type d -exec chmod 755 {} \; && \
	${FIND} ${SQUIRRELDIR}/plugins/${SQUIRREL_PLUGIN_NAME} \
		-type f -exec chmod 644 {} \;
.endif

.if !target(post-install)
post-install:
.ifndef WITHOUT_ACTIVATE
.if exists( ${SQUIRRELDIR}/config/config.php )
	@${ECHO_CMD} "Activating plug-in in SquirrelMail"
	${SQUIRRELDIR}/config/conf.pl --install-plugin ${SQUIRREL_PLUGIN_NAME}
.endif
.else
	@${ECHO_CMD} "To activate the plug-in in SquirrelMail use"
	@${ECHO_CMD} "${SQUIRRELDIR}/config/conf.pl --install-plugin ${SQUIRREL_PLUGIN_NAME}"
.endif
	@${ECHO_CMD} ""

.if exists(${FILESDIR}/pkg-message.in) || exists(${FILESDIR}/plugin-pkg-message.in)
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""
.endif
.endif
