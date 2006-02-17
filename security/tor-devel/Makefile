# ports collection makefile for:	tor-devel
# Date created:				2005.10.20
# Whom:					peter.thoenen@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	tor
PORTVERSION=	0.1.1.13
CATEGORIES=	security net
MASTER_SITES=	http://tor.eff.org/dist/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}-alpha

MAINTAINER=	peter.thoenen@yahoo.com
COMMENT=	An anonymizing overlay network for TCP

RUN_DEPENDS=	tsocks:${PORTSDIR}/net/tsocks
LIB_DEPENDS=	event-1.1a:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

USE_RC_SUBR=	tor
SUB_FILES=	pkg-message
PKG_MESSAGE=	${WRKSRC}/pkg-message

CONFLICTS=	tor-[0-9]*

MANCOMPRESSED=	no
MAN1=		tor.1 tor-resolve.1 torify.1

post-patch:
	@${MV} ${WRKSRC}/contrib/tor-tsocks.conf \
		${WRKSRC}/contrib/tor-tsocks.conf.sample
	@${REINPLACE_CMD} -e "s|tor-tsocks.conf|tor-tsocks.conf.sample|g" \
		${WRKSRC}/contrib/Makefile.in
	@${FIND} ${WRKSRC} -type f | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E \
		-e 's!-g -O2!!' \
		-e 's!-O2!!'

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${MKDIR} /var/run/tor
	@${CHOWN} _tor:_tor /var/run/tor
	@${TOUCH} /var/log/tor
	@${CHOWN} _tor:_tor /var/log/tor
	@${MKDIR} /var/db/tor
	@${MKDIR} /var/db/tor/data
	@${CHOWN} -R _tor:_tor /var/db/tor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
