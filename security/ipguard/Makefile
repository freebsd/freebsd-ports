# Created by: SeaD
# $FreeBSD$

PORTNAME=	ipguard
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://ipguard.deep.perm.ru/files/ http://deep.perm.ru/files/ipguard/

MAINTAINER=	sead@deep.perm.ru
COMMENT=	Tool designed to protect LAN IP address space by ARP spoofing

LIB_DEPENDS=	net:${PORTSDIR}/net/libnet

USE_RC_SUBR=	${PORTNAME}
MAN8=		${PORTNAME}.8
PORTDOCS=	COPYRIGHT NEWS README README.tcpdump README.log ethers.sample rfc826.txt
PLIST_FILES=	sbin/ipguard

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
