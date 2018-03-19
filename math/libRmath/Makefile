# Created by: Eric van Gyzen <vangyzen@stat.duke.edu>
# $FreeBSD$

PORTNAME=	libRmath
DISTVERSION=	3.4.4
CATEGORIES=	math lang
MASTER_SITES=	CRAN/src/base/R-${PORTVERSION:C|\..*||}
DISTNAME=	R-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Standalone math library from R

LICENSE=	GPLv2

BROKEN_FreeBSD_10_armv6=	Fails to build
ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre.so:devel/pcre

BUILD_WRKSRC=	${WRKSRC}/src/nmath/standalone
CONFIGURE_ARGS=	--disable-nls --with-ICU=no --with-cairo=no \
		--with-jpeglib=no --with-libpng=no --with-libtiff=no \
		--with-readline=no --with-tcltk=no --with-x=no \
		--without-libintl-prefix
CONFIGURE_ENV+=	ac_cv_header_iconv_h=no FPICFLAGS=-fPIC
GNU_CONFIGURE=	yes
RMATH_SOVERSION=${PORTVERSION:R}
USES=		localbase
USE_LDCONFIG=	yes

PLIST_SUB=	RMATH_SOVERSION="${RMATH_SOVERSION}"

OPTIONS_DEFINE=		FLANG
OPTIONS_EXCLUDE_aarch64=	FLANG
OPTIONS_EXCLUDE_armv6=	FLANG
OPTIONS_EXCLUDE_armv7=	FLANG
OPTIONS_EXCLUDE_i386=	FLANG

FLANG_DESC=		Use experimental flang instead of default Fortran compiler
FLANG_USES=		fortran:flang
FLANG_USES_OFF=		fortran

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
	(cd ${STAGEDIR}${PREFIX}/lib; ${LN} -sf libRmath.so libRmath.so.${RMATH_SOVERSION})

.include <bsd.port.mk>
