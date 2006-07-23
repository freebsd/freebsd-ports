# New ports collection makefile for:   uim-qt
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-qt

COMMENT=	QT modules of uim input method

LIB_DEPENDS=	qt-mt.3:${PORTSDIR}/x11-toolkits/qt33 \
		uim.2:${PORTSDIR}/textproc/uim

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-qt
CONFIGURE_ENV=	QTDIR=${X11BASE}/lib QTINCDIR=${X11BASE}/include \
		CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		CXXFLAGS="${CXXFLAGS} ${PTHREAD_CFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" \
		LIBS="${LIBS} ${PTHREAD_LIBS} -L${X11BASE}/lib -L${LOCALBASE}/lib" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS} -L${X11BASE}/lib -L${LOCALBASE}/lib"
UIM_SLAVE=	yes

# This is normally handled by defining USE_QT_VER ...

.if defined(PACKAGE_BUILDING)
TMPDIR?=	/tmp                
MAKE_ENV+=	TMPDIR="${TMPDIR}"      
CONFIGURE_ENV+=	TMPDIR="${TMPDIR}" 
.endif

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-qt_Makefile.in 

.if defined(WITHOUT_X11)
IGNORE=		requires X11
.endif

do-build:
	(cd ${WRKSRC}/qt && ${GMAKE} LIBS="-luim -luim-custom")

do-install:
	(cd ${WRKSRC}/qt && ${SETENV} ${MAKE_ENV} ${GMAKE} install)

.include "${MASTERDIR}/Makefile"
