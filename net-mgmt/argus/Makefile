# New ports collection makefile for:	argus
# Date created:		26 November 1998
# Whom:			Jonathan Hanna <jhanna@home.com>
#
# $FreeBSD$
#

PORTNAME=	argus
PORTVERSION=	1.8.1
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/argus/current/

MAINTAINER=	se@freebsd.org

.if !exists(/usr/include/tcpd.h)
LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

GNU_CONFIGURE=	true

MAN1=	connections.1 ra.1 rasort.1 services.1
MAN5=	argus.5
MAN8=	argus.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/argus_bpf ${PREFIX}/bin/argus
.for i in fullra ra radjacency raconnections racount radnstats raservices rasort
	${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${PREFIX}/bin
.endfor
.for i in connections.1 ra.1 rasort.1 services.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/$i ${PREFIX}/man/man1
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/man5/argus.5 ${PREFIX}/man/man5/argus.5
	${INSTALL_MAN} ${WRKSRC}/man/man8/argus.8 ${PREFIX}/man/man8/argus.8
	${INSTALL_DATA} ${WRKSRC}/include/cons_def.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/cons_out.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/argus
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/argus/README.argus
.for i in CA-95.01 CA-95.01.scan.sh README configs dailyscan.sh policy.conf policy.test ra.conf services
	${INSTALL_DATA} ${WRKSRC}/examples/$i ${PREFIX}/share/doc/argus
.endfor
.endif

.include <bsd.port.mk>
