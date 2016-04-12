# Created by: SeaD
# $FreeBSD$

PORTNAME=	ipguard
PORTVERSION=	1.04
PORTREVISION=	2
CATEGORIES=	security net
MASTER_SITES=	http://ipguard.deep.perm.ru/files/ http://deep.perm.ru/files/ipguard/

MAINTAINER=	sead@deep.perm.ru
COMMENT=	Tool designed to protect LAN IP address space by ARP spoofing

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libnet.so:net/libnet

USE_RC_SUBR=	${PORTNAME}
PORTDOCS=	COPYRIGHT NEWS README README.tcpdump README.log ethers.sample rfc826.txt
PLIST_FILES=	sbin/ipguard \
		man/man8/${PORTNAME}.8.gz

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
