PORTNAME=	botan
DISTVERSION=	3.9.0
CATEGORIES=	security
MASTER_SITES=	http://botan.randombit.net/releases/
PKGNAMESUFFIX=	${_BOTANMAJOR}
DISTNAME=	Botan-${PORTVERSION}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Portable, easy to use and efficient C++ crypto library
WWW=		https://botan.randombit.net/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	${LOCALBASE}/include/boost/asio.hpp:devel/boost-libs

USES=		compiler:c++20-lang cpe gmake shebangfix tar:xz

CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure.py
CONFIGURE_ARGS=		--cc=${CHOSEN_COMPILER_TYPE} \
			${"${CCACHE_BIN}" != "":?--compiler-cache=${CCACHE_BIN}:} \
			--prefix=${PREFIX:Q} \
			--with-boost \
			--with-bzip2 \
			--with-external-includedir=${LOCALBASE}/include \
			--with-external-libdir=${LOCALBASE}/lib \
			--with-lzma \
			--with-zlib \
			--program-suffix=${_BOTANMAJOR}
TEST_TARGET=		check
LDFLAGS+=		-pthread

DOCSDIR=	${LOCALBASE}/share/doc/${PORTNAME}-${PORTVERSION}

_SOABIVER=	9
_BOTANMAJOR=	${DISTVERSION:S/./ /g:[1]}
_SHLIBVER=	${DISTVERSION:S/./ /g:[2]}
_SHLIBVERPATCH=	${DISTVERSION:S/./ /g:[3]}
PLIST_SUB=	SHLIBVER=${_SHLIBVER} \
		SHLIBVERPATCH=${_SHLIBVERPATCH} \
		SOABIVER=${_SOABIVER} \
		BOTANMAJOR=${_BOTANMAJOR}
PORTDOCS=	*

OPTIONS_DEFINE=			DOCS LLVM_FROM_PORTS MANPAGES PYTHON SQLITE3
OPTIONS_DEFAULT=		MANPAGES
OPTIONS_SUB=			yes

LLVM_FROM_PORTS_DESC=		Use LLVM from ports to build

MANPAGES_BUILD_DEPENDS=		${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}furo>=2022.6.21:textproc/py-furo@${PY_FLAVOR}
MANPAGES_CONFIGURE_WITH=	sphinx

PYTHON_USES=		python
PYTHON_USES_OFF=	python:build
PYTHON_CONFIGURE_ON=	--with-python-versions=${PYTHON_VER}
PYTHON_CONFIGURE_OFF=	--no-install-python-module

SQLITE3_USES=		sqlite
SQLITE3_CONFIGURE_WITH=	sqlite3

.include <bsd.port.options.mk>

# llvm from ports fixes build failure, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=279136
.if ${OPSYS} == FreeBSD && \
	((${OSVERSION} >= 1500000) || \
	${PORT_OPTIONS:MLLVM_FROM_PORTS})
USES+=	llvm
USES:=	${USES:Ncompiler\:*} # XXX avoid warnings
CHOSEN_COMPILER_TYPE=	clang
.endif

.if ${ARCH} == aarch64
CONFIGURE_ARGS+=	--cc-abi="-march=armv8-a+crypto"
.elif ${ARCH:Mpowerpc64*}
CONFIGURE_ARGS+=	--cpu="ppc64"
.if !defined(MACHINE_CPU) || (defined(MACHINE_CPU) && !${MACHINE_CPU:Mvsx2})
CONFIGURE_ARGS+=	--disable-modules=aes_power8,ghash_cpu
.endif
.endif

.if ${ARCH} == i386 || ${ARCH} == amd64 || ${ARCH:Mpowerpc64*}
PLIST_SUB+=	HAS_PROCESSOR_RNG=""
.else
PLIST_SUB+=	HAS_PROCESSOR_RNG="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^optimization_flags .*|optimization_flags "${CXXFLAGS}"|' \
		${WRKSRC}/src/build-data/cc/clang.txt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/botan${_BOTANMAJOR} ${STAGEDIR}${PREFIX}/lib/libbotan-${_BOTANMAJOR}.so.${_SOABIVER}.${_SHLIBVER}.${_SHLIBVERPATCH}

.include <bsd.port.mk>
