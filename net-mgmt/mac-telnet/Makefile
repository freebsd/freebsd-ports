PORTNAME=	mac-telnet
PORTVERSION=	0.5.2
PORTEPOCH=	1
CATEGORIES=	net-mgmt net

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	MAC telnet client for connecting to MikroTik RouterOS devices
WWW=		https://github.com/haakonnessjoen/MAC-Telnet

LICENSE=	GPLv2

USES=		autoreconf libtool pkgconfig gettext ssl
USE_GITHUB=	yes

GH_ACCOUNT=	haakonnessjoen
GH_PROJECT=	MAC-Telnet
GH_TAGNAME=	v${PORTVERSION}

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"

post-install:
	@${CHMOD} 0600 ${STAGEDIR}${PREFIX}/etc/mactelnetd.users
	@-${CHOWN} root ${STAGEDIR}${PREFIX}/etc/mactelnetd.users

.include <bsd.port.mk>
