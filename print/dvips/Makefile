# New ports collection makefile for:    dvips
# Version required:     5.76
# Date created:         30 September 1994
# Whom:                 jmz
#
# $FreeBSD$
#

DISTNAME=	dvips576
PKGNAME=	dvips-5.76
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tex.ac.uk/tex-archive/dviware/dvips/

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/dvips576/dvips
IS_INTERACTIVE=	yes
MAN1=		dvips.1 afm2tfm.1

pre-install:
	@${MKDIR} ${PREFIX}/share/texmf

post-install:
	@${MKDIR} ${PREFIX}/share/texmf/fonts/vf  ${PREFIX}/share/texmf/fonts/tfm  ${PREFIX}/share/texmf/tex/latex
	@install -c  -m 644 ${WRKDIR}/dvips576/dvips/*.sty ${PREFIX}/share/texmf/tex/latex
	@install -c  -m 644 ${WRKDIR}/dvips576/PSlatex/*.sty ${PREFIX}/share/texmf/tex/latex
	@install -c  -m 644 ${WRKDIR}/dvips576/PStfms/*.tfm ${PREFIX}/share/texmf/fonts/tfm
	@install -c  -m 644 ${WRKDIR}/dvips576/PSvfs/*.vf ${PREFIX}/share/texmf/fonts/vf

pre-clean:
	@${RM} -f ${SCRIPTDIR}/post-install

.include <bsd.port.mk>
