# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	yourls
PORTVERSION=	1.7.1
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Your Own URL Shortener

LICENSE=	ISCL MIT
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tu}
GH_PROJECT=	${PORTNAME:tu}

NO_BUILD=	yes
NO_ARCH=	yes

USES=		cpe
USE_PHP=	bcmath curl json mysqli pcre xml

SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES+=	pkg-message
PLIST_SUB=	WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} "! -name \.*")

.include <bsd.port.mk>
