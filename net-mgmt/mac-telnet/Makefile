PORTNAME=	mac-telnet
PORTVERSION=	0.4.5.a1
CATEGORIES=	net-mgmt net

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	MAC telnet client for connecting to MikroTik RouterOS devices
WWW=		https://github.com/haakonnessjoen/MAC-Telnet

LICENSE=	GPLv2

USES=		autoreconf libtool pkgconfig gettext
USE_GITHUB=	yes

GH_ACCOUNT=	haakonnessjoen
GH_PROJECT=	MAC-Telnet
GH_TAGNAME=	42d6271

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
