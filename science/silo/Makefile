# Created by: Pedro F. Giffuni <giffunip@tutopia.com>
# $FreeBSD$

PORTNAME=	silo
PORTVERSION=	4.9.1
DISTVERSIONSUFFIX=	-bsd
CATEGORIES=	science
MASTER_SITES=	https://wci.llnl.gov/codes/${PORTNAME}/silo-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mesh and field I/O library and scientific database

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

OPTIONS_DEFINE=	HDF5 PYTHON
OPTIONS_RADIO=	EXCLUSIVE
OPTIONS_RADIO_EXCLUSIVE=	FORTRAN QT4
OPTIONS_DEFAULT=	QT4

OPTIONS_SUB=	yes

USES=		gmake readline
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static
USE_LDCONFIG=	yes

FORTRAN_CONFIGURE_ENABLE=	fortran
FORTRAN_USE=			FORTRAN=yes

PYTHON_CONFIGURE_ENABLE=	pythonmodule
PYTHON_USE=			PYTHON=yes

QT4_USE=			XORG=xext,xi,xmu,xt \
				QT4=gui,linguist_build,moc_build,uic_build
QT4_CONFIGURE_ON=		--with-Qt-dir=${QT_PREFIX} \
				--with-Qt-lib="QtGui -lQtCore"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHDF5}
LIB_DEPENDS+=	libhdf5.so:${PORTSDIR}/science/hdf5
CONFIGURE_ARGS+=	--with-hdf5=${LOCALBASE}/include,${LOCALBASE}/lib
PLIST_SUB+=	SUFX_HDF5="h5"
.else
PLIST_SUB+=	SUFX_HDF5=""
.endif

.if ${PORT_OPTIONS:MQT4}
QT_NONSTANDARD=	yes
DESKTOP_ENTRIES="Silex" "Silex browser for Silo files" "" "silex" "" true
.else
CONFIGURE_ARGS+=	--disable-silex
.endif

post-extract:
	@${CHMOD} -R a+rX ${WRKSRC}

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
