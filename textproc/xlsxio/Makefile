PORTNAME=	xlsxio
PORTVERSION=	0.2.35
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/brechtsanders/xlsxio/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C library for reading and writing .xlsx files
WWW=		https://github.com/brechtsanders/xlsxio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libminizip.so:archivers/minizip

USES=		cmake pathfix tar:xz

CMAKE_OFF=	BUILD_DOCUMENTATION \
		BUILD_EXAMPLES \
		WITH_LIBZIP \
		WITH_MINIZIP_NG \
		WITH_WIDE
CMAKE_ON=	BUILD_PC_FILES \
		BUILD_SHARED \
		BUILD_STATIC \
		BUILD_TOOLS

.include <bsd.port.mk>
