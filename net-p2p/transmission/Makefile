PORTNAME=	transmission
DISTVERSION=	4.0.5
CATEGORIES=	net-p2p

MAINTAINER=	mondo.debater_0q@icloud.com
COMMENT=	Transmission BitTorrent client
WWW=		https://www.transmissionbt.com

LICENSE=	GPLv3+

USES=		metaport

OPTIONS_DEFINE=		CLI DAEMON DOCS GTK QT UTILS
OPTIONS_DEFAULT=	CLI DAEMON GTK QT UTILS

CLI_DESC=	Build command-line client (deprecated)
DAEMON_DESC=	Build daemon
DOCS_DESC=	Install documentation
GTK_DESC=	Build GTK+ client
QT_DESC=	Build QT client
UTILS_DESC=	Build utilities (create, edit, remote, show)

CLI_RUN_DEPENDS=	transmission-cli:net-p2p/transmission-components@cli
DAEMON_RUN_DEPENDS=	transmission-daemon:net-p2p/transmission-components@daemon
DOCS_RUN_DEPENDS=	${DOCSDIR}/README.md:net-p2p/transmission-components@docs
GTK_RUN_DEPENDS=	transmission-gtk:net-p2p/transmission-components@gtk
QT_RUN_DEPENDS=		transmission-qt:net-p2p/transmission-components@qt
UTILS_RUN_DEPENDS=	transmission-create:net-p2p/transmission-components@utils

.include <bsd.port.mk>
