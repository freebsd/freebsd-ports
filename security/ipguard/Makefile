# New ports collection makefile for:    ipguard
# Date created:                         2 Sep 2005
# Whom:                                 SeaD
#
# $FreeBSD$
#

PORTNAME=	ipguard
PORTVERSION=	0.04
CATEGORIES=	security net
MASTER_SITES=	http://ipguard.deep.perm.ru/files/

MAINTAINER=	sead@mail.ru
COMMENT=	Tool designed to protect LAN IP adress space by ARP spoofing

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

MAN8=		ipguard.8

ETHERS?=	/etc/ethers

MAKE_ARGS+=	ETHERS=${ETHERS}

SUB_FILES=	pkg-message
SUB_LIST=	ETHERS=${ETHERS}
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipguard ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/doc/ipguard.8 ${MANPREFIX}/man/man8
	${INSTALL_SCRIPT} ${WRKSRC}/doc/ipguard.sh.sample ${PREFIX}/etc/rc.d

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
