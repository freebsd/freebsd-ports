PORTNAME=	libRmath
DISTVERSION=	4.5.1
CATEGORIES=	math lang
MASTER_SITES=	CRAN/src/base/R-${DISTVERSION:C|\..*||}
DISTNAME=	R-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Standalone math library from R
WWW=		https://www.R-project.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc64 powerpc64le

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre2-8.so:devel/pcre2

USES=		cpe fortran localbase pathfix
CPE_VENDOR=	r-project
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls \
		--with-cairo=no \
		--with-ICU=no \
		--with-jpeglib=no \
		--with-libpng=no \
		--with-libtiff=no \
		--with-readline=no \
		--with-tcltk=no \
		--with-x=no \
		--without-libintl-prefix
CONFIGURE_ENV+=	ac_cv_header_iconv_h=no \
		FPICFLAGS=-fPIC

BUILD_WRKSRC=	${WRKSRC}/src/nmath/standalone

PLIST_SUB=	RMATH_SOVERSION="${_RMATH_SOVERSION}"

_RMATH_SOVERSION=	${DISTVERSION:R}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/include/Rmath.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${BUILD_WRKSRC}/libRmath.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${BUILD_WRKSRC}/libRmath.so ${STAGEDIR}${PREFIX}/lib
	(cd ${STAGEDIR}${PREFIX}/lib; ${LN} -sf libRmath.so libRmath.so.${_RMATH_SOVERSION})

.include <bsd.port.mk>
