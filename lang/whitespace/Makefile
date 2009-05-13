# New ports collection makefile for:	whitespace
# Date created:        18 May 2006
# Whom:                Li-Lun Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	whitespace
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://compsoc.dur.ac.uk/whitespace/downloads/
DISTNAME=	wspace-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	llwang@infor.org
COMMENT=	An interpreter for the Whitespace programming language

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

WRKSRC=	${WRKDIR}/WSpace
USE_GMAKE=	yes
ALL_TARGET=	${TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wspace ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/tutorial.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
