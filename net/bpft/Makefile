# New ports collection makefile for:	bpft
# Date created:         17 March 1999
# Whom:                 oddbjorn@tricknology.org
#
# $FreeBSD$
#

PORTNAME=	bpft
PORTVERSION=	2.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nsk.su/pub/unix/
EXTRACT_SUFX=	.tgz

MAINTAINER=	oddbjorn@tricknology.org

MAN1=		trafshow2.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/bpft
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/bpft/README
.endif

.include <bsd.port.mk>
