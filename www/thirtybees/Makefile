PORTNAME=	thirtybees
PORTVERSION=	1.7.0
CATEGORIES=	www finance
MASTER_SITES=	https://thirtybees.com/versions/
DISTNAME=	${PORTNAME}-v${PORTVERSION}-php8.3

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Mature e-commerce solution
WWW=		https://thirtybees.com

LICENSE_FILE=	${WRKSRC}/LICENSES

USES=		php:web zip
USE_PHP=	bcmath curl gd imap mbstring opcache pdo_mysql \
		soap xml zip
IGNORE_WITH_PHP=85 86

NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message
PLIST_SUB=	THIRTYBEES_USER=${THIRTYBEES_USER} \
		THIRTYBEES_GROUP=${THIRTYBEES_GROUP}

THIRTYBEES_USER?=	${WWWOWN}
THIRTYBEES_GROUP?=	${WWWGRP}

post-extract:
	@${RM} -r ${WRKSRC}/.github

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
