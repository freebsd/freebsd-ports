# New ports collection makefile for:	tgif2tex
# Version required:	1.46
# Date created:		12 Mar 1998
# Whom:			Satoshi TAOKA <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id$
#

DISTNAME=	tgif2tex
PKGNAME?=	tgif2tex-1.46
CATEGORIES=	print
MASTER_SITES=	http://camphor.elcom.nitech.ac.jp/~nakano/tgif2tex/

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

USE_PERL5=	yes

PORTSDOCDIR?=	${PREFIX}/share/doc/tgif2tex
DOCSRC+=	example.obj \
		example.tex

do-build:
	@cd ${WRKSRC}; ${MV} tgif2tex tgif2tex.org; \
	${SED} -e 's,/usr/local/X11R6/bin/tgif,${X11BASE}/bin/tgif,' \
		-e 's;^#! */usr/local/bin/perl *;#!${PERL5};' \
			tgif2tex.org > tgif2tex

pre-install:
	@if [ ${PREFIX} != "/usr/local" ]; then \
	    ${SED} s,/usr/local,${PREFIX}, ${WRKSRC}/tgif2tex \
			> ${WRKSRC}/tgif2tex.org; \
	    ${MV} ${WRKSRC}/tgif2tex.org ${WRKSRC}/tgif2tex; \
	fi

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tgif2tex ${PREFIX}/bin/tgif2tex
.if !defined(NOPORTDOCS)
	${MKDIR} ${PORTSDOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${DOCSRC} ${PORTSDOCDIR};
	${INSTALL_DATA} ${FILESDIR}/00readme ${PORTSDOCDIR}
.endif

.include <bsd.port.mk>
