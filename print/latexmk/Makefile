# ex:ts=8
# New ports collection makefile for:	latexmk
# Date created:				17 Dec 2004
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	latexmk
PORTVERSION=	307a
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
PORTDOCS=	CHANGES INSTALL README latexmk.pdf latexmk.ps latexmk.txt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/latexmk.pl ${PREFIX}/bin/latexmk
	${INSTALL_MAN} ${WRKSRC}/latexmk.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
