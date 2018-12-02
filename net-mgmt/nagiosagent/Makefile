# Created by: Eugene Mychlo <myc@barev.net>
# $FreeBSD$

PORTNAME=	NagiosAgent
PORTVERSION=	1.2.0.1
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netpatch.ru/projects/nagiosagent/ \
		http://www.netpatch.ru/projects/nagiosagent/old/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	myc@barev.net
COMMENT=	Qt-based frontend to Nagios

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

PLIST_FILES=	bin/NagiosAgent \
		share/pixmaps/NagiosAgent.png

USES=		qmake qt:4 zip
USE_QT=		gui network corelib uic_build rcc_build moc_build

DESKTOP_ENTRIES=	"NagiosAgent" "GUI client for Nagios" \
			"${PREFIX}/share/pixmaps/NagiosAgent.png" \
			"NagiosAgent" "Network;Qt;" true

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/NagiosAgent ${STAGEDIR}${PREFIX}/bin/NagiosAgent
	${INSTALL_DATA} ${WRKSRC}/resources/icon16x16.png ${STAGEDIR}${PREFIX}/share/pixmaps/NagiosAgent.png

.include <bsd.port.mk>
