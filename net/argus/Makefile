# New ports collection makefile for:	argus
# Version required:	argus-1.7.beta.1e
# Date created:		26 November 1998
# Whom:			Jonathan Hanna <jhanna@home.com>
#
# $Id:$
#

DISTNAME=	argus-1.7.beta.1e
PKGNAME=	argus-1.7.b.1e
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.sei.cmu.edu/pub/argus-1.5/argus-1.7/

MAINTAINER=	jhanna@home.com

LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper

HAS_CONFIGURE=	true

MAN1=	connections.1 ra.1 rasort.1 services.1
MAN5=	argus.5
MAN8=	argus.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/adjacency ${PREFIX}/bin/adjacency
	${INSTALL_PROGRAM} ${WRKSRC}/bin/argus_bpf ${PREFIX}/bin/argus
	${INSTALL_PROGRAM} ${WRKSRC}/bin/connections ${PREFIX}/bin/connections
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dnstats ${PREFIX}/bin/dnstats
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ra ${PREFIX}/bin/ra
	${INSTALL_PROGRAM} ${WRKSRC}/bin/raservices ${PREFIX}/bin/raservices
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rasort ${PREFIX}/bin/rasort
	${INSTALL_MAN} ${WRKSRC}/man/man1/connections.1 ${PREFIX}/man/man1/connections.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/ra.1 ${PREFIX}/man/man1/ra.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/rasort.1 ${PREFIX}/man/man1/rasort.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/services.1 ${PREFIX}/man/man1/services.1
	${INSTALL_MAN} ${WRKSRC}/man/man5/argus.5 ${PREFIX}/man/man5/argus.5
	${INSTALL_MAN} ${WRKSRC}/man/man8/argus.8 ${PREFIX}/man/man8/argus.8
	${INSTALL_DATA} ${WRKSRC}/include/cons_def.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/cons_out.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/argus
	${INSTALL_DATA} ${WRKSRC}/examples/CA-95.01 ${PREFIX}/share/doc/argus
	${INSTALL_DATA} ${WRKSRC}/examples/CA-95.01.scan.sh ${PREFIX}/share/doc/argus
	${INSTALL_DATA} ${WRKSRC}/examples/README ${PREFIX}/share/doc/argus
	${INSTALL_DATA} ${WRKSRC}/examples/configs ${PREFIX}/share/doc/argus
	${INSTALL_DATA} ${WRKSRC}/examples/dailyscan.sh ${PREFIX}/share/doc/argus
	${INSTALL_DATA} ${WRKSRC}/examples/policy.conf ${PREFIX}/share/doc/argus
	${INSTALL_DATA} ${WRKSRC}/examples/policy.test ${PREFIX}/share/doc/argus
	${INSTALL_DATA} ${WRKSRC}/examples/ra.conf ${PREFIX}/share/doc/argus
	${INSTALL_DATA} ${WRKSRC}/examples/services ${PREFIX}/share/doc/argus
.endif

.include <bsd.port.mk>
