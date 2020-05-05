# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	rkward
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION:C/b//}/src
PKGNAMESUFFIX=	-kde

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	IDE/GUI for the R-project

LICENSE=	GPLv2

LIB_DEPENDS=	libR.so:math/R
TEST_DEPENDS=	${LR_MOD_DIR}/FAdist/INDEX:science/R-cran-FAdist

USES=		cmake compiler:c++11-lang desktop-file-utils gettext fortran \
		kde:5 php:cli qt:5 shared-mime-info xorg
USE_QT=		buildtools concurrent core dbus gui network printsupport qmake script webkit	\
		widgets xml
USE_XORG=	x11
USE_KDE=	auth bookmarks codecs completion config configwidgets coreaddons crash	\
		doctools ecm i18n itemviews jobwidgets kate_run kdewebkit kio		\
		notifications parts service solid sonnet texteditor textwidgets		\
		widgetsaddons windowsystem xmlgui

CFLAGS+=	-I${LOCALBASE}/include

LR_MOD_DIR=	${LOCALBASE}/lib/R/library
DOCSDIR=	${PREFIX}/share/doc/HTML/en/rkward

OPTIONS_DEFINE=	DOCS NLS INSTTEST RECDEP
INSTTEST_DESC=	Install rkwardtests R package
RECDEP_DESC=	Recommended runtime dependencies
OPTIONS_DEFAULT=RECDEP
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRECDEP}
RUN_DEPENDS+=	${LR_MOD_DIR}/R2HTML/INDEX:textproc/R-cran-R2HTML	\
		${LR_MOD_DIR}/XML/INDEX:textproc/R-cran-XML		\
		${LR_MOD_DIR}/gdata/INDEX:devel/R-cran-gdata		\
		${LR_MOD_DIR}/mvtnorm/INDEX:math/R-cran-mvtnorm		\
		${LR_MOD_DIR}/nortest/INDEX:math/R-cran-nortest		\
		${LR_MOD_DIR}/outliers/INDEX:math/R-cran-outliers	\
		${LR_MOD_DIR}/qcc/INDEX:graphics/R-cran-qcc		\
		${LR_MOD_DIR}/tseries/INDEX:finance/R-cran-tseries	\
		${LR_MOD_DIR}/car/INDEX:math/R-cran-car
.endif

.if ${PORT_OPTIONS:MINSTTEST}
R_LIB_DIR=	lib/R/library
R_COMMAND=	${LOCALBASE}/bin/R
.endif

pre-configure:
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's|ADD_SUBDIRECTORY(doc)|#ADD_SUBDIRECTORY(doc)|'	\
		${WRKSRC}/CMakeLists.txt
.endif
.if ! ${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e 's|ADD_SUBDIRECTORY(po)|#ADD_SUBDIRECTORY(po)|'	\
		${WRKSRC}/CMakeLists.txt
.endif
	@(if [ ! -e ${LOCALBASE}/lib/R/lib/libR.so ] ; then \
	${ECHO_MSG} "==> ${PKGNAME} requires math/R to be built WITH_LIBR" ; \
	exit 1; fi)

post-install:
	${RM} ${STAGEDIR}${PREFIX}/share/apps/katepart/syntax/r.xml # Conflicts with kate
.if ${PORT_OPTIONS:MINSTTEST}
	${MKDIR} ${STAGEDIR}${PREFIX}/${R_LIB_DIR}
	(cd ${WRKSRC}/rkward/rbackend/rpackages/rkwardtests &&	\
	${SETENV} ${MAKE_ENV} _R_CHECK_FORCE_SUGGESTS_=FALSE &&	\
	${R_COMMAND} CMD INSTALL -l ${STAGEDIR}${PREFIX}/${R_LIB_DIR} . )
.endif

.if defined(MAINTAINER_MODE)
regression-test:	install
	(cd ${WRKSRC}/tests &&	\
	KDE_LANG=en_US ${PREFIX}/bin/${PORTNAME}  --evaluate source\(\"all_tests.R\"\) )
.endif

.include <bsd.port.mk>
