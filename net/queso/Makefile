# ex:ts=8
# Ports collection makefile for:  Queso
# Date created:			  13 Oct 1998
# Whom:				  Wu Ching-hong <woju@freebsd.ee.ntu.edu.tw>
# 				  and David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	queso
PORTVERSION=	980922
CATEGORIES=	net security
MASTER_SITES=	http://ftp.cerias.purdue.edu/pub/tools/unix/scanners/queso/ \
		http://www.mirrors.wiretapped.net/security/network-mapping/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Determine the remote OS using simple tcp packets

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300004
LIB_DEPENDS=	pcap.2:${PORTSDIR}/net/libpcap
.endif

post-install:
	#${INSTALL_PROGRAM} ${WRKSRC}/queso ${PREFIX}/sbin
	#${INSTALL_DATA} ${WRKSRC}/queso.conf ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/queso
	${INSTALL_DATA} ${WRKSRC}/Documentation.txt ${PREFIX}/share/doc/queso
.endif

.include <bsd.port.post.mk>
