PORTNAME=	rkward
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	IDE/GUI for the R-project
WWW=		https://rkward.kde.org/

LICENSE=	GPLv2

DEPRECATED=	Depends on expiring math/R-cran-car
EXPIRATION_DATE=2025-09-30

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libR.so:math/R	\
		libcups.so:print/cups	\
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	kbibtex:databases/kbibtex	\
		hs-pandoc>0:textproc/hs-pandoc	\
		${LR_MOD_DIR}/R2HTML/INDEX:textproc/R-cran-R2HTML	\
		${LR_MOD_DIR}/rmarkdown/INDEX:textproc/R-cran-rmarkdown
TEST_DEPENDS=	${LR_MOD_DIR}/FAdist/INDEX:science/R-cran-FAdist	\
		xcb-util-cursor>0:x11/xcb-util-cursor

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gl fortran	\
		kde:6 localbase php:cli qt:6 shared-mime-info xorg
USE_GL=		opengl
USE_QT=		5compat base declarative positioning webchannel webengine
USE_XORG=	ice x11 xext
USE_KDE=	archive bookmarks breeze-icons colorscheme completion config	\
		configwidgets coreaddons crash ecm doctools guiaddons i18n	\
		itemviews jobwidgets kio notifications parts service solid	\
		syntaxhighlighting texteditor widgetsaddons windowsystem xmlgui

TEST_TARGET=	plugintests

LR_MOD_DIR=	${LOCALBASE}/lib/R/library
DOCSDIR=	${PREFIX}/share/doc/HTML/en/rkward

OPTIONS_DEFINE=	DOCS NLS INSTTEST RECDEP
INSTTEST_DESC=	Install rkwardtests R package
RECDEP_DESC=	Recommended runtime dependencies
OPTIONS_DEFAULT=RECDEP
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRECDEP}
RUN_DEPENDS+=	${LR_MOD_DIR}/XML/INDEX:textproc/R-cran-XML		\
		${LR_MOD_DIR}/gdata/INDEX:devel/R-cran-gdata		\
		${LR_MOD_DIR}/mvtnorm/INDEX:math/R-cran-mvtnorm		\
		${LR_MOD_DIR}/nortest/INDEX:math/R-cran-nortest		\
		${LR_MOD_DIR}/outliers/INDEX:math/R-cran-outliers	\
		${LR_MOD_DIR}/qcc/INDEX:graphics/R-cran-qcc		\
		${LR_MOD_DIR}/tseries/INDEX:finance/R-cran-tseries	\
		${LR_MOD_DIR}/xtable/INDEX:textproc/R-cran-xtable	\
		${LR_MOD_DIR}/car/INDEX:math/R-cran-car			\
		${LR_MOD_DIR}/ltm/INDEX:math/R-cran-ltm			\
		${LR_MOD_DIR}/moments/INDEX:math/R-cran-moments		\
		${LR_MOD_DIR}/pwr/INDEX:math/R-cran-pwr			\
		${LR_MOD_DIR}/hdrcde/INDEX:math/R-cran-hdrcde		\
		${LR_MOD_DIR}/devtools/INDEX:devel/R-cran-devtools	\
		${LR_MOD_DIR}/exactRankTests/INDEX:math/R-cran-exactRankTests
#RUN_DEPENDS+=	${LR_MOD_DIR}/XLConnect/INDEX:math/R-cran-XLConnect
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
	#${RM} ${STAGEDIR}${PREFIX}/share/apps/katepart/syntax/r.xml # Conflicts with kate
.if ${PORT_OPTIONS:MINSTTEST}
	${MKDIR} ${STAGEDIR}${PREFIX}/${R_LIB_DIR}
	(cd ${WRKSRC}/rkward/rbackend/rpackages/rkwardtests &&	\
	${SETENV} ${MAKE_ENV} _R_CHECK_FORCE_SUGGESTS_=FALSE &&	\
	${R_COMMAND} CMD INSTALL -l ${STAGEDIR}${PREFIX}/${R_LIB_DIR} . )
.endif

.include <bsd.port.mk>
