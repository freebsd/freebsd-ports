# Created by: David O'Brien (obrien@NUXI.com)

PORTNAME=	detex
PORTVERSION=	2.8
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.cs.purdue.edu/homes/trinkle/detex/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Strips TeX/LaTeX codes from a file

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		tar
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DNO_MALLOC_DECL -DHAVE_STRING_H"

CONFLICTS_INSTALL=	texlive-base # bin/detex

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-extract:
	@(cd ${WRKSRC} && ${MV} ${PORTNAME}.1l ${PORTNAME}.1)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
