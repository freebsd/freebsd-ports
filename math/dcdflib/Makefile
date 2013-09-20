# Created by: Anton Berezin <tobez@plab.ku.dk>
# $FreeBSD$

PORTNAME=	dcdflib.c
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://odin.mda.uth.tmc.edu/pub/source/

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Library of C Routines for Cumulative Distribution Functions

WRKSRC=		${WRKDIR}/dcdflib.c/src

USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/.c//}

NO_STAGE=	yes
post-extract:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/dcdflib
	@${INSTALL_DATA} ${WRKSRC}/../doc/dcdflib.chs ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../doc/dcdflib.fdoc ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
.endif

.include <bsd.port.mk>
