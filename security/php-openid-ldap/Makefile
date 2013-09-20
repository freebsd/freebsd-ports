# Created by: Matthew X. Economou <xenophon+freebsd@irtnog.org>
# $FreeBSD$

PORTNAME=	openid-ldap
PORTVERSION=	0.8.9
CATEGORIES=	security www
MASTER_SITES=	http://www.openid-ldap.org/releases/
PKGNAMEPREFIX=	php${PHP_VER}-
EXTRACT_SUFX=	-noarc.tar.gz

MAINTAINER=	xenophon+freebsd@irtnog.org
COMMENT=	PHP-based OpenID identity provider using LDAP as backend

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5
USE_PHP=	bcmath ldap session

PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-noarc
NO_BUILD=	yes
NO_INSTALL=	yes

SUB_FILES+=	pkg-message

PLIST_FILES=	%%WWWDIR%%/style.css \
		%%WWWDIR%%/images/openid-logo.gif \
		%%WWWDIR%%/images/openid.gif \
		%%WWWDIR%%/images/logo.gif \
		%%WWWDIR%%/images/openid.ico \
		%%WWWDIR%%/images/user.gif \
		%%WWWDIR%%/images/openid.png \
		%%WWWDIR%%/images/seatbelt/icon-high.png \
		%%WWWDIR%%/images/seatbelt/icon-gray.png \
		%%WWWDIR%%/images/seatbelt/icon-logo.png \
		%%WWWDIR%%/engine.php \
		%%WWWDIR%%/showme.php \
		%%WWWDIR%%/index.php \
		%%WWWDIR%%/ldap.php
PLIST_DIRS=	%%WWWDIR%%/images/seatbelt \
		%%WWWDIR%%/images \
		%%WWWDIR%%

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_FILES+=	%%DOCSDIR%%/INSTALL \
		%%DOCSDIR%%/FAQ \
		%%DOCSDIR%%/LICENSE \
		%%DOCSDIR%%/CHANGELOG \
		%%DOCSDIR%%/htaccess \
		%%DOCSDIR%%/README
PLIST_DIRS+=	%%DOCSDIR%%
.endif

post-install:
	${MKDIR} ${WWWDIR}
	(cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} "*.php *.css images" ${WWWDIR})
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	${CHMOD} o= ${WWWDIR}/ldap.php
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	(cd ${INSTALL_WRKSRC}/docs && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
