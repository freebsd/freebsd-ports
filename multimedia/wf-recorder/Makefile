# $FreeBSD$

PORTNAME=	wf-recorder
DISTVERSION=	0.2
CATEGORIES=	multimedia wayland
MASTER_SITES=	https://github.com/ammen99/wf-recorder/releases/download/v${DISTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Screen recorder for wlroots-based compositors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	scdoc:textproc/scdoc \
		wayland-protocols>=1.14:graphics/wayland-protocols \
		wayland-scanner:graphics/wayland
LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg \
		libpulse.so:audio/pulseaudio \
		libwayland-client.so:graphics/wayland

USES=		compiler:c++11-lang meson pkgconfig tar:xz

PLIST_FILES=	bin/wf-recorder \
		man/man1/wf-recorder.1.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS OPENCL
OPTIONS_DEFAULT=	OPENCL

OPENCL_DESC=	RGB to YUV conversion with the help of OpenCL

OPENCL_BUILD_DEPENDS=	opencl>0:devel/opencl
OPENCL_LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
OPENCL_MESON_ENABLED=	opencl

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
