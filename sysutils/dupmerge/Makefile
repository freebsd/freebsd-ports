# $FreeBSD$

PORTNAME=	dupmerge
PORTVERSION=	1.73
CATEGORIES=	sysutils
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Searches for files with equal content

USES=		zip
MAKE_FLAGS=
MAKEFILE=
LDFLAGS+=	-lroken -lcrypt
ALL_TARGET=	dupmerge
PLIST_FILES=	bin/dupmerge
PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dupmerge ${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
