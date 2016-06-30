# Created by: gahr
# $FreeBSD$

PORTNAME=	zorba
PORTVERSION=	2.7.0
PORTREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	https://launchpadlibrarian.net/119058962/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose C++ XQuery processor

LICENSE=	APACHE20

LIB_DEPENDS=	libxerces-c.so:textproc/xerces-c3 \
		libicudata.so:devel/icu \
		libcurl.so:ftp/curl \
		libtidy.so:www/tidy-lib \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	fop:textproc/fop

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	PHP PYTHON RUBY JAVA DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS+=	doxygen:devel/doxygen
PHP_CMAKE_BOOL=		WITH_PHP5
PYTHON_CMAKE_BOOL=	WITH_PYTHON
RUBY_CMAKE_BOOL=	WITH_RUBY
JAVA_CMAKE_BOOL=	WITH_JAVA

# Both install include/xqc.h
CONFLICTS=	xqilla-[0-9]*

USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes
USE_CXXSTD=	c++11
USES=		cmake:outsource compiler:c++11-lib execinfo
CXXFLAGS+=	-I${LOCALBASE}/include -O1 # compiler hangs with -O2 on CURRENT
LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS=	-DCMAKE_REQUIRED_FLAGS:STRING="-I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		-DLOCALBASE:STRING=${LOCALBASE} \
		-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

PLIST_SUB+=	FULLVERSION=${PORTVERSION} \
		MIDVERSION=${PORTVERSION:R} \
		MINVERSION=${PORTVERSION:R:R}

.if exists(/usr/lib/libexecinfo.so)
LOC_EXECINFO=	/usr/lib/libexecinfo.so
.else
LOC_EXECINFO=	${LOCALBASE}/lib/libexecinfo.so
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPHP}
USE_PHP=	tokenizer
USES+=		php:build
WITH_SWIG=	yes
CMAKE_ARGS+=	-DPHP5_INSTALL_PATH:FILEPATH="lib/php/${PHP_EXT_DIR}"
PLIST_SUB+=	PHP_EXTLIBDIR="lib/php/${PHP_EXT_DIR}"
.endif

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python
WITH_SWIG=	yes
CMAKE_ARGS+=	-DPYTHON_SWIG_INSTALL_DIR:FILEPATH=${PYTHONPREFIX_SITELIBDIR:S/${PREFIX}\///}
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR:S/${PREFIX}\///}
.endif

.if ${PORT_OPTIONS:MRUBY}
USE_RUBY=	yes
WITH_SWIG=	yes
.endif

.if ${PORT_OPTIONS:MJAVA}
USE_JAVA=	yes
CONFIGURE_ENV+=	JAVA_HOME=${JAVA_HOME}
CATEGORIES+=	java
WITH_SWIG=	yes
CMAKE_ARGS+=	-DJAVA_LIBDIR:PATH=${JAVALIBDIR}
.endif

.if defined(WITH_SWIG)
BUILD_DEPENDS+=	swig2.0:devel/swig20
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%LIBEXECINFO%%|${LOC_EXECINFO}|' \
		-e 's|FreeBSD|${OPSYS}|g' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/cmake_modules/FindPHP5.cmake
.if !${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/ADD_SUBDIRECTORY(doc)/d' \
		${WRKSRC}/CMakeLists.txt
.endif

post-install:
	${LN} -sf libzorba_simplestore.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libzorba_simplestore.so.${PORTVERSION:R:R}

test:	build
	cd ${BUILD_WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
