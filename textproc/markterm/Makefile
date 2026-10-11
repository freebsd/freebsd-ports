PORTNAME=	markterm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0
CATEGORIES=	textproc

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Render Markdown to the terminal, to Markdown, or to PDF
WWW=		https://github.com/ralsina/markterm

# GPLv3 is added by the TEXMATH option (libtexprintf)
LICENSE=	MIT
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	crystal:lang/crystal \
		git:devel/git \
		shards:devel/shards
LIB_DEPENDS=	libgc-threaded.so:devel/boehm-gc-threaded \
		libpcre2-8.so:devel/pcre2 \
		libpng.so:graphics/png \
		libyaml.so:textproc/libyaml

# cmake:indirect only pulls in cmake: ext/build-libharu.sh drives it
# itself (gmake is picked up as its make program). C++17 is needed
# by the vendored litehtml.
USES=		cmake:indirect compiler:c++17-lang gmake gnome pkgconfig \
		readline ssl
USE_GITHUB=	yes
GH_ACCOUNT=	ralsina
# Crystal shards, pinned to what upstream's shard.lock resolves to.
# Directory names must match the repository name: post-extract
# rewrites `github: owner/repo` into `path: deps/repo`.
GH_TUPLE=	ralsina:markd:490f0bc3129d1e625464b3f4da7336a2a978cffe:markd/deps/markd \
		ralsina:docopt.cr:v0.3.1:docopt/deps/docopt.cr \
		ralsina:docopt-config:v0.3.0:docopt_config/deps/docopt-config \
		ralsina:tartrazine:v0.22.0:tartrazine/deps/tartrazine \
		ralsina:sixteen:v0.9.0:sixteen/deps/sixteen \
		ralsina:baked_file_system:beb373124c7a235cfb9cd94e36849d8168eaa04b:baked_file_system/deps/baked_file_system \
		hutou:tablo:v1.1.0:tablo/deps/tablo \
		crystal-term:color:v1.0.0:term_color/deps/color \
		crystal-term:screen:v1.0.0:term_screen/deps/screen \
		crystal-china:base58.cr:0e2c44d16a8098b00d8bf0b74add8bb9ea2f1c5f:base58/deps/base58.cr \
		naqvis:crimage:7d3244a3850646e3d398cef071f7c3e3f52c7518:crimage/deps/crimage \
		naqvis:uni_text_seg:v0.1.3:textseg/deps/uni_text_seg \
		naqvis:uni_char_width:v0.1.3:uniwidth/deps/uni_char_width \
		kemalcr:kemal:v1.13.0:kemal/deps/kemal \
		luislavena:radix:v0.4.1:radix/deps/radix \
		crystal-loot:exception_page:v0.5.0:exception_page/deps/exception_page \
		Sija:backtracer.cr:v1.2.4:backtracer/deps/backtracer.cr
# C/C++ sources for the litepdf shim: git submodules plus libharu,
# which ext/build-libharu.sh builds from source with the CID font
# patch (print/libharu ships unpatched, so it cannot be used).
GH_TUPLE+=	ralsina:litehtml:bf76f100647e19d1938047d23f7258281586e87b:litehtml/ext/litehtml \
		libharu:libharu:v2.4.6:libharu/ext/build/libharu
USE_GNOME=	libxml2

PLIST_FILES=	bin/markmark \
		bin/markpdf \
		bin/markterm

PORTDOCS=	BUILDING.md CHANGELOG.md README.md

OPTIONS_DEFINE=		DOCS TEXMATH
OPTIONS_DEFAULT=	DOCS TEXMATH

TEXMATH_DESC=		Render LaTeX math as Unicode text art via libtexprintf (GPLv3)
TEXMATH_GH_TUPLE=	bartp5:libtexprintf:18977837b20649d56a651eb6bf846f1c914db77a:texprintf/ext/libtexprintf
TEXMATH_VARS=		_WITH_TEXMATH=1 \
			LICENSE+=GPLv3
TEXMATH_VARS_OFF=	_WITH_TEXMATH=0

SHARDS_ENV=	--time --verbose --production --release --no-color --stats

post-extract:
# force shards to use local paths, not git repos, for dependencies
	@${RM} ${WRKSRC}/shard.lock
	@${REINPLACE_CMD} -E \
		-e 's,github: .*/,path: deps/,' \
		-e '/^[[:space:]]*(branch|commit|tag):/d' \
		-e '/^scripts:[[:space:]]*$$/d' \
		-e '/^[[:space:]]+postinstall:/d' \
		${WRKSRC}/shard.yml \
		${WRKSRC}/deps/*/shard.yml

do-build:
# the litepdf static library (litehtml + libharu + optional libtexprintf);
# -MMD/-MP are left out of the flags so cmake does not see them
	(cd ${WRKSRC}/ext && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		CC="${CC}" CXX="${CXX}" AR="${AR}" \
		CFLAGS="${CFLAGS} -fPIC" \
		CXXFLAGS="${CXXFLAGS} -std=c++17 -fPIC" \
		WITH_TEXMATH=${_WITH_TEXMATH})
# the Crystal binaries; markpdf-web (a Kemal playground) is left out
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/shards lock ${SHARDS_ENV} && \
		${SETENV} ${MAKE_ENV} WITH_TEXMATH=${_WITH_TEXMATH} \
		${LOCALBASE}/bin/shards build ${SHARDS_ENV} \
		markterm markmark markpdf)

do-install:
.for f in markterm markmark markpdf
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
