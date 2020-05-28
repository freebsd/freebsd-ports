# $FreeBSD$

PORTNAME=       thirtybees
PORTVERSION=    1.1.0
CATEGORIES=	www finance
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Mature e-commerce solution

LICENSE_FILE=	${WRKSRC}/LICENSES

USES=		php:web zip
USE_PHP=	bcmath curl gd imap json mbstring opcache openssl pdo_mysql \
		soap xml zip
NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message
PLIST_SUB=	THIRTYBEES_USER=${THIRTYBEES_USER} \
		THIRTYBEES_GROUP=${THIRTYBEES_GROUP}

THIRTYBEES_USER?=	${WWWOWN}
THIRTYBEES_GROUP?=	${WWWGRP}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
