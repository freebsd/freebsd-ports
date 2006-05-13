# New ports collection makefile for:	tgif2tex
# Date created:		12 Mar 1998
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tgif2tex
PORTVERSION=	2.13
PORTREVISION=	1
CATEGORIES+=	print
MASTER_SITES=	http://www.fse.hiroshima-u.ac.jp/~nakano/tgif2tex/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Converting texts in figure by tgif to LaTeX commands

USE_PERL5_RUN=	yes

DOCSRC=		how-to-use.aux how-to-use.dvi \
		how-to-use.log how-to-use.ps how-to-use.tex \
		example.obj example.tex \
		original.dps original.tps \
		pythagoras.dps pythagoras.tps \
		sample1.obj sample1.ps \
		sample2.1.dps sample2.1.tps \
		sample2.2.dps sample2.2.tps \
		sample2.3.dps sample2.3.tps \
		sample2.aux sample2.dvi sample2.log \
		sample2.tex sample2.obj sample2.ps

do-build:
	${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE}," \
		-e "s,%%X11BASE%%,${X11BASE}," \
		${WRKSRC}/tgif2tex

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tgif2tex ${PREFIX}/bin/tgif2tex
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${DOCSRC} ${DOCSDIR};
	${INSTALL_DATA} ${FILESDIR}/00readme ${DOCSDIR}
.endif

.include <bsd.port.mk>
