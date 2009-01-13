# New ports collection makefile for:    dupmerge
# Date created:         12 Jan 2009
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	dupmerge
PORTVERSION=	1.73
CATEGORIES=	sysutils
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Searches for files with equal content

USE_ZIP=	yes
MAKE_FLAGS=
MAKEFILE=
LDFLAGS+=	-lroken -lcrypt
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"
ALL_TARGET=	dupmerge
PLIST_FILES=	bin/dupmerge
PORTDOCS=	readme.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dupmerge ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
