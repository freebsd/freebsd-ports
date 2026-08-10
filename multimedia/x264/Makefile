PORTNAME=	x264
DISTVERSION=	0.165.3223
CATEGORIES=	multimedia

MAINTAINER=	multimedia@FreeBSD.org
COMMENT?=	H.264/MPEG-4 AVC Video Encoding (CLI utility)
WWW=		https://www.videolan.org/x264.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS?=	libx264.so:multimedia/libx264

USES+=		meson pkgconfig python:build shebangfix
SHEBANG_GLOB=	*.py

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org/gstreamer
GL_ACCOUNT=	meson-ports
GL_PROJECT=	x264
GL_TAGNAME=	00852f599572d10798b2dafd2c5286213d0ce795

PLIST_FILES?=	bin/x264

OPTIONS_DEFINE+=	BASH FFMS LAVF SWSCALE
OPTIONS_DEFAULT+=	BASH FFMS LAVF LSMASH SWSCALE
OPTIONS_RADIO=		MP4
#OPTIONS_RADIO_MP4=	GPAC LSMASH
OPTIONS_RADIO_MP4=	LSMASH

FFMS_DESC=		FFmpeg Source input support
#GPAC_DESC=		GPAC library support
LAVF_DESC=		libav* format input support (requires FFmpeg)
LSMASH_DESC=		L-SMASH library support
MP4_DESC=		MPEG-4 output
SWSCALE_DESC=		Resize video filter

BASH_BUILD_DEPENDS=	bash-completion>0:shells/bash-completion
BASH_RUN_DEPENDS=	bash-completion>0:shells/bash-completion
BASH_PLIST_FILES=	share/bash-completion/completions/x264

FFMS_LIB_DEPENDS=	libffms2.so:multimedia/ffms2
FFMS_MESON_ENABLED=	ffms
FFMS_IMPLIES=		SWSCALE

#GPAC_LIB_DEPENDS=	libgpac.so:multimedia/gpac
#GPAC_USES=		localbase:ldflags
#GPAC_MESON_ENABLED=	gpac

LAVF_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg
LAVF_MESON_ENABLED=	lavf
LAVF_IMPLIES=		SWSCALE

LSMASH_LIB_DEPENDS=	liblsmash.so:multimedia/l-smash
LSMASH_MESON_ENABLED=	lsmash

SWSCALE_LIB_DEPENDS=	libswscale.so:multimedia/ffmpeg
SWSCALE_MESON_ENABLED=	swscale

.include <bsd.port.options.mk>

.if !defined(PKGNAMEPREFIX) || (${ARCH} != "aarch64" && ${ARCH} != "amd64" && empty(ARCH:Mpowerpc64*))
MESON_ARGS+=   -Dasm=disabled -Dvsx=disabled
.endif

.if defined(PKGNAMEPREFIX) && ${ARCH} == "powerpc64" && ${PORT_OPTIONS:MASM} && empty(MACHINE_CPU:Mvsx)
IGNORE=	ASM requires VSX on powerpc64; set CPUTYPE=power7 or newer, or disable the ASM option
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|g' \
	    ${PATCH_WRKSRC}/meson.build
	@${REINPLACE_CMD} -e 's|%%GIT_COMMIT_HASH%%|${GL_TAGNAME}|g' \
	    ${PATCH_WRKSRC}/meson.build

.if !defined(PKGNAMEPREFIX)
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${MESON_BUILD_DIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.endif

do-install-BASH-on:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/bash-autocomplete.sh ${STAGEDIR}${PREFIX}/share/bash-completion/completions/x264

.include <bsd.port.mk>
