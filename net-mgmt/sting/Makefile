# New ports collection makefile for:	sting
# Date created:				10 May 2000
# Whom:					benno@netizen.com.au
#
# $FreeBSD$
#

PORTNAME=	sting
PORTVERSION=	0.7
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.cs.washington.edu/homes/savage/sting/
DISTNAME=	sting

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool that measures end-to-end TCP connection characteristics

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113 || defined(IPFW2)
BROKEN=		"Does not work with ipfw2"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sting ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.sting
.endif

.include <bsd.port.post.mk>
