# Ports collection makefile for:  libnet
# Date created:			Sun Feb 3, 1999
# Whom:				shipley@dis.org
#
# $FreeBSD$
#

PORTNAME=	libnet
PORTVERSION=	0.99g
CATEGORIES=     net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	shipley@dis.org

MAN3=		libnet.3

GNU_CONFIGURE=	yes

#NOPROFILE=	true

.include <bsd.port.pre.mk>
.if ${OSVERSION} <= 300000
BROKEN=         does not build
.endif

WRKSRC=         ${WRKDIR}/Libnet-0.99g

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/libnet
	${INSTALL_MAN} ${WRKSRC}/doc/PORTS ${PREFIX}/share/doc/libnet
	${INSTALL_MAN} ${WRKSRC}/doc/README ${PREFIX}/share/doc/libnet
	${INSTALL_MAN} ${WRKSRC}/doc/README.bpf ${PREFIX}/share/doc/libnet
	${INSTALL_MAN} ${WRKSRC}/doc/README.asn.1 ${PREFIX}/share/doc/libnet
	${INSTALL_MAN} ${WRKSRC}/doc/README.bpf ${PREFIX}/share/doc/libnet
	${INSTALL_MAN} ${WRKSRC}/doc/README.examples ${PREFIX}/share/doc/libnet
	${INSTALL_MAN} ${WRKSRC}/doc/README.linux ${PREFIX}/share/doc/libnet
	${INSTALL_MAN} ${WRKSRC}/doc/README.rawsockets ${PREFIX}/share/doc/libnet
	${INSTALL_MAN} ${WRKSRC}/doc/README.stubs ${PREFIX}/share/doc/libnet
.endif

.include <bsd.port.post.mk>
