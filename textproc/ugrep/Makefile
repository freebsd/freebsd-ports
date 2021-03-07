# $FreeBSD$

PORTNAME=	ugrep
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.9
CATEGORIES=	textproc

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	NEW ultra fast grep with interactive query UI

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c++11-lang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	Genivia

OPTIONS_DEFINE=		COLOR HIDDEN LZ4 MMAP PAGER PCRE2 PRETTY
OPTIONS_DEFINE_aarch64=	NEON
OPTIONS_DEFINE_amd64=	AVX SSE2
OPTIONS_DEFAULT=	COLOR HIDDEN LZ4 MMAP PAGER PCRE2 PRETTY
OPTIONS_DEFAULT_aarch64=	NEON
OPTIONS_DEFAULT_amd64=	AVX SSE2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost-regex

PCRE2_DESC=			Use Perl Compatible Regular Expressions v2
PCRE2_CONFIGURE_WITH=		pcre2=${LOCALBASE}
PCRE2_LIB_DEPENDS=		libboost_regex.so:devel/boost-libs \
				libpcre2-8.so:devel/pcre2
LZ4_CONFIGURE_WITH=		lz4=${LOCALBASE}
LZ4_LIB_DEPENDS=		liblz4.so:archivers/liblz4
NEON_DESC=			ARM NEON/AArch64 optimizations
NEON_CONFIGURE_ENABLE=		neon
AVX_CONFIGURE_ENABLE=		avx
AVX_DESC=			AVX optimizations
SSE2_CONFIGURE_ENABLE=		sse2
SSE2_DESC=			SSE2 optimizations
COLOR_DESC=			Colorized output by default
COLOR_CONFIGURE_ENABLE=		color
PRETTY_DESC=			Pretty output by default
PRETTY_CONFIGURE_ENABLE=	pretty
PAGER_DESC=			Pager enabled by default
PAGER_CONFIGURE_ENABLE=		pager
HIDDEN_DESC=			Search hidden files by default
HIDDEN_CONFIGURE_ENABLE=	hidden
MMAP_DESC=			Enable memory mapped files by default
MMAP_CONFIGURE_ENABLE=		mmap

.include <bsd.port.mk>
