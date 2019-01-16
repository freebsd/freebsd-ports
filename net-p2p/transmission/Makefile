# $FreeBSD$

PORTNAME=	transmission
DISTVERSION=	2.94
PORTREVISION=	2
CATEGORIES=	net-p2p

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Meta-port for Transmission BitTorrent client

LICENSE=	GPLv2+ MIT
LICENSE_COMB=	multi

USES=		metaport

OPTIONS_DEFINE=		CLI DAEMON GTK WEB

OPTIONS_RADIO=		QT
OPTIONS_RADIO_QT=	QT4 QT5

CLI_DESC=		Command line version
DAEMON_DESC=		Daemon version
GTK_DESC=		GTK version
QT4_DESC=		Qt4 version
QT5_DESC=		Qt5 version
WEB_DESC=		Web client

OPTIONS_DEFAULT=	CLI DAEMON GTK QT4 WEB

CLI_RUN_DEPENDS=	transmission-cli:net-p2p/transmission-cli
DAEMON_RUN_DEPENDS=	transmission-daemon:net-p2p/transmission-daemon
GTK_RUN_DEPENDS=	transmission-gtk:net-p2p/transmission-gtk
QT4_RUN_DEPENDS=	transmission-qt:net-p2p/transmission-qt@qt4
QT5_RUN_DEPENDS=	transmission-qt:net-p2p/transmission-qt@qt5
WEB_RUN_DEPENDS=	${DATADIR}/web/index.html:www/transmission-web

.include <bsd.port.mk>
