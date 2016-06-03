# Created by: Anton Berezin <tobez@plab.ku.dk>
# $FreeBSD$

PORTNAME=	dcdflib.c
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://odin.mda.uth.tmc.edu/pub/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of C Routines for Cumulative Distribution Functions

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

WRKSRC=		${WRKDIR}/dcdflib.c/src
USES=		uidfix
USE_LDCONFIG=	yes
MAKEFILE=	${FILESDIR}/Makefile.lib
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/.c//}
OPTIONS_DEFINE= DOCS

.if defined(NO_PROFILE)
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../doc/dcdflib.chs ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../doc/dcdflib.fdoc ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
