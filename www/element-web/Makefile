PORTNAME=	element
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.16
CATEGORIES=	www
MASTER_SITES=	https://github.com/vector-im/element-web/releases/download/${DISTVERSIONFULL}/
PKGNAMESUFFIX=	-web

MAINTAINER=	ports@xanderio.de
COMMENT=	Glossy Matrix collaboration client for the web
WWW=		https://github.com/vector-im/element-web

LICENSE=	APACHE20

USES=		cpe

CPE_VENDOR=	matrix

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
PLIST_SUB=	COMMITID=91088212bc241f36c0c9

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
