# Created by: andrewb@cs.cmu.edu
# $FreeBSD$

PORTNAME=	twelf
PORTVERSION=	1.7.1
DISTVERSIONPREFIX=	src-
CATEGORIES=	lang math
MASTER_SITES=	http://twelf.plparty.org/releases/ \
		http://www-2.cs.cmu.edu/~twelf/dist/ http://www.cs.cmu.edu/~twelf/dist/

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Meta-logical framework for deductive systems

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	mlton:lang/mlton
BUILD_DEPENDS=	mlton:lang/mlton \
		texi2html:textproc/texi2html

OPTIONS_DEFINE=	DOCS

USES=		gmake
ALL_TARGET=	mlton
PLIST_FILES=	bin/${PORTNAME}-server
PORTDATA=	emacs examples examples-clp examples-delphin tex vim README
PORTDOCS=	dvi html info pdf ps
WRKSRC=		${WRKDIR}/twelf
INFO=		twelf

DOCS_USE=	TEX=dvipsk:build,tex:build
DOCS_USES=	makeinfo

post-patch-DOCS-on:
	@${REINPLACE_CMD} 's|-number|-number-sections|g' \
		${WRKSRC}/doc/guide/Makefile
	@${REINPLACE_CMD} 's|twelf_\*.html|twelf/\*.html|g' \
		${WRKSRC}/doc/guide/Makefile

post-build-DOCS-on:
	cd ${WRKSRC}/doc/guide && ${MAKE} all ${INSTALL_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME}-server \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
