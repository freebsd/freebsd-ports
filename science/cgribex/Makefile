# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	cgribex
PORTVERSION=	1.9.4
CATEGORIES=	science
MASTER_SITES=	https://code.mpimet.mpg.de/attachments/download/21178/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight GRIBEX in C with portable Fortran interface

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool

CPPFLAGS+=	-DgFortran
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GRIB_API JASPER SZIP
OPTIONS_DEFAULT=JASPER SZIP

GRIB_API_CONFIGURE_WITH=grib_api=${LOCALBASE}
GRIB_API_LIB_DEPENDS=	libgrib_api.so:science/grib_api
JASPER_CONFIGURE_WITH=	jasper=${LOCALBASE}
JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
SZIP_CONFIGURE_WITH=	szlib=${LOCALBASE}
SZIP_LIB_DEPENDS=	libsz.so:science/szip

post-configure:
	@${REINPLACE_CMD} -e 's|-Ino/include||g; s|-Lno/lib||g' ${WRKSRC}/Makefile ${WRKSRC}/*/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcgribex.so

.include <bsd.port.mk>
