PORTNAME=	ugrep
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.6
CATEGORIES=	textproc

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	NEW ultra fast grep with interactive query UI
WWW=		https://ugrep.com

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c++11-lang gmake shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	Genivia

OPTIONS_DEFINE=		COLOR HIDDEN LZ4 MMAP PAGER PCRE2 PRETTY ZSTD BROTLI BZIP3
OPTIONS_DEFINE_aarch64=	NEON
OPTIONS_DEFINE_amd64=	AVX SSE2
OPTIONS_DEFAULT=	COLOR HIDDEN LZ4 MMAP PAGER PCRE2 PRETTY ZSTD BROTLI BZIP3
OPTIONS_DEFAULT_aarch64=	NEON
OPTIONS_DEFAULT_amd64=	AVX SSE2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost-regex

SHEBANG_FILES=	bin/ug+ bin/ugrep+
bash_CMD=	${SH}

PCRE2_DESC=			Use Perl Compatible Regular Expressions v2
PCRE2_CONFIGURE_WITH=		pcre2=${LOCALBASE}
PCRE2_LIB_DEPENDS=		libboost_regex.so:devel/boost-libs \
				libpcre2-8.so:devel/pcre2
LZ4_CONFIGURE_WITH=		lz4=${LOCALBASE}
LZ4_LIB_DEPENDS=		liblz4.so:archivers/liblz4
NEON_DESC=			ARM NEON/AArch64 optimizations
NEON_CONFIGURE_OFF=		--disable-neon
AVX_CONFIGURE_OFF=		--disable-avx
AVX_DESC=			AVX optimizations
SSE2_CONFIGURE_OFF=		--disable-sse2
SSE2_DESC=			SSE2 optimizations
COLOR_DESC=			Colorized output by default
COLOR_CONFIGURE_OFF=		--disable-auto-color
PRETTY_DESC=			Pretty output by default
PRETTY_CONFIGURE_ENABLE=	pretty
PAGER_DESC=			Pager enabled by default
PAGER_CONFIGURE_ENABLE=		pager
HIDDEN_DESC=			Search hidden files by default
HIDDEN_CONFIGURE_ENABLE=	hidden
MMAP_DESC=			Enable memory mapped files by default
MMAP_CONFIGURE_ENABLE=		mmap
ZSTD_CONFIGURE_WITH=		zstd=${LOCALBASE}
ZSTD_LIB_DEPENDS=		libzstd.so:archivers/zstd
BROTLI_CONFIGURE_WITH=		brotli=${LOCALBASE}
BROTLI_LIB_DEPENDS=		libbrotlidec.so:archivers/brotli
BZIP3_DESC=			bzip3 compression support
BZIP3_CONFIGURE_WITH=		bzip3=${LOCALBASE}
BZIP3_LIB_DEPENDS=		libbzip3.so:archivers/bzip3

.include <bsd.port.mk>
