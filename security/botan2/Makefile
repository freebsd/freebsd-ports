PORTNAME=	botan
DISTVERSION=	2.19.5
CATEGORIES=	security
MASTER_SITES=	http://botan.randombit.net/releases/
PKGNAMESUFFIX=	2
DISTNAME=	Botan-${PORTVERSION}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Portable, easy to use and efficient C++ crypto library
WWW=		https://botan.randombit.net/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BROKEN_armv6=	include/arm_neon.h:28:2: error: "NEON support not enabled"

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs

USES=		compiler:c++17-lang cpe gmake shebangfix tar:xz
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes

SHEBANG_FILES=	configure.py src/python/botan2.py src/scripts/install.py

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure.py
CONFIGURE_ARGS=		--cc=${CHOSEN_COMPILER_TYPE} \
			--prefix=${PREFIX:Q} \
			--with-boost \
			--with-bzip2 \
			--with-external-includedir=${LOCALBASE}/include \
			--with-external-libdir=${LOCALBASE}/lib \
			--with-lzma \
			--with-zlib
LDFLAGS+=		-pthread

DOCSDIR=	${LOCALBASE}/share/doc/${PORTNAME}-${PORTVERSION}

_SOABIVER=	19
_SHLIBVER=	${DISTVERSION:S/./ /g:[2]}
_SHLIBVERPATCH=	${DISTVERSION:S/./ /g:[3]}
PLIST_SUB=	SHLIBVER=${_SHLIBVER} \
		SHLIBVERPATCH=${_SHLIBVERPATCH} \
		SOABIVER=${_SOABIVER}
PORTDOCS=	*

OPTIONS_DEFINE=			DOCS MANPAGES PYTHON SQLITE3
OPTIONS_DEFINE_aarch64=		OPENMP
OPTIONS_DEFINE_amd64=		OPENMP
OPTIONS_DEFINE_i386=		OPENMP
OPTIONS_DEFINE_powerpc64=	OPENMP
OPTIONS_DEFINE_powerpc64le=	OPENMP
OPTIONS_DEFINE_riscv64=		OPENMP
OPTIONS_DEFAULT=		MANPAGES
OPTIONS_DEFAULT_aarch64=	OPENMP
OPTIONS_DEFAULT_amd64=		OPENMP
OPTIONS_DEFAULT_powerpc64=	OPENMP
OPTIONS_DEFAULT_powerpc64le=	OPENMP
OPTIONS_DEFAULT_riscv64=	OPENMP
OPTIONS_SUB=			yes

MANPAGES_BUILD_DEPENDS=		${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR}
MANPAGES_CONFIGURE_WITH=	sphinx

OPENMP_CONFIGURE_ON=	--with-openmp

PYTHON_USES=		python
PYTHON_USES_OFF=	python:build
PYTHON_CONFIGURE_ON=	--with-python-versions=${PYTHON_VER}
PYTHON_CONFIGURE_OFF=	--no-install-python-module

SQLITE3_USES=		sqlite
SQLITE3_CONFIGURE_WITH=	sqlite3

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64
CONFIGURE_ARGS+=	--cc-abi="-march=armv8-a+crypto"
.elif ${ARCH} == powerpc64
CONFIGURE_ARGS+=	--cpu="ppc64"
.if !defined(MACHINE_CPU) || (defined(MACHINE_CPU) && !${MACHINE_ABI:Mvsx2})
CONFIGURE_ARGS+=	--disable-powercrypto
.endif
.elif ${ARCH} == powerpc64le
CONFIGURE_ARGS+=	--cpu="ppc64le"
.endif

.if ${ARCH} == i386 || ${ARCH} == amd64
PLIST_SUB+=	HAS_RDRAND_RNG=""
.else
PLIST_SUB+=	HAS_RDRAND_RNG="@comment "
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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/botan ${STAGEDIR}${PREFIX}/lib/libbotan-2.so.${_SOABIVER}.${_SHLIBVER}.${_SHLIBVERPATCH}

.include <bsd.port.mk>
