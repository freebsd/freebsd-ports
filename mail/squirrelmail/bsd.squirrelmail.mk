# $FreeBSD$
#
# $Id: bsd.squirrelmail.mk 23 2008-12-03 16:17:48Z tabthorpe $
#
# Common code for squirrelmail plugins.
#
# Created & tested by 
# Thomas Abthorpe <tabthorpe@FreeBSD.org>
# Philippe Audeoud <jadawin@FreeBSD.org>
#
# This code is still a work in progress, and will likely need further
# tweaking. Feedback is always welcome.
#

RUN_DEPENDS+=		 ${SQUIRRELDIR}/index.php:${PORTSDIR}/mail/squirrelmail

NO_BUILD=		yes
NO_WRKSUBDIR=		yes
USE_PERL5_BUILD=	yes
USE_PHP=		yes
WANT_PHP_WEB=		yes

SQUIRREL_PLUGIN_NAME=   ${PORTNAME}

.ifdef SQUIRRELDIR
PLIST_SUB+=     SQUIRRELDIR=${SQUIRRELDIR}
SUB_LIST+=      SQUIRRELDIR=${SQUIRRELDIR}
.else
.ifndef WITHOUT_WWWDIR
SQUIRRELDIR=    ${PREFIX}/www/squirrelmail
PLIST_SUB+=     SQUIRRELDIR=www/squirrelmail
SUB_LIST+=      SQUIRRELDIR=www/squirrelmail
.else
SQUIRRELDIR=    ${PREFIX}/squirrelmail
PLIST_SUB+=     SQUIRRELDIR=squirrelmail
SUB_LIST+=      SQUIRRELDIR=squirrelmail
.endif
.endif
PLIST_SUB+=     SQUIRREL_PLUGIN_NAME=${SQUIRREL_PLUGIN_NAME}

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

_SMSRCDIR?=	${SQUIRREL_PLUGIN_NAME}

do-install:
	${CP} -R ${WRKSRC}/${_SMSRCDIR} ${SQUIRRELDIR}/plugins/${SQUIRREL_PLUGIN_NAME}
	${FIND} ${SQUIRRELDIR}/plugins/${SQUIRREL_PLUGIN_NAME} \
		-type d -exec chmod 755 {} \;
	${FIND} ${SQUIRRELDIR}/plugins/${SQUIRREL_PLUGIN_NAME} \
		-type f -exec chmod 644 {} \;

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

.if exists(${FILESDIR}/pkg-message.in)
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""
.endif
