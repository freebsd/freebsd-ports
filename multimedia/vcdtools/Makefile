# ex:ts=8
# New ports collection makefile for:	vcdtools
# Date created:	 	Mar 9, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vcdtools
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.debian.org/debian/pool/main/v/vcdtools/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Create your own VCD

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mkvcdfs ${WRKSRC}/vcdmplex ${PREFIX}/bin
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${DOCSDIR}
.endif

.include <bsd.port.mk>
