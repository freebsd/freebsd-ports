# Created by: Pedro F. Giffuni <giffunip@tutopia.com>
# $FreeBSD$

PORTNAME=	silo
PORTVERSION=	4.9
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

NO_LATEST_LINK=	yes

USES=		readline
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFORTRAN}
USE_FORTRAN=	yes
.else
CONFIGURE_ARGS+=	--disable-fortran
.endif

.if ${PORT_OPTIONS:MHDF5}
LIB_DEPENDS+=	hdf5:${PORTSDIR}/science/hdf5
CONFIGURE_ARGS+=	--with-hdf5=${LOCALBASE}/include,${LOCALBASE}/lib
PLIST_SUB+=	HDF5="" NOHDF5="@comment "
.else
PLIST_SUB+=	HDF5="@comment " NOHDF5=""
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--enable-pythonmodule
PLIST_SUB+=	PYTHON=""
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MQT4}
USE_XORG=	xext xi xmu xt
USE_QT4=	qt3support linguist_build moc_build uic_build
QT_NONSTANDARD=	yes
CONFIGURE_ARGS+=	--with-Qt-dir=${QT_PREFIX}
PLIST_SUB+=	QT4=""
DESKTOP_ENTRIES="Silex" "Silex browser for Silo files" "" "silex" "" true
.else
CONFIGURE_ARGS+=	--disable-silex
PLIST_SUB+=	QT4="@comment "
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
	@cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${GMAKE} check
.endif

.include <bsd.port.mk>
