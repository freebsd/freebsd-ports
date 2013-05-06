# New ports collection makefile for:	abntex
# Date created:	Tue Sep 17 22:08:35 BRT 2002
# Whom:		Hammurabi Mendes <hmendes@brturbo.com>
#
# $FreeBSD$
#

PORTNAME=	abntex
PORTVERSION=	0.8.2
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://codigolivre.org.br/frs/download.php/2654/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Both classes and styles for both LaTex and bibtex for ABNT rules

USE_TEX=	tetex
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

NO_BUILD=	yes

do-install:
# install files
	${INSTALL_SCRIPT} ${WRKSRC}/bin/geratss ${PREFIX}/bin
.for dir in bibtex/bib bibtex/bst doc/bibtex doc/latex makeindex tex/latex
	@${MKDIR} ${PREFIX}/share/texmf/${dir}
	${TAR} -C ${WRKSRC}/texmf/${dir} --exclude ".*" --exclude "*~" \
		-cf - abntex | ${TAR} -C ${PREFIX}/share/texmf/${dir} -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/texmf/${dir}
.endfor
# inform tex about installation
	@${LOCALBASE}/bin/texhash

.include <bsd.port.mk>
