# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-qt

COMMENT=	QT modules of uim input method

USE_QT_VER=	3
USE_AUTOTOOLS=	libtool

LIB_DEPENDS=	uim:${PORTSDIR}/textproc/uim

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-qt --enable-pref --enable-default-toolkit=qt \
		--disable-kde-applet
CONFIGURE_ENV=	QTDIR=${LOCALBASE}/lib QTINCDIR=${LOCALBASE}/include \
		LIBS="${LIBS} ${PTHREAD_LIBS} -L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
CXXFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-qt3_candwin_Makefile.in \
		${PATCHDIR}/extra-patch-qt3_immodule_Makefile.in \
		${PATCHDIR}/extra-patch-qt3_pref_Makefile.in \
		${PATCHDIR}/extra-patch-qt3_switcher_Makefile.in \
		${PATCHDIR}/extra-patch-qt3_toolbar_Makefile.in

.if defined(WITHOUT_X11)
IGNORE=		requires X11
.endif

do-build:
	(cd ${WRKSRC}/uim && ${SETENV} ${MAKE_ENV} ${GMAKE} libuim-counted-init.la)
	(cd ${WRKSRC}/qt3 && ${SETENV} ${MAKE_ENV} ${GMAKE})

do-install:
	(cd ${WRKSRC}/qt3 && ${SETENV} ${MAKE_ENV} ${GMAKE} install)

.include "${MASTERDIR}/Makefile"
