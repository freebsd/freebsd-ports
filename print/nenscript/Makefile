# Created by: cjm2
# $FreeBSD$

PORTNAME=	nenscript
PORTVERSION=	1.13.3
CATEGORIES=	print
MASTER_SITES=	http://www.ai.mit.edu/projects/im/magnus/nenscript/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clone of the proprietary enscript program from Adobe Systems

USES=		tar:bzip2

MAKEFILE=	makefile
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nenscript ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nenscript.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
