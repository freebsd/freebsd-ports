# New ports collection makefile for:	gladtex
# Date created:		2006-02-04
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	gladtex
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	textproc math www
MASTER_SITES=	http://www.math.uio.no/~martingu/gladtex/dl/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A program to replace LaTeX formulas in HTML files with images

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		png.6:${PORTSDIR}/graphics/png
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		dvips:${PORTSDIR}/print/dvipsk-tetex

USE_PERL5_RUN=	yes

BINPATH=	${PREFIX}/bin
INCPATH=	-I${LOCALBASE}/include
LIBPATH=	-L${LOCALBASE}/lib

MAKE_ENV+=	BINPATH=${BINPATH} INCPATH=${INCPATH} LIBPATH=${LIBPATH}

DOCSFILES=	README

post-extract:
	@@cd ${WRKSRC};
	${RM} -f eqn2img

post-install:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}; \
	${MKDIR} ${DOCSDIR}; \
	${INSTALL_DATA} ${DOCSFILES} ${DOCSDIR}
.endif

.include <bsd.port.mk>
