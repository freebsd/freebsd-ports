# New ports collection makefile for: pandoc
# Date created:                      9 February 2007
# Whom:                              John MacFarlane <jgm@berkeley.edu>
#
# $FreeBSD$
#

PORTNAME=	pandoc
PORTVERSION=	1.2.1
CATEGORIES=	textproc haskell
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	pgj@FreeBSD.org
COMMENT=	A general markup converter

BUILD_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc \
		hs-utf8-string-ghc>=0.3:${PORTSDIR}/devel/hs-utf8-string-ghc \
		hs-zip-archive-ghc>=0.1:${PORTSDIR}/archivers/hs-zip-archive-ghc

MANCOMPRESSED=	no
MAN1=		pandoc.1 markdown2pdf.1 html2markdown.1 hsmarkdown.1

USE_GMAKE=	yes
USE_PERL5=	yes

PLIST_FILES=	bin/pandoc bin/markdown2pdf bin/html2markdown bin/hsmarkdown
PORTDOCS=	BUGS README README.html
SCRIPTS=	hsmarkdown html2markdown markdown2pdf

OPTIONS=	HIGHLIGHTING "Syntax highlighting support" off

.include <bsd.port.pre.mk>

.if defined(WITH_HIGHLIGHTING)
BUILD_DEPENDS+=	hs-highlighting-kate-ghc>=0.2:${PORTSDIR}/textproc/hs-highlighting-kate-ghc
MAKE_ARGS=	CABALOPTS+="-fhighlighting"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/Text.Pandoc.TH,/Text.Pandoc.TH/; /Paths_pandoc/d' \
		${WRKSRC}/pandoc.cabal

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dist/build/pandoc/pandoc ${PREFIX}/bin
.for script in ${SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/${script} ${PREFIX}/bin
.endfor
.for man in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/man/man1/${man} ${PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
