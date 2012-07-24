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
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://ftp.cerias.purdue.edu/pub/tools/unix/scanners/queso/ \
		http://www.mirrors.wiretapped.net/security/network-mapping/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Determine the remote OS using simple TCP packets

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} 's,$(CFGDIR)/queso.conf,$(CFGDIR)/queso.conf.sample,' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
