# ex:ts=8
# Ports collection makefile for:  Queso
# Version required:		  980922
# Date created:			  13 Oct 1998
# Whom:				  Wu Ching-hong <woju@freebsd.ee.ntu.edu.tw>
# 				  and David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.1.1.1 1998/10/24 23:31:27 obrien Exp $
#

DISTNAME=	queso-980922
CATEGORIES=	net security
MASTER_SITES=	ftp://apostols.org/AposTools/snapshots/  \
		ftp://ftp.ee.lbl.gov/  \
		ftp://freebsd.ntu.edu.tw/freebsd/_distfiles/
DISTFILES=	queso-980922.tar.gz

MAINTAINER=	woju@freebsd.ee.ntu.edu.tw

GNU_CONFIGURE=  yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300004
DISTFILES+=	libpcap-0.4.tar.Z
post-patch:
	@cd ${WRKSRC}/../libpcap-0.4/; ./configure; make
.endif

post-install:
	#${INSTALL_PROGRAM} ${WRKSRC}/queso ${PREFIX}/sbin
	#${INSTALL_DATA} ${WRKSRC}/queso.conf ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/queso
	${INSTALL_DATA} ${WRKSRC}/Documentation.txt ${PREFIX}/share/doc/queso
.endif

.include <bsd.port.post.mk>
