# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	latexmk
PORTVERSION=	435
CATEGORIES=	print
MASTER_SITES=	http://users.phys.psu.edu/~collins/software/latexmk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to completely automate generating output from LaTeX documents

LICENSE=	GPLv2 # (or later)

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USES=		perl5 zip
USE_PERL5=	run
USE_TEX=	latex

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/latexmk man/man1/latexmk.1.gz

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} latexmk.pl \
		${STAGEDIR}${PREFIX}/bin/latexmk)
	(cd ${WRKSRC} && ${INSTALL_MAN} latexmk.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in CHANGES INSTALL README latexmk.pdf latexmk.ps latexmk.txt
	(cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${STAGEDIR}${DOCSDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} example_rcfiles \
		${STAGEDIR}${EXAMPLESDIR})
	@(cd ${WRKSRC} && ${COPYTREE_BIN} extra-scripts \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
