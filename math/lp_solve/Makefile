# New ports collection makefile for:	lp_solve
# Date created:         31 June 2003
# Whom:			Pedro F. Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	lp_solve
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	# none
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linear Programming Solver

USE_BISON=	yes

MAN1=		lp_solve.1

USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,%%CC%%,${CC},g ; \
	s,%%CFLAGS%%,${CFLAGS},g'  ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lp_solve ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lp2mps ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mps2lp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lp_solve.1 ${PREFIX}/man/man1
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	${CP} $(WRKSRC)/HARTMUT_DOCUMENTATION ${DOCSDIR}
	${CP} $(WRKSRC)/MPS.description ${DOCSDIR}
	${CP} $(WRKSRC)/*.pdf ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/demo ${EXAMPLESDIR}
	${CP} -R $(WRKSRC)/lp_examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
