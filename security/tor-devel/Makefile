# ports collection makefile for: 		tor
# Date created: 				2004.05.28
# Whom:						freebsd-ports@rikrose.net
#
# $FreeBSD$
#

PORTNAME=	tor
PORTVERSION=	0.0.6.2
CATEGORIES=	security
MASTER_SITES=	http://freehaven.net/tor/dist/

MAINTAINER=	freebsd-ports@rikrose.net
COMMENT=	An anonymizing overlay network for TCP

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_OPENSSL=	yes
USE_REINPLACE=	yes

MANCOMPRESSED=	no
MAN1=		tor.1 torify.1

post-patch:
	@${MV} ${WRKSRC}/contrib/tor-tsocks.conf \
		${WRKSRC}/contrib/tor-tsocks.conf.sample
	@${REINPLACE_CMD} -e "s|tor-tsocks.conf|tor-tsocks.conf.sample|g" \
		${WRKSRC}/contrib/Makefile.in

.include <bsd.port.mk>
