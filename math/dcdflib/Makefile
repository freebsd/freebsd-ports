# Created by: Anton Berezin <tobez@plab.ku.dk>
# $FreeBSD$

PORTNAME=	dcdflib.c
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://odin.mda.uth.tmc.edu/pub/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of C Routines for Cumulative Distribution Functions

WRKSRC=		${WRKDIR}/dcdflib.c/src
USE_LDCONFIG=	yes
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/.c//}
OPTIONS_DEFINE= DOCS

.if defined(NO_PROFILE)
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

post-extract:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../doc/dcdflib.chs ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../doc/dcdflib.fdoc ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
