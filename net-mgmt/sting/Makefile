# New ports collection makefile for:	sting
# Date created:				10 May 2000
# Whom:					benno@netizen.com.au
#
# $FreeBSD$
#

PORTNAME=	sting
PORTVERSION=	0.7
CATEGORIES=	net
MASTER_SITES=	http://www.cs.washington.edu/homes/savage/sting/
DISTNAME=	sting

MAINTAINER=	kbyanc@posi.net
COMMENT=	A tool that measures end-to-end TCP connection characteristics

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile"
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sting ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.sting
.endif

.include <bsd.port.post.mk>
