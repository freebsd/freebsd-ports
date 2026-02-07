PORTNAME=	btavctpd
DISTVERSION=	1.0.0
CATEGORIES=	multimedia

MAINTAINER=	nsonack@herrhotzenplotz.de
COMMENT=	Media-Player remote control daemon via Bluetooth
WWW=		https://github.com/herrhotzenplotz/btavctpd

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libplayerctl.so:multimedia/playerctl
RUN_DEPENDS=	xdotool:x11/xdotool

USES=		gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	herrhotzenplotz
USE_GNOME=	glib20

PLIST_FILES=	bin/btavctpd \
		share/man/man8/btavctpd.8.gz

.include <bsd.port.mk>
