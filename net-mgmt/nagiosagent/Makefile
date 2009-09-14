# New ports collection makefile for:	NagiosAgent
# Date created:				02 Jun 2009
# Whom:					Eugene Mychlo <myc@barev.net>
#
# $FreeBSD$
#

PORTNAME=	NagiosAgent
PORTVERSION=	1.2.0.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netpatch.ru/projects/nagiosagent/ \
		http://www.netpatch.ru/projects/nagiosagent/old/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	myc@barev.net
COMMENT=	A QT-based frontend to Nagios

PLIST_FILES=	bin/NagiosAgent \
		share/pixmaps/NagiosAgent.png

USE_ZIP=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui network corelib qmake_build uic_build rcc_build moc_build

DESKTOP_ENTRIES=	"NagiosAgent" "GUI client for Nagios" \
			"NagiosAgent.png" \
			"NagiosAgent" "Application;Network;" false

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE} -unix NagiosAgent.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/NagiosAgent    ${PREFIX}/bin/NagiosAgent
	${INSTALL_DATA} ${WRKSRC}/resources/icon16x16.png ${PREFIX}/share/pixmaps/NagiosAgent.png

.include <bsd.port.mk>
