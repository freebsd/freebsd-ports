# Created by: andrewb@cs.cmu.edu
# $FreeBSD$

PORTNAME=	twelf
PORTVERSION=	1.7.1
CATEGORIES=	lang math
MASTER_SITES=	http://twelf.plparty.org/releases/ \
	http://www-2.cs.cmu.edu/~twelf/dist/ http://www.cs.cmu.edu/~twelf/dist/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Meta-logical framework for deductive systems

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	mlton:lang/mlton
BUILD_DEPENDS=	mlton:lang/mlton \
		texi2html:textproc/texi2html

USES=	gmake
ALL_TARGET=	mlton
PLIST_FILES=	bin/${PORTNAME}-server
PORTDATA=	emacs examples examples-clp examples-delphin tex vim README
PORTDOCS=	dvi html info pdf ps

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
USE_TEX=	tex:build dvipsk:build
BUILD_DEPENDS+=	${LOCALBASE}/bin/makeinfo:print/texinfo
.endif

post-patch:
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} 's|-number|-number-sections|g' \
		${WRKSRC}/doc/guide/Makefile
	@${REINPLACE_CMD} 's|twelf_\*.html|twelf/\*.html|g' \
		${WRKSRC}/doc/guide/Makefile
.endif

post-build:
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/doc/guide && ${MAKE} all ${INSTALL_TARGET}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME}-server \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}
.endif

WRKSRC=		${WRKDIR}/twelf
INFO=		twelf

.include <bsd.port.mk>
