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
MASTER_SITES=	ftp://ftp.ee.lbl.gov/  \
		${MASTER_SITE_SUNSITE} \
		ftp://freebsd.ntu.edu.tw/freebsd/_distfiles/
MASTER_SITE_SUBDIR=	distributions/trinux/src/netmap

MAINTAINER=	obrien@FreeBSD.org

GNU_CONFIGURE=  yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300004
DISTFILES=	queso-980922.tar.gz libpcap-0.4.tar.Z
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
