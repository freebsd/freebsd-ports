# Ports collection makefile for:  libnet
# Version required:		0.10a
# Date created:			Sun Feb 3, 1999
# Whom:				shipley@dis.org
#
# $FreeBSD$
#

DISTNAME=	libnet-0.10a
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

WRKSRC=         ${WRKDIR}/Libnet

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/libnet
	${INSTALL_MAN} ${WRKSRC}/doc/PORTS ${PREFIX}/share/doc/libnet
	${INSTALL_MAN} ${WRKSRC}/doc/README ${PREFIX}/share/doc/libnet
	${INSTALL_MAN} ${WRKSRC}/doc/README.bpf ${PREFIX}/share/doc/libnet
.endif

.include <bsd.port.post.mk>
