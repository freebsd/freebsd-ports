# Created by: Pedro F. Giffuni <giffunip@tutopia.com>
# $FreeBSD$

PORTNAME=	silo
PORTVERSION=	4.10.2
PORTREVISION=	1
DISTVERSIONSUFFIX=	-bsd
CATEGORIES=	science
MASTER_SITES=	http://wci.llnl.gov/content/assets/docs/simulation/computer-codes/${PORTNAME}/silo-${PORTVERSION}/

MAINTAINER=	dbaio@bsd.com.br
COMMENT=	Mesh and field I/O library and scientific database

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static
INSTALL_TARGET=	install-strip
USES=		gmake libtool readline
USE_LDCONFIG=	yes

OPTIONS_DEFINE=			FORTRAN HDF5 PYTHON QT4
OPTIONS_DEFAULT=		HDF5
OPTIONS_SUB=			yes

FORTRAN_CONFIGURE_ENABLE=	fortran
FORTRAN_USES=			fortran

HDF5_LIB_DEPENDS=		libhdf5.so:science/hdf5
HDF5_CONFIGURE_ON=		--with-hdf5=${LOCALBASE}/include,${LOCALBASE}/lib
HDF5_PLIST_SUB=			SUFX_HDF5="h5"
HDF5_PLIST_SUB_OFF=		SUFX_HDF5=""

PYTHON_CONFIGURE_ENABLE=	pythonmodule
PYTHON_USES=			python:2

QT4_USE=			XORG=ice,sm,x11,xext,xi,xmu,xt \
				QT4=corelib,gui,linguisttools_build,moc_build,uic_build
QT4_CONFIGURE_ON=		--with-Qt-dir=${QT_PREFIX} \
				--with-Qt-lib="QtGui -lQtCore"
QT4_CONFIGURE_ENABLE=		silex
QT4_VARS=			QT_NONSTANDARD=yes
QT4_DESKTOP_ENTRIES=		"Silex" "Silex browser for Silo files" \
				"" "silex" "" true

post-patch:
	@${REINPLACE_CMD} -e \
		's|\(_Qt_dir/include\)"|\1/qt4"| ; \
		 s|\(_Qt_dir/lib\)"|\1/qt4"| ; \
		 s|\(/uic\)"|\1-qt4"| ; \
		 s|\(/moc\)"|\1-qt4"| ; \
		 s|\(/lrelease\)"|\1-qt4"| ; \
		 s|\(/lupdate\)"|\1-qt4"|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/-avoid-version/s|^|#| ; \
		 /^install-data-am/s|:.*|:|' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		'/-ldl/s|^|#|' ${WRKSRC}/tests/Makefile.in
	@${REINPLACE_CMD} -e \
		's|@libdir@|@pythondir@|' ${WRKSRC}/tools/python/Makefile.in
	@${REINPLACE_CMD} -e \
		's|\(INBUILD\));|\1, me);|' ${WRKSRC}/src/hdf5_drv/silo_hdf5.c

.if defined(MAINTAINER_MODE)
regression-test: build
	@cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check
.endif

.include <bsd.port.mk>
