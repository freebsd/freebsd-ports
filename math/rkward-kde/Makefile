# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	rkward
DISTVERSION=	0.7.0b
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION:C/b//}/src
PKGNAMESUFFIX=	-kde

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	IDE/GUI for the R-project

LICENSE=	GPLv2

LIB_DEPENDS=	libR.so:math/R \
		libsoprano.so:textproc/soprano

USES=		cmake desktop-file-utils gettext fortran kde:5 php:cli qt:5 shared-mime-info
USE_QT=		buildtools core dbus gui network printsupport qmake script webkit	\
		widgets xml
USE_XORG=	x11
USE_KDE=	auth bookmarks codecs completion config configwidgets coreaddons crash	\
		doctools ecm i18n itemviews jobwidgets kate_run kdewebkit kio		\
		notifications parts service solid sonnet texteditor textwidgets		\
		widgetsaddons windowsystem xmlgui

CFLAGS+=	-I${LOCALBASE}/include

DOCSDIR=	${PREFIX}/share/doc/HTML/en/rkward

OPTIONS_DEFINE=	RECDEP DOCS NLS
RECDEP_DESC=	Recommended runtime dependencies
OPTIONS_DEFAULT=RECDEP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
NLS=		""
.else
NLS=		"@comment "
.endif
PLIST_SUB+=	NLS=${NLS}

.if ${PORT_OPTIONS:MRECDEP}
LR_MOD_DIR=	${LOCALBASE}/lib/R/library
RUN_DEPENDS+=	${LR_MOD_DIR}/R2HTML/INDEX:textproc/R-cran-R2HTML	\
		${LR_MOD_DIR}/XML/INDEX:textproc/R-cran-XML		\
		${LR_MOD_DIR}/gdata/INDEX:devel/R-cran-gdata		\
		${LR_MOD_DIR}/mvtnorm/INDEX:math/R-cran-mvtnorm		\
		${LR_MOD_DIR}/outliers/INDEX:math/R-cran-outliers	\
		${LR_MOD_DIR}/tseries/INDEX:finance/R-cran-tseries	\
		${LR_MOD_DIR}/car/INDEX:math/R-cran-car
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

post-install:
	${RM} ${STAGEDIR}${PREFIX}/share/apps/katepart/syntax/r.xml # Conflicts with kate

.if defined(MAINTAINER_MODE)
regression-test:	install
	@${ECHO_MSG} "To pass the tests, some CRAN packages like R2HTML"
	@${ECHO_MSG} "must be installed."
	(cd ${WRKSRC}/tests && KDE_LANG=en_US make plugintests)
.endif

.include <bsd.port.mk>
