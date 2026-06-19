PORTNAME=	l-smash-works
DISTVERSION=	20260326
CATEGORIES=	multimedia
PKGNAMEPREFIX=	vapoursynth-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	L-SMASH source plugin for VapourSynth
WWW=		https://github.com/HomeOfAviSynthPlusEvolution/L-SMASH-Works

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 powerpc64le

BUILD_DEPENDS=	${LOCALBASE}/include/vapoursynth/VSHelper.h:multimedia/vapoursynth
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		liblsmash.so:multimedia/l-smash

USES=		meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	HomeOfAviSynthPlusEvolution
GH_PROJECT=	L-SMASH-Works
GH_TAGNAME=	1282

EXTRACT_AFTER_ARGS= 	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/include/VSHelper.h \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/include/VapourSynth.h \
			--no-same-owner --no-same-permissions

WRKSRC_SUBDIR=	VapourSynth

CFLAGS_powerpc64le=	-DNO_WARN_X86_INTRINSICS

PLIST_FILES=	lib/vapoursynth/libvslsmashsource.so

post-patch:
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|g' \
		${PATCH_WRKSRC}/meson.build
	@${REINPLACE_CMD} -e 's|LSMASHSource.dll|libvslsmashsource.so|g' \
		${PATCH_WRKSRC}/README.md

post-install:
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
