# New ports collection makefile for:	argus
# Version required:	1.7.beta.1e
# Date created:		26 November 1998
# Whom:			Jonathan Hanna <jhanna@home.com>
#
# $Id: Makefile,v 1.2 1998/12/05 17:58:00 flathill Exp $
#

DISTNAME=	argus-1.7.beta.1e
PKGNAME=	argus-1.7.b.1e
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.sei.cmu.edu/pub/argus-1.5/argus-1.7/

MAINTAINER=	jhanna@home.com

LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper

HAS_CONFIGURE=	true
CONFIGURE_ARGS=	--with-pcap=bpf

MAN1=	connections.1 ra.1 rasort.1 services.1
MAN5=	argus.5
MAN8=	argus.8

do-install:
.for i in adjacency argus_bpf connections dnstats ra raservices rasort
	${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${PREFIX}/bin
.endfor
	${MV} ${PREFIX}/bin/argus_bpf ${PREFIX}/bin/argus
.for i in connections.1 ra.1 rasort.1 services.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/$i ${PREFIX}/man/man1
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/man5/argus.5 ${PREFIX}/man/man5/argus.5
	${INSTALL_MAN} ${WRKSRC}/man/man8/argus.8 ${PREFIX}/man/man8/argus.8
	${INSTALL_DATA} ${WRKSRC}/include/cons_def.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/cons_out.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/argus
.for i in CA-95.01 CA-95.01.scan.sh README configs dailyscan.sh policy.conf policy.test ra.conf services
	${INSTALL_DATA} ${WRKSRC}/examples/$i ${PREFIX}/share/doc/argus
.endfor
.endif

.include <bsd.port.mk>
