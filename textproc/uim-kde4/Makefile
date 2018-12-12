# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	2
PKGNAMESUFFIX=	-kde4

COMMENT=	KDE4 panel applet of uim input method

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS=	libuim.so:textproc/uim
RUN_DEPENDS=	uim-pref-qt4:textproc/uim-qt4

USE_GCC=	any
USE_KDE=	kdelibs automoc4
USE_QT=		corelib dbus gui qmake_build moc_build qt3support svg uic rcc
USES+=		kde:4 qt:4

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-qt4 --enable-pref --enable-default-toolkit=qt4 \
		--enable-kde4-applet
CONFIGURE_ENV=	KDE4_CONFIG="${KDE_PREFIX}/bin/kde4-config"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-qt4_toolbar_CMakeLists.txt

.if defined(WITHOUT_X11)
IGNORE=		requires X11
.endif

do-build:
	(cd ${WRKSRC}/qt4/toolbar/build && ${SETENV} ${MAKE_ENV} ${MAKE_CMD})

do-install:
	(cd ${WRKSRC}/qt4/toolbar/build && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} DESTDIR=${STAGEDIR} install)

.include "${MASTERDIR}/Makefile"
