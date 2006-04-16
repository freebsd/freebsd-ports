# New ports collection makefile for:   uim-qt
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-qt

COMMENT=	QT modules of uim input method

RUN_DEPENDS=	uim-module-manager:${PORTSDIR}/textproc/uim
LIB_DEPENDS+=	qt-mt.3:${PORTSDIR}/x11-toolkits/qt33

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-qt
CONFIGURE_ENV=	QTDIR=${X11BASE}/lib QTINCDIR=${X11BASE}/include \
		CXXFLAGS="${CXXFLAGS} ${PTHREAD_CFLAGS} -I${X11BASE}/include" LIBS="${LIBS} ${PTHREAD_LIBS} -L${X11BASE}/lib"

UIM_SLAVE=	yes

do-install:
	(cd ${WRKSRC}/qt && ${GMAKE} install)
	(cd ${WRKSRC}/helper && ${GMAKE} install)

.include "${MASTERDIR}/Makefile"
