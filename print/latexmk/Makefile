# ex:ts=8
# New ports collection makefile for:	latexmk
# Date created:				17 Dec 2004
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	latexmk
PORTVERSION=	431
CATEGORIES=	print
MASTER_SITES=	http://www.phys.psu.edu/~collins/software/latexmk/

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A tool to completely automate generating output from LaTeX documents

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

USE_PERL5_RUN=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

MAN1=		latexmk.1
PLIST_FILES=	bin/latexmk
PORTDOCS=	CHANGES COPYING INSTALL README latexmk.pdf latexmk.ps latexmk.txt
PORTEXAMPLES=	*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/latexmk.pl ${PREFIX}/bin/latexmk
	${INSTALL_MAN} ${WRKSRC}/latexmk.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	( cd ${WRKSRC} && ${COPYTREE_SHARE} example_rcfiles ${EXAMPLESDIR} )
	( cd ${WRKSRC} && ${COPYTREE_BIN} extra-scripts ${EXAMPLESDIR} )
.endif
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
