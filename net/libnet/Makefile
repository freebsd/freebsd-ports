# Ports collection makefile for:  libnet
# Date created:			Sun Feb 3, 1999
# Whom:				shipley@dis.org
#
# $FreeBSD$
#

PORTNAME=	libnet
PORTVERSION=	1.1.0
CATEGORIES=	net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/

MAINTAINER=	shipley@dis.org
COMMENT=	A C library for creating IP packets

USE_AUTOMAKE=	yes
CONFIGURE_ENV=	ACLOCAL=${ACLOCAL}

WRKSRC=		${WRKDIR}/Libnet-latest
MAN3=		libnet.3

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/libnet
	@${MKDIR} ${PREFIX}/share/doc/libnet/ancillary
.for i in BUGS CHANGELOG DESIGN_NOTES MIGRATION PACKET_BUILDING PORTED RAWSOCKET_NON_SEQUITUR SUPPORTED_PROTOCOLS TODO
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/libnet
.endfor
.for i in README.asn.1 README.bpf README.legacy-applications README.libnet-config README.linux README.rawsockets
	${INSTALL_DATA} ${WRKSRC}/doc/Ancillary/${i} ${PREFIX}/share/doc/libnet/ancillary
.endfor
.endif

.include <bsd.port.mk>
