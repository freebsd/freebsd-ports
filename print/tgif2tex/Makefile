# New ports collection makefile for:	tgif2tex
# Date created:		12 Mar 1998
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tgif2tex
PORTVERSION=	2.05
CATEGORIES+=	print
MASTER_SITES=	http://www.jaist.ac.jp/~knakano/tgif2tex/

MAINTAINER=	taoka@FreeBSD.org

USE_PERL5=	yes

PORTSDOCDIR?=	${PREFIX}/share/doc/tgif2tex
DOCSRC+=	example.obj \
		example.tex

do-build:
	@cd ${WRKSRC}; ${MV} tgif2tex tgif2tex.org; \
	${SED}	-e 's,/usr/local/X11R6/bin/tgif,${X11BASE}/bin/tgif,' \
		-e 's;^#! */usr/bin/perl *;#!${PERL5};' \
		-e 's,/usr/local,${PREFIX},' \
			tgif2tex.org > tgif2tex

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tgif2tex ${PREFIX}/bin/tgif2tex
.if !defined(NOPORTDOCS)
	${MKDIR} ${PORTSDOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${DOCSRC} ${PORTSDOCDIR};
	${INSTALL_DATA} ${FILESDIR}/00readme ${PORTSDOCDIR}
.endif

.include <bsd.port.mk>
