# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	latexmk
PORTVERSION=	435
CATEGORIES=	print
MASTER_SITES=	http://users.phys.psu.edu/~collins/software/latexmk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to completely automate generating output from LaTeX documents

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USES=		perl5 zip
USE_PERL5=	run
USE_TEX=	latex

MAN1=		latexmk.1
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/latexmk

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} latexmk.pl ${PREFIX}/bin/latexmk)
	(cd ${WRKSRC} && ${INSTALL_MAN} latexmk.1 ${MANPREFIX}/man/man1)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in CHANGES INSTALL README latexmk.pdf latexmk.ps latexmk.txt
	(cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${DOCSDIR})
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} example_rcfiles ${EXAMPLESDIR})
	@(cd ${WRKSRC} && ${COPYTREE_BIN} extra-scripts ${EXAMPLESDIR})
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
