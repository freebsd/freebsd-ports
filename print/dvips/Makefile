# New ports collection makefile for:    dvips
# Version required:     5.74
# Date created:         30 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.16 1997/08/25 01:29:40 jmz Exp $
#

DISTNAME=	dvips574
PKGNAME=	dvips-5.74
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tex.ac.uk/tex-archive/dviware/dvips/

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/dvips574/dvips
IS_INTERACTIVE=	yes
MAN1=		dvips.1 afm2tfm.1

pre-install:
	@${MKDIR} ${PREFIX}/share/texmf

post-install:
	@${MKDIR} ${PREFIX}/share/texmf/fonts/vf  ${PREFIX}/share/texmf/fonts/tfm  ${PREFIX}/share/texmf/tex/latex
	@install -c  -m 644 ${WRKDIR}/dvips574/dvips/*.sty ${PREFIX}/share/texmf/tex/latex
	@install -c  -m 644 ${WRKDIR}/dvips574/PSlatex/*.sty ${PREFIX}/share/texmf/tex/latex
	@install -c  -m 644 ${WRKDIR}/dvips574/PStfms/*.tfm ${PREFIX}/share/texmf/fonts/tfm
	@install -c  -m 644 ${WRKDIR}/dvips574/PSvfs/*.vf ${PREFIX}/share/texmf/fonts/vf

pre-clean:
	@rm -f ${SCRIPTDIR}/post-install

.include <bsd.port.mk>
