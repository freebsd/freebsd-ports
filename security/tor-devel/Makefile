# ports collection makefile for: 		tor
# Date created: 				2004.05.28
# Whom:						freebsd-ports@rikrose.net
#
# $FreeBSD$
#

PORTNAME=	tor
PORTVERSION=	0.0.8.1
CATEGORIES=	security
MASTER_SITES=	http://tor.freehaven.net/dist/

MAINTAINER=	freebsd-ports@rikrose.net
COMMENT=	An anonymizing overlay network for TCP

RUN_DEPENDS=	tsocks:${PORTSDIR}/net/tsocks

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_OPENSSL=	yes
USE_REINPLACE=	yes

MANCOMPRESSED=	no
MAN1=		tor.1 tor-resolve.1 torify.1

post-patch:
	@${MV} ${WRKSRC}/contrib/tor-tsocks.conf \
		${WRKSRC}/contrib/tor-tsocks.conf.sample
	@${REINPLACE_CMD} -e "s|tor-tsocks.conf|tor-tsocks.conf.sample|g" \
		${WRKSRC}/contrib/Makefile.in

post-install:
	@${CP} ${WRKSRC}/contrib/tor.sh ${LOCALBASE}/etc/rc.d/tor.sh.sample

.include <bsd.port.mk>
