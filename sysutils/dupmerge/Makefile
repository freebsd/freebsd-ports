# $FreeBSD$

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
ALL_TARGET=	dupmerge
PLIST_FILES=	bin/dupmerge
PORTDOCS=	readme.txt

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dupmerge ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
