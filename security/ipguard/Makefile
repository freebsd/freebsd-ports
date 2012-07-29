# Ports collection makefile for:        ipguard
# Date created:                         6 Oct 2008
# Whom:                                 SeaD
#
# $FreeBSD$
#

PORTNAME=	ipguard
PORTVERSION=	1.04
CATEGORIES=	security net
MASTER_SITES=	http://ipguard.deep.perm.ru/files/ http://deep.perm.ru/files/ipguard/

MAINTAINER=	sead@deep.perm.ru
COMMENT=	Tool designed to protect LAN IP address space by ARP spoofing

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet11/libnet.a:${PORTSDIR}/net/libnet

USE_RC_SUBR=	${PORTNAME}
MAN8=		${PORTNAME}.8
PORTDOCS=	COPYRIGHT NEWS README README.tcpdump README.log ethers.sample rfc826.txt
PLIST_FILES=	sbin/ipguard

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
