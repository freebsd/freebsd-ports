# New ports collection makefile for:	silo
# Date created:		17 jul 2008
# Whom: 		Pedro F. Giffuni <giffunip@tutopia.com>
#
# $FreeBSD$
#

PORTNAME=	silo
PORTVERSION=	4.6.2
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	https://wci.llnl.gov/codes/${PORTNAME}/silo-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mesh and field I/O library and scientific database

LIB_DEPENDS=	netcdf.4:${PORTSDIR}/science/netcdf

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"

NO_LATEST_LINK=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-shared
USE_LDCONFIG=	yes

USE_XLIB=	yes
USE_QT_VER=	3
QT_COMPONENTS=	moc uic

.ifdef WITH_PYTHON
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--enable-pythonmodule
PLIST_SUB+=	WITH_PYTHON=""
.else
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

.ifdef WITH_HDF5
USE_FORTRAN=	yes
CONFIGURE_ENV+=	${MAKE_ENV}
CONFIGURE_ARGS+=	--enable-fortran
.else
CONFIGURE_ARGS+=	--disable-fortran
.endif

.ifdef WITH_HDF5
LIB_DEPENDS+=	hdf5.0:${PORTSDIR}/science/hdf5
CONFIGURE_ARGS=	--with-hdf5=${LOCALBASE}/include,${LOCALBASE}/lib
PLIST_SUB+=	WITH_HDF5=""
PLIST_SUB+=	WITH_NCDF="@comment "
LIBSILO=	libsiloh5
.else
PLIST_SUB+=	WITH_HDF5="@comment "
PLIST_SUB+=	WITH_NCDF=""
LIBSILO=	libsilo
.endif

.ifdef WITH_OPTIMIZATION
CONFIGURE_ARGS+=	--enable-optimization
.endif

post-install:
	@${RM} ${PREFIX}/lib/libsilo*.settings
	@${MV} ${PREFIX}/lib/${LIBSILO}.so ${PREFIX}/lib/${LIBSILO}.so.4
	@${LN} -sf ${PREFIX}/lib/${LIBSILO}.so.4 ${PREFIX}/lib/${LIBSILO}.so

.ifdef MAINTAINER_MODE
regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} check
.endif

.include <bsd.port.mk>
