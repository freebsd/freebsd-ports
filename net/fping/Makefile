PORTNAME=	fping
DISTVERSION=	5.5
CATEGORIES=	net
MASTER_SITES=	http://fping.org/dist/ \
		https://github.com/schweikert/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Quickly ping multiple hosts without flooding the network
WWW=		https://www.fping.org/

LICENSE=	PreviousBSD
LICENSE_GROUPS=	FSF
LICENSE_NAME=	Previous BSD License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	IPV6
OPTIONS_SUB=	yes

IPV6_CONFIGURE_OFF=	--disable-ipv6

post-install-IPV6-on:
	${RLN} ${STAGEDIR}${PREFIX}/sbin/fping ${STAGEDIR}${PREFIX}/sbin/fping6
	${RLN} ${STAGEDIR}${PREFIX}/share/man/man8/fping.8 ${STAGEDIR}${PREFIX}/share/man/man8/fping6.8

.include <bsd.port.mk>
