PORTNAME=	netcdf-fortran
PORTVERSION=	4.6.0
CATEGORIES=	science
MASTER_SITES=	https://downloads.unidata.ucar.edu/netcdf-fortran/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fortran library for machine-independent, array-oriented data access
WWW=		https://www.unidata.ucar.edu/software/netcdf/ \
		https://github.com/Unidata/netcdf-fortran

LICENSE=	UCAR_UNIDATA
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_NAME=	University Corporation for Atmospheric Research/Unidata
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	netcdf>=4.9.0:science/netcdf
LIB_DEPENDS=	libnetcdf.so:science/netcdf

USES=		fortran gmake libtool localbase makeinfo pathfix

CPPFLAGS+=	-fPIC -DPIC -DgFortran
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_ENV=	MAKEINFOFLAGS=--no-split
MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	check
USE_LDCONFIG=	yes

.include <bsd.port.mk>
