# New ports collection makefile for:	squirrelmail-newuser_wiz-plugin
# Date created:		2006-06-20
# Whom:			Thomas Abthorpe <thomas@goodking.ca>
#
# $FreeBSD$
#

PORTNAME=	newuser_wiz
PORTVERSION=	1.3.2
PORTREVISION=	4
CATEGORIES=	mail www
MASTER_SITES=	http://www.squirrelmail.org/plugins/
PKGNAMEPREFIX=	squirrelmail-
PKGNAMESUFFIX=	-plugin
DISTNAME=	${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	squirrelmail

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Force user to enter Full name and Email address at initial logon

RUN_DEPENDS=	${SQUIRRELDIR}/index.php:${PORTSDIR}/mail/squirrelmail \
		${SQUIRRELDIR}/plugins/compatibility:${PORTSDIR}/mail/squirrelmail-compatibility-plugin1

SQUIRREL_PLUGIN_NAME=	${PORTNAME}

DEPRECATED=		use mail/squirrelmail-askuserinfo-plugin
EXPIRATION_DATE=	2010-07-01

.ifdef SQUIRRELDIR
PLIST_SUB+=	SQUIRRELDIR=${SQUIRRELDIR}
SUB_LIST+=	"SQUIRRELDIR=${SQUIRRELDIR}"
.else
.ifndef WITHOUT_WWWDIR
SQUIRRELDIR=	${PREFIX}/www/squirrelmail
PLIST_SUB+=	SQUIRRELDIR=www/squirrelmail
SUB_LIST+=	"SQUIRRELDIR=www/squirrelmail"
.else
SQUIRRELDIR=	${PREFIX}/squirrelmail
PLIST_SUB+=	SQUIRRELDIR=squirrelmail
SUB_LIST+=	"SQUIRRELDIR=squirrelmail"
.endif
.endif
PLIST_SUB+=	SQUIRREL_PLUGIN_NAME=${SQUIRREL_PLUGIN_NAME}

NO_BUILD=		yes
NO_WRKSUBDIR=		yes
USE_PERL5_BUILD=	yes
USE_PHP=		yes
WANT_PHP_WEB=		yes

.include <bsd.port.pre.mk>

.if exists(${SQUIRRELDIR}/plugins/compatibility/getpot)
IGNORE='compatibility2 plugin is incompatible with this plugin, install mail/squirrelmail-compatibility-plugin1. WARNING compatibility-plugin1 could break other squirrelmail plugins'
.endif

pre-everything::
	@${ECHO} ""
.ifndef WITHOUT_ACTIVATE
	@${ECHO} "Activating plug-in in SquirrelMail after installation."
	@${ECHO} "If you don't want to automatically activate the plug-in set"
	@${ECHO} "WITHOUT_ACTIVATE=yes"
.else
	@${ECHO} "NOT Activating plug-in in SquirrelMail after installation."
	@${ECHO} "If you want to automatically activate the plug-in unset"
	@${ECHO} "WITHOUT_ACTIVATE"
.endif
	@${ECHO} ""

do-install:
	${CP} -rp ${WRKSRC}/${SQUIRREL_PLUGIN_NAME} ${SQUIRRELDIR}/plugins
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${SQUIRRELDIR}/plugins/${SQUIRREL_PLUGIN_NAME}

post-install:
.ifndef WITHOUT_ACTIVATE
.if exists( ${SQUIRRELDIR}/config/config.php )
	@${ECHO} "Activating plug-in in SquirrelMail"
	${SQUIRRELDIR}/config/conf.pl --install-plugin ${SQUIRREL_PLUGIN_NAME}
.endif
.else
	@${ECHO} "To activate the plug-in in SquirrelMail use"
	@${ECHO} "${SQUIRRELDIR}/config/conf.pl --install-plugin ${SQUIRREL_PLUGIN_NAME}"
.endif

.include <bsd.port.post.mk>
