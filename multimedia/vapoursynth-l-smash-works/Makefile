PORTNAME=	l-smash-works
DISTVERSION=	20230716
PORTREVISION=	1
CATEGORIES=	multimedia
PKGNAMEPREFIX=	vapoursynth-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	L-SMASH source plugin for VapourSynth
WWW=		https://github.com/HomeOfAviSynthPlusEvolution/L-SMASH-Works

BROKEN=		Does not build with ffmpeg > 6

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
USE_LDFLAGS=	yes

EXCLUDE=	VSHelper.h VSScript.h VapourSynth.h
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude ,}

WRKSRC_SUBDIR=	VapourSynth

PLIST_FILES=	lib/vapoursynth/libvslsmashsource.so

CFLAGS_powerpc64le=	-DNO_WARN_X86_INTRINSICS

post-patch:
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|g' \
		${PATCH_WRKSRC}/meson.build
	@${REINPLACE_CMD} -e 's|LSMASHSource.dll|libvslsmashsource.so|g' \
		${PATCH_WRKSRC}/README

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
