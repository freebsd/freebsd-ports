PORTNAME=	netcdf-cxx
PORTVERSION=	4.3.1
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	https://downloads.unidata.ucar.edu/netcdf-cxx/${PORTVERSION}/ \
		LOCAL/sunpoet
DISTNAME=	${PORTNAME}4-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ library for machine-independent, array-oriented data access
WWW=		https://www.unidata.ucar.edu/software/netcdf/ \
		https://github.com/Unidata/netcdf-cxx4

LICENSE=	UCAR_UNIDATA
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_NAME=	University Corporation for Atmospheric Research/Unidata
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libnetcdf.so:science/netcdf

USES=		libtool localbase pathfix

CPPFLAGS+=	-fPIC -DPIC
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

.include <bsd.port.mk>
