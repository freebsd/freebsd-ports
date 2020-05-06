# $FreeBSD$

PORTNAME=	transmission
DISTVERSION=	3.00
CATEGORIES=	net-p2p

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Meta-port for Transmission BitTorrent client

LICENSE=	GPLv2+ MIT
LICENSE_COMB=	multi

USES=		metaport

OPTIONS_DEFINE=		CLI DAEMON GTK WEB QT
OPTIONS_DEFAULT=        CLI GTK WEB

CLI_DESC=		Command line version
DAEMON_DESC=		Daemon version
GTK_DESC=		GTK version
QT_DESC=		Qt version
WEB_DESC=		Web client

CLI_RUN_DEPENDS=	transmission-cli:net-p2p/transmission-cli
DAEMON_RUN_DEPENDS=	transmission-daemon:net-p2p/transmission-daemon
GTK_RUN_DEPENDS=	transmission-gtk:net-p2p/transmission-gtk
QT_RUN_DEPENDS=		transmission-qt:net-p2p/transmission-qt
WEB_RUN_DEPENDS=	${DATADIR}/web/index.html:www/transmission-web

.include <bsd.port.mk>
