# $FreeBSD$

PORTNAME=	l-smash-works
DISTVERSION=	0.0-935 # git rev-list --count HEAD
DISTVERSIONSUFFIX=	-g3edd194
PORTREVISION=	1
CATEGORIES=	multimedia
PKGNAMEPREFIX=	vapoursynth-

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	L-SMASH source plugin for VapourSynth

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/vapoursynth/VSHelper.h:multimedia/vapoursynth
BUILD_DEPENDS+=	ffmpeg>=3.2,1:multimedia/ffmpeg
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		liblsmash.so:multimedia/l-smash

USE_GITHUB=	yes
GH_ACCOUNT=	VFR-maniac
GH_PROJECT=	L-SMASH-Works

USES=		gmake pkgconfig shebangfix
EXCLUDE=	VSHelper.h VSScript.h VapourSynth.h
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude ,}
WRKSRC_SUBDIR=	VapourSynth
SHEBANG_FILES=	configure
bash_CMD=	${SH}
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	LD="${CC}" REV="${PORTVERSION:E}" \
		HASH="${DISTVERSIONSUFFIX:S/^-g//}"
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--extra-cflags="${CPPFLAGS} ${CFLAGS}" \
		--extra-ldflags="${LDFLAGS}" \
		--extra-libs="${LIBS}"
MAKEFILE=	GNUmakefile
MAKE_ARGS=	STRIP="${STRIP_CMD}"
CPPFLAGS+=	`pkg-config vapoursynth --cflags`
USE_LDCONFIG=	yes
DATADIR=	${PREFIX}/lib/vapoursynth
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
PLIST_FILES=	lib/libvslsmashsource.so.${PORTVERSION:E} \
		%%DATADIR%%/libvslsmashsource.so
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -Ee '/CROSS/!s/^(CC|LD|REV|HASH)=.*/: $${&}/' \
		-e 's/pushd/cd/; s/popd/cd -/' \
		-e 's/-Os //; /=.*-fexcess-precision/d' \
		${WRKSRC}/configure

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
