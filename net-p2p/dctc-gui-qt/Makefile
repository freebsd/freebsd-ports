# New ports collection makefile for:	dctc qt gui
# Date created:		Sun Jul 28 7:00:43 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dctc
PORTVERSION=	0.0.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dc-qt
PKGNAMESUFFIX=	-gui-qt
DISTNAME=	dc-qt-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A Qt GUI for the Direct Connect (TM) dctc text client

RUN_DEPENDS=	dctc:${PORTSDIR}/net/dctc

USE_QT_VER=	3
USE_REINPLACE=	yes
USE_SIZE=	yes
MAKE_ENV=	QTDIR="${QTDIR}"
PLIST_FILES=	bin/dc-qt

QTDIR?=	${X11BASE}
QMAKE?=	${X11BASE}/bin/qmake

post-patch:
	@${REINPLACE_CMD} -E -e 's|"hublist|"dc_hublist|' \
		${WRKSRC}/dc_hub.cc

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		-spec ${X11BASE}/share/qt/mkspecs/freebsd-g++ dc-qt.pro

post-configure:
# uphold CC/CXX/CFLAGS
# link against correct qt lib
	@${REINPLACE_CMD} -E -e 's|^CC.+$$|CC=${CC}|; \
		s|^CXX[[:space:]]*=.*$$|CXX=${CXX}|; \
		s|^(CFLAGS.+)$$|\1 ${PTHREAD_CFLAGS}|; \
		s|-lqt |-lqt-mt ${PTHREAD_LIBS:S/"//g} |' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dc-qt ${PREFIX}/bin

.include <bsd.port.mk>
