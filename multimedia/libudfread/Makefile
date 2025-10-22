PORTNAME=	libudfread
DISTVERSION=	1.2.0
CATEGORIES=	multimedia
MASTER_SITES=	https://get.videolan.org/${PORTNAME}/ \
		https://download.videolan.org/pub/videolan/${PORTNAME}/

MAINTAINER=	yzrh@noema.org
COMMENT=	UDF reader for media players
WWW=		https://code.videolan.org/videolan/libudfread/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe meson tar:xz
CPE_VENDOR=	videolan
USE_LDCONFIG=	yes

MESON_ARGS=	-Ddefault_library=shared

.include <bsd.port.mk>
