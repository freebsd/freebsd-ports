# $FreeBSD$

PORTNAME=	dupmerge
PORTVERSION=	1.73
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Searches for files with equal content

USES=		zip
MAKE_FLAGS=	# empty
MAKEFILE=	# empty
ALL_TARGET=	dupmerge
PLIST_FILES=	bin/dupmerge
PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dupmerge ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
