# New ports collection makefile for:   uim-kde4
# Date created:        26 November 2010
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-kde4

COMMENT=	KDE4 panel applet of uim input method

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake
LIB_DEPENDS=	uim.7:${PORTSDIR}/textproc/uim
RUN_DEPENDS=	uim-pref-qt4:${PORTSDIR}/textproc/uim-qt4

USE_GCC=	4.2+
USE_KDE4=	kdehier kdeprefix kdelibs automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build qt3support uic rcc
USE_AUTOTOOLS=	libtool

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-qt4 --enable-pref --enable-default-toolkit=qt4 \
		--enable-kde4-applet
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
	KDE4_CONFIG="${KDE4_PREFIX}/bin/kde4-config"
UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-qt4_toolbar_CMakeLists.txt

.if defined(WITHOUT_X11)
IGNORE=		requires X11
.endif

do-build:
	(cd ${WRKSRC}/qt4/toolbar/build && ${SETENV} ${MAKE_ENV} ${GMAKE})

do-install:
	(cd ${WRKSRC}/qt4/toolbar/build && ${SETENV} ${MAKE_ENV} ${GMAKE} install)

.include "${MASTERDIR}/Makefile"
