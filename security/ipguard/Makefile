# Ports collection makefile for:        ipguard
# Date created:                         6 Oct 2008
# Whom:                                 SeaD
#
# $FreeBSD$
#

PORTNAME=	ipguard
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://ipguard.deep.perm.ru/files/ http://deep.perm.ru/files/ipguard/

MAINTAINER=	sead@deep.perm.ru
COMMENT=	Tool designed to protect LAN IP adress space by ARP spoofing

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet11/libnet.a:${PORTSDIR}/net/libnet

USE_RC_SUBR=	${PORTNAME}
MAN8=		${PORTNAME}.8
DOCS=		COPYRIGHT NEWS README README.tcpdump README.log ethers.sample rfc826.txt

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
