# New ports collection makefile for:   uim-qt
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-qt

COMMENT=	QT modules of uim input method

USE_QT_VER=	3
USE_AUTOTOOLS=	libtool:22

LIB_DEPENDS=	uim.6:${PORTSDIR}/textproc/uim

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-qt --enable-pref --enable-default-toolkit=qt \
		--disable-kde-applet
CONFIGURE_ENV=	QTDIR=${X11BASE}/lib QTINCDIR=${X11BASE}/include \
		CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		CXXFLAGS="${CXXFLAGS} ${PTHREAD_CFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" \
		LIBS="${LIBS} ${PTHREAD_LIBS} -L${X11BASE}/lib -L${LOCALBASE}/lib" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS} -L${X11BASE}/lib -L${LOCALBASE}/lib"
UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-qt_Makefile.in \
		${PATCHDIR}/extra-patch-qt_chardict_po_Makefile.in.in

.if defined(WITHOUT_X11)
IGNORE=		requires X11
.endif

do-build:
	(cd ${WRKSRC}/uim && ${SETENV} ${MAKE_ENV} ${GMAKE} libuim-counted-init.la)
	(cd ${WRKSRC}/qt && ${SETENV} ${MAKE_ENV} ${GMAKE})

do-install:
	(cd ${WRKSRC}/qt && ${SETENV} ${MAKE_ENV} ${GMAKE} install)

.include "${MASTERDIR}/Makefile"
