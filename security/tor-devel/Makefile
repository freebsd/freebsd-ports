# ports collection makefile for:	tor-devel
# Date created:				2005.10.20
# Whom:					eol1@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	tor
PORTVERSION=	0.1.1.10
CATEGORIES=	security net
MASTER_SITES=	http://tor.eff.org/dist/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}-alpha

MAINTAINER=	eol1@yahoo.com
COMMENT=	An anonymizing overlay network for TCP

RUN_DEPENDS=	tsocks:${PORTSDIR}/net/tsocks
LIB_DEPENDS=	event-1.1a:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_REINPLACE=	yes

CONFLICTS=	tor-[0-9]*

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
	${INSTALL_DATA} ${WRKSRC}/contrib/tor.sh ${PREFIX}/etc/rc.d/tor.sh.sample

.include <bsd.port.mk>
