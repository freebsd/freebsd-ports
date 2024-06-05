PORTNAME=	element
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.68
CATEGORIES=	www
MASTER_SITES=	https://github.com/element-hq/element-web/releases/download/${DISTVERSIONFULL}/
PKGNAMESUFFIX=	-web

MAINTAINER=	ports@xanderio.de
COMMENT=	Glossy Matrix collaboration client for the web
WWW=		https://element.io

LICENSE=	APACHE20

USES=		cpe

CPE_VENDOR=	matrix

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
PLIST_SUB=	COMMITID=c73469086a55f7f61043

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
