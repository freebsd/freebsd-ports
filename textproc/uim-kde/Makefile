# New ports collection makefile for:   uim-kde
# Date created:        10 March 2007
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-kde

COMMENT=	KDE panel applet of uim input method

LIB_DEPENDS=	uim.6:${PORTSDIR}/textproc/uim
RUN_DEPENDS=	uim-pref-qt:${PORTSDIR}/textproc/uim-qt

USE_GCC=	4.2+
USE_KDELIBS_VER=3
USE_QT_VER=	3
USE_AUTOTOOLS=	libtool:22

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-qt --enable-pref --enable-default-toolkit=qt \
		--enable-kde-applet
CONFIGURE_ENV=	QTDIR=${X11BASE}/lib QTINCDIR=${X11BASE}/include \
		CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS} ${PTHREAD_CFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" \
		LIBS="${LIBS} ${PTHREAD_LIBS} -L${X11BASE}/lib -L${LOCALBASE}/lib" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS} -L${X11BASE}/lib -L${LOCALBASE}/lib"
UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-qt_Makefile.in

.if defined(WITHOUT_X11)
IGNORE=		requires X11
.endif

do-build:
	(cd ${WRKSRC}/qt && ${SETENV} ${MAKE_ENV} ${GMAKE} uim_panelapplet.la)

do-install:
	(cd ${WRKSRC}/qt && ${SETENV} ${MAKE_ENV} ${GMAKE} install-appletLTLIBRARIES install-lnkDATA)

.include "${MASTERDIR}/Makefile"
