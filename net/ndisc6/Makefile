# New ports collection makefile for:	ndisc6
# Date created:		12 July 2006
# Whom:			rdenis@simphalempin.com
#
# $FreeBSD$
#

PORTNAME=	ndisc6
PORTVERSION=	0.7.2
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.remlab.net/files/ndisc6/archive/ \
		http://people.via.ecp.fr/~rem/www.remlab.net/files/ndisc6/archive/

MAINTAINER=	rdenis@simphalempin.com
COMMENT=	IPv6 network diagnostic tools

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-suid-install

MAN1=		tcpspray6.1 addrinfo.1 dnssort.1
MAN8=		ndisc6.8 rdisc6.8 rltraceroute6.8
MLINKS=		rltraceroute6.8 tcptraceroute6.8 \
		rltraceroute6.8 tracert6.8 \
		addrinfo.1 nameinfo.1

PORTDOCS=	AUTHORS NEWS README

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
