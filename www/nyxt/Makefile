PORTNAME=	nyxt
DISTVERSION=	3.12.0
DISTVERSIONSUFFIX=	-source-with-submodules
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	https://github.com/atlas-engineer/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Keyboard-driven web browser which uses WebKitGTK backend
WWW=		https://nyxt.atlas.engineer/

LICENSE=	BSD3CLAUSE CC-BY-SA-3.0
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/licenses/SOURCE-LICENSE
LICENSE_FILE_CC-BY-SA-3.0=	${WRKSRC}/licenses/ASSET-LICENSE

BUILD_DEPENDS=	git>0:devel/git \
		sbcl>0:lang/sbcl
LIB_DEPENDS=	libfixposix.so:devel/libfixposix \
		libwebkit2gtk-4.1.so:www/webkit2-gtk@41 \
		libzstd.so:archivers/zstd

USES=		desktop-file-utils gmake pkgconfig tar:xz

MAKEFILE=	makefile
WRKSRC=		${WRKDIR}

OPTIONS_DEFINE=		GSTREAMER
OPTIONS_DEFAULT=	GSTREAMER

GSTREAMER_USES=	gstreamer
GSTREAMER_USE=	GSTREAMER=bad,good,libav

.include <bsd.port.mk>
