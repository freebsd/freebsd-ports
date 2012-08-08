# New ports collection makefile for:	whitespace
# Date created:        18 May 2006
# Whom:                Li-Lun Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	whitespace
PORTVERSION=	0.3
PORTREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	http://compsoc.dur.ac.uk/whitespace/downloads/
DISTNAME=	wspace-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	llwang@infor.org
COMMENT=	An interpreter for the Whitespace programming language

LICENSE=	GPLv2

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp
USE_PERL5_BUILD=	5.8+

WRKSRC=	${WRKDIR}/WSpace
USE_GMAKE=	yes
ALL_TARGET=	${TARGET}

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	DOCS EXAMPLES

PORTEXAMPLES=		*
PORTDOCS=		*

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wspace ${PREFIX}/bin

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/tutorial.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
