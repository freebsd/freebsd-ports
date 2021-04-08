# $FreeBSD: head/www/element-web/Makefile 564765 2021-02-09 05:54:55Z ashish $

PORTNAME=	element
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.24
CATEGORIES=	www
MASTER_SITES=	https://github.com/vector-im/element-web/releases/download/${DISTVERSIONFULL}/
PKGNAMESUFFIX=	-web

MAINTAINER=	ports@xanderio.de
COMMENT=	Glossy Matrix collaboration client for the web

LICENSE=	APACHE20

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
