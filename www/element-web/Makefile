PORTNAME=	element
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.25
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
PLIST_SUB=	COMMITID=4ac3cb7a9dd861e34551

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
