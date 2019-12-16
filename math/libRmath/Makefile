# Created by: Eric van Gyzen <vangyzen@stat.duke.edu>
# $FreeBSD$

PORTNAME=	libRmath
DISTVERSION=	3.6.2
CATEGORIES=	math lang
MASTER_SITES=	CRAN/src/base/R-${PORTVERSION:C|\..*||}
DISTNAME=	R-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Standalone math library from R

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc64

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre.so:devel/pcre

USES=		localbase
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

OPTIONS_DEFINE=			FLANG
OPTIONS_EXCLUDE_aarch64=	FLANG
OPTIONS_EXCLUDE_armv6=		FLANG
OPTIONS_EXCLUDE_armv7=		FLANG
OPTIONS_EXCLUDE_i386=		FLANG

FLANG_DESC=	Use experimental flang instead of default Fortran compiler
FLANG_USES_OFF=	fortran
FLANG_USES=	fortran:flang

_RMATH_SOVERSION=	${DISTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g'\
		${WRKSRC}/src/nmath/standalone/Makefile.in \
		${WRKSRC}/src/unix/Makefile.in
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" \
		${WRKSRC}/configure

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/include/Rmath.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${BUILD_WRKSRC}/libRmath.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${BUILD_WRKSRC}/libRmath.so ${STAGEDIR}${PREFIX}/lib/libRmath.so
	(cd ${STAGEDIR}${PREFIX}/lib; ${LN} -sf libRmath.so libRmath.so.${_RMATH_SOVERSION})

.include <bsd.port.mk>
