# Ports collection makefile for:  libnet
# Date created:			Sun Feb 3, 1999
# Whom:				shipley@dis.org
#
# $FreeBSD$
#

PORTNAME=	libnet
PORTVERSION=	1.0.1b
CATEGORIES=	net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/

MAINTAINER=	shipley@dis.org

MAN3=		libnet.3

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/Libnet-${PORTVERSION}
MAN3=		libnet.3

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/libnet.3 ${PREFIX}/man/man3
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/libnet
	@${MKDIR} ${PREFIX}/share/doc/libnet/html
	@${MKDIR} ${PREFIX}/share/doc/libnet/html/examples
.for i in CHANGELOG CHANGELOG-NEWFUNCTIONS COPYING README README.asn.1 README.bpf README.legacy-applications README.libnet-config README.linux README.rawsockets TODO-1.0 TODO-1.1
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/libnet
.endfor
.for i in 1.html 2.html 3.html 4.html 5.html 6.html 7.html contrib.html fig-3a.gif figure-1.gif figure-2.gif figure-3.gif figure-3a.gif lrm.html
	${INSTALL_DATA} ${WRKSRC}/doc/html/${i} ${PREFIX}/share/doc/libnet/html
.endfor
.for i in libnet-example-1.c libnet-example-2.c libnet-example-3.c libnet-example-4.c
	${INSTALL_DATA} ${WRKSRC}/doc/html/examples/${i} ${PREFIX}/share/doc/libnet/html/examples
.endfor
.endif

.include <bsd.port.mk>
