# New ports collection makefile for:	silo
# Date created:		17 jul 2008
# Whom: 		Pedro F. Giffuni <giffunip@tutopia.com>
#
# $FreeBSD$
#

PORTNAME=	silo
PORTVERSION=	4.6.1
CATEGORIES=	science
MASTER_SITES=	https://wci.llnl.gov/codes/${PORTNAME}/silo-${PORTVERSION}/

MAINTAINER=	giffunip@tutopia.com
COMMENT=	A mesh and field I/O library and scientific database

LIB_DEPENDS=	netcdf.4:${PORTSDIR}/science/netcdf

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include"	\
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS} -L${LOCALBASE}/lib"

USE_GMAKE=	yes
CONFIGURE_ARGS= --enable-shared
USE_LDCONFIG=	yes

USE_XLIB=	yes
USE_QT_VER=	3
QT_COMPONENTS=	moc uic

OPTIONS=	PYTHON	"Enable Python Module" On \
		HDF5	"Enable HDF5 Driver" Off \
		BROWSER	"Enable Silex Browser" Off \
		FORTRAN "Compile Fortran interface" Off \
		OPTIMIZATION "Enable extra optimizations" On

.include <bsd.port.pre.mk>

.ifdef WITH_PYTHON
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--enable-pythonmodule
PLIST_SUB+=	WITH_PYTHON=""
.else
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

.ifdef WITH_HDF5
LIB_DEPENDS+=	hdf5.0:${PORTSDIR}/science/hdf5
CONFIGURE_ARGS= --with-hdf5=${LOCALBASE}
PLIST_SUB+=	WITH_HDF5=""
PLIST_SUB+=	WITH_HDF5="@comment "
.else
PLIST_SUB+=	WITH_HDF5="@comment "
PLIST_SUB+=	WITH_NCDF=""
.endif

.ifdef WITH_BROWSER
CONFIGURE_ARGS+=	--enable-silex
PLIST_SUB+=	WITH_BROWSER=""
.else
PLIST_SUB+=	WITH_BROWSER="@comment "
.endif

.ifdef WITH_FORTRAN
USE_FORTRAN=	yes
CONFIGURE_ARGS+=	--enable-fortran
.else
CONFIGURE_ARGS+=	--disable-fortran
.endif

.ifdef WITH_OPTIMIZATION
CONFIGURE_ARGS+=	--enable-optimization
.endif

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} check

.include <bsd.port.post.mk>
