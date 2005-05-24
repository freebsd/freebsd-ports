# ports collection makefile for: 		tor
# Date created: 				2004.05.28
# Whom:						freebsd-ports@rikrose.net
#
# $FreeBSD$
#

PORTNAME=	tor
PORTVERSION=	0.0.9.9
# PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://tor.eff.org/dist/

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
# uphold CFLAGS
	@${FIND} ${WRKSRC} -type f | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E \
		-e 's!-g -O2!!' \
		-e 's!-O2!!'

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${CP} ${WRKSRC}/contrib/tor.sh ${LOCALBASE}/etc/rc.d/tor.sh.sample

.include <bsd.port.mk>
