# New ports collection makefile for:	bpft
# Version required:     2.0
# Date created:         17 March 1999
# Whom:                 oddbjorn@tricknology.org
#
# $FreeBSD$
#

DISTNAME=	bpft-2.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nsk.su/pub/unix/
EXTRACT_SUFX=	.tgz

MAINTAINER=	oddbjorn@tricknology.org

MAN1=		trafshow.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/bpft
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/bpft/README
.endif

.include <bsd.port.mk>
