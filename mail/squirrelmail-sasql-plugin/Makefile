# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	squirrelmail-${SQUIRREL_PLUGIN_NAME}-plugin
PORTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	http://www.squirrelmail.org/plugins/
DISTNAME=	${SQUIRREL_PLUGIN_NAME}-${PORTVERSION}
DIST_SUBDIR=	squirrelmail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Edit SpamAssassin settings stored in an SQL DB

RUN_DEPENDS=	${SQUIRRELDIR}/index.php:${PORTSDIR}/mail/squirrelmail \
		${SQUIRRELDIR}/plugins/compatibility:${PORTSDIR}/mail/squirrelmail-compatibility-plugin \
		${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB

SQUIRREL_PLUGIN_NAME=	sasql

.ifdef SQUIRRELDIR
PLIST_SUB+=	SQUIRRELDIR=${SQUIRRELDIR}
SUB_LIST+=	"SQUIRRELDIR=${SQUIRRELDIR}"
.else
.	ifndef WITHOUT_WWWDIR
SQUIRRELDIR=	${PREFIX}/www/squirrelmail
PLIST_SUB+=	SQUIRRELDIR=www/squirrelmail
SUB_LIST+=	"SQUIRRELDIR=www/squirrelmail"
.	else
SQUIRRELDIR=	${PREFIX}/squirrelmail
PLIST_SUB+=	SQUIRRELDIR=squirrelmail
SUB_LIST+=	"SQUIRRELDIR=squirrelmail"
.	endif
.endif

SUB_FILES=	pkg-message

USES=		perl5
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PERL5=	build
USE_PHP=	yes
WANT_PHP_WEB=	yes

NO_STAGE=	yes
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

post-patch:
	@${RM} ${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/*.orig ${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/.cvsignore

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
	@${ECHO} ""
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
