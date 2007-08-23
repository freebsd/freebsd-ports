# New ports collection makefile for:	squirrelmail-compatibility-plugin
# Date created:				3 Jul 2005
# Whom:					Alexander Wittig <alexander@wittig.name>
#
# $FreeBSD$

PORTNAME=	compatibility
PORTVERSION=	2.0.8
CATEGORIES=	mail www
MASTER_SITES=	http://www.squirrelmail.org/plugins/
PKGNAMEPREFIX=	squirrelmail-
PKGNAMESUFFIX=	-plugin
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.0
DIST_SUBDIR=	squirrelmail

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Required by many plugins for compatibility with SquirrelMail

RUN_DEPENDS=	squirrelmail>=1.4.10:${PORTSDIR}/mail/squirrelmail

CONFLICTS=	squirrelmail-compatibility-plugin-1.*

SQUIRREL_PLUGIN_NAME=	${PORTNAME}

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

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PERL5_BUILD=	yes
WANT_PHP_WEB=	yes

.include <bsd.port.pre.mk>

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
	@${ECHO} "Patching SquirrelMail for compatibility plugin"
	@${ECHO} ""
	${PATCH} -sN -p0 -d ${SQUIRRELDIR}/plugins/compatibility < ${SQUIRRELDIR}/plugins/compatibility/patches/compatibility_patch-1.4.10.diff
	@${ECHO} ""

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
