# $FreeBSD$

PORTNAME=	moab
DISTVERSION=	4.6.3
CATEGORIES=	math
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/fathom/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Component for representing and evaluating mesh data

LICENSE=	BSD2CLAUSE
xLICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libnetcdf.so:science/netcdf

USES=		autoreconf gmake libtool localbase:ldflags
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --with-netcdf=${LOCALBASE}
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
