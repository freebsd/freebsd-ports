# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	rkward
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/Current_Stable_Releases
PKGNAMESUFFIX=	-kde4

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	IDE/GUI for the R-project

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R
RUN_DEPENDS=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R \
		${KDE4_PREFIX}/lib/kde4/katepart.so:${PORTSDIR}/editors/kate

CONFLICTS=	rkward-0.4.*

USE_QT4=	qmake_build moc_build rcc_build uic_build phonon

USE_KDE4=	kdehier kdeprefix automoc4 kdelibs
USE_PHP=	yes
WANT_PHP_CLI=	yes
USES=		cmake gettext
INSTALLS_ICONS=	yes

CFLAGS+=	-I${LOCALBASE}/include

DOCSDIR=	${PREFIX}/share/doc/HTML/en/rkward
MAN1=		rkward.1

.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
.endif

OPTIONS_DEFINE=	RECDEP
RECDEP_DESC=	Recommended runtime dependencies
OPTIONS_DEFAULT=RECDEP

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
NLS=		""
.else
NLS=		"@comment "
.endif
PLIST_SUB+=	NLS=${NLS}

.if ${PORT_OPTIONS:MRECDEP}
LR_MOD_DIR=	${LOCALBASE}/lib/R/library
RUN_DEPENDS+=	${LR_MOD_DIR}/R2HTML/INDEX:${PORTSDIR}/textproc/R-cran-R2HTML	\
		${LR_MOD_DIR}/XML/INDEX:${PORTSDIR}/textproc/R-cran-XML		\
		${LR_MOD_DIR}/mvtnorm/INDEX:${PORTSDIR}/math/R-cran-mvtnorm	\
		${LR_MOD_DIR}/outliers/INDEX:${PORTSDIR}/math/R-cran-outliers	\
		${LR_MOD_DIR}/tseries/INDEX:${PORTSDIR}/finance/R-cran-tseries	\
		${LR_MOD_DIR}/car/INDEX:${PORTSDIR}/math/R-cran-car
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|'	\
		${WRKSRC}/rkward/rbackend/rkfrontendtransmitter.cpp
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's|ADD_SUBDIRECTORY(doc)|#ADD_SUBDIRECTORY(doc)|'	\
		${WRKSRC}/CMakeLists.txt
.else
#Fix build with kdelibs>=4.5.0
	${REINPLACE_CMD} -e 's,V4.1-Based Variant V1.0,V4.2-Based Variant V1.1,g' \
		${WRKSRC}/doc/rkward/index.docbook
.endif
.if ! ${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e 's|ADD_SUBDIRECTORY(po)|#ADD_SUBDIRECTORY(po)|'	\
		${WRKSRC}/CMakeLists.txt
.endif
	@(if [ ! -e ${LOCALBASE}/lib/R/lib/libR.so ] ; then \
	${ECHO_MSG} "==> ${PKGNAME} requires math/R to be built WITH_LIBR" ; \
	exit 1; fi)

.if defined(MAINTAINER_MODE)
regression-test:	install
	@${ECHO_MSG} "To pass the tests, some CRAN packages like R2HTML"
	@${ECHO_MSG} "must be installed."
	(cd ${WRKSRC}/tests && KDE_LANG=en_US make plugintests)
.endif

.include <bsd.port.mk>
