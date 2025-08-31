PORTNAME=	ffms2
DISTVERSION=	5.0
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	25cef14386fcaaa58ee547065deee8f6e82c56a2.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FFmpeg-based source library and VapourSynth plugin
WWW=		https://github.com/FFMS/ffms2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/vapoursynth/VSHelper.h:multimedia/vapoursynth
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USE_GITHUB=	yes
GH_ACCOUNT=	FFMS

USES=		autoreconf compiler:c++11-lib gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes

EXTRACT_AFTER_ARGS=	--exclude src/vapoursynth/V*.h \
			--no-same-owner --no-same-permissions

GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/lib/vapoursynth
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--enable-static

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^dist_doc_DATA/s,=,& \
	   doc/${PORTNAME}-vapoursynth.md,' \
	   ${WRKSRC}/Makefile.am

pre-configure:
	@${MKDIR} ${WRKSRC}/src/config # from autogen.sh

.include <bsd.port.mk>
