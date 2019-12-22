# $FreeBSD$

PORTNAME=	riot
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.6
CATEGORIES=	www
MASTER_SITES=	https://github.com/vector-im/riot-web/releases/download/${DISTVERSIONFULL}/
PKGNAMESUFFIX=	-web

MAINTAINER=	alex@xanderio.de
COMMENT=	Glossy Matrix collaboration client for the web

LICENSE=	APACHE20

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
