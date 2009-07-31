# New ports collection makefile for:	digitizer
# Date created:		27 May 2006
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	digitizer
PORTVERSION=	4.1
PORTREVISION=	4
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	digit-src-${PORTVERSION:S/./_/}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Engauge Digitizer - Digitizing software to convert graphs into numbers

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	fftw3.5:${PORTSDIR}/math/fftw3

WRKSRC=		${WRKDIR}/engauge

USE_QT_VER=	3
QTDIR?=		${QT_PREFIX}
MAKE_ENV=	QMAKESPEC="${LOCALBASE}/share/qt/mkspecs/freebsd-g++"	\
		QTDIR="${QTDIR}"

DESKTOP_ENTRIES=	"Engauge Digitizer" \
			"Digitizing software to convert graphs into numbers" \
			"${DATADIR}/lo16-app-digitizer.png" \
			"engauge" \
			"Education;Math;" \
			true

.if !defined(NOPORTDOCS)
DOCS=		README
.endif

pre-configure:
.if !defined(WITH_DEBUG)
	${REINPLACE_CMD} -e '/^CONFIG/s/debug/release/' ${WRKSRC}/digitizer.pro
.endif
	${REINPLACE_CMD} -e 's|Path1("usermanual")|Path1("${DOCSDIR}/usermanual")|'	\
		${WRKSRC}/src/digitmain.cpp

pre-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} qmake -unix digitizer.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/engauge ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/img/lo16-app-digitizer.png	\
		${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/usermanual
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	cd ${WRKSRC}/usermanual && ${FIND} . -type f -depth 1	\
		-exec ${INSTALL_DATA} {} ${DOCSDIR}/usermanual \;
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${FIND} . -type f -depth 1	\
		-exec ${INSTALL_DATA} {} ${EXAMPLESDIR} \;
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
