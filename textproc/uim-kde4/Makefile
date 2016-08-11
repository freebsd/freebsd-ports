# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-kde4

COMMENT=	KDE4 panel applet of uim input method

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS=	libuim.so:textproc/uim
RUN_DEPENDS=	uim-pref-qt4:textproc/uim-qt4

USE_GCC=	any
USE_KDE4=	kdelibs automoc4
USE_QT4=	qmake_build moc_build qt3support uic rcc

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-qt4 --enable-pref --enable-default-toolkit=qt4 \
		--enable-kde4-applet
CONFIGURE_ENV=	KDE4_CONFIG="${KDE4_PREFIX}/bin/kde4-config"
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
