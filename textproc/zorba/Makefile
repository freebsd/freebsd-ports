# New ports collection Makefile for:	zorba
# Date created:				22 February 2011
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	zorba
PORTVERSION=	2.0.2
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A general purpose C++ XQuery processor

LICENSE=	AL2

LIB_DEPENDS=	xerces-c.3:${PORTSDIR}/textproc/xerces-c3 \
   		tidy:${PORTSDIR}/www/tidy-lib \
		curl.6:${PORTSDIR}/ftp/curl \
		icudata.48:${PORTSDIR}/devel/icu

OPTIONS=	PHP    "PHP bindings" off \
		PYTHON "Python bindings" off \
		RUBY   "Ruby bindings" off \
		JAVA   "Java bindings" off

# Both install include/xqc.h
CONFLICTS=	xqilla-[0-9]*

USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_CMAKE=	yes
CMAKE_OUTSOURCE=yes
CONFIGURE_ENV+=	JAVA_HOME=${JAVA_HOME}

DOCSDIR=	${PREFIX}/share/doc/${PKGNAME}
DATADIR=	${PREFIX}/share/${PKGNAME}

.include <bsd.port.options.mk>

.if defined(WITH_PHP)
USE_PHP=	tokenizer
USE_PHP_BUILD=	yes
WITH_SWIG=	yes
CMAKE_ARGS+=	-DWITH_PHP5:BOOL=true \
   		-DPHP5_INSTALL_PATH:FILEPATH="lib/php/${PHP_EXT_DIR}"
PLIST_SUB+=	WITH_PHP="" \
		PHP_EXTLIBDIR="lib/php/${PHP_EXT_DIR}"
.else
CMAKE_ARGS+=	-DWITH_PHP5:BOOL=false
PLIST_SUB+=	WITH_PHP="@comment "
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
WITH_SWIG=	yes
CMAKE_ARGS+=	-DWITH_PYTHON:BOOL=true \
		-DPYTHON_SWIG_INSTALL_DIR:FILEPATH=${PYTHONPREFIX_SITELIBDIR:S/${PREFIX}\///}
PLIST_SUB+=	WITH_PYTHON="" \
		PYTHON_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR:S/${PREFIX}\///}

.else
CMAKE_ARGS+=	-DWITH_PYTHON:BOOL=false
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

.if defined(WITH_RUBY)
USE_RUBY=	yes
WITH_SWIG=	yes
CMAKE_ARGS+=	-DWITH_RUBY:BOOL=true
PLIST_SUB+=	WITH_RUBY=""
.else
CMAKE_ARGS+=	-DWITH_RUBY:BOOL=false
PLIST_SUB+=	WITH_RUBY="@comment "
.endif

.if defined(WITH_JAVA)
USE_JAVA=	yes
WITH_SWIG=	yes
CMAKE_ARGS+=	-DWITH_JAVA:BOOL=true \
   		-DJAVA_LIBDIR:PATH=${JAVALIBDIR:S/${PREFIX}//}
PLIST_SUB+=	WITH_JAVA=""
.else
CMAKE_ARGS+=	-DWITH_JAVA:BOOL=false
PLIST_SUB+=	WITH_JAVA="@comment "
.endif

.if defined(WITH_SWIG)
BUILD_DEPENDS+=	swig:${PORTSDIR}/devel/swig13
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	   ${WRKSRC}/cmake_modules/FindPHP5.cmake
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '481s|^|#|' ${WRKSRC}/CMakeLists.txt
.endif

pre-build:
	${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
