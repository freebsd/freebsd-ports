# New ports collection makefile for:    dvips
# Date created:         30 September 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	dvips
PORTVERSION=	5.76
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmz
DISTNAME=	dvips576

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	Convert a TeX DVI file to PostScript

CONFLICTS=	*teTeX*

WRKSRC=		${WRKDIR}/dvips576/dvips
IS_INTERACTIVE=	yes
MAN1=		dvips.1 afm2tfm.1

pre-install:
	@${MKDIR} ${PREFIX}/share/texmf

post-install:
	@${MKDIR} ${PREFIX}/share/texmf/fonts/vf  ${PREFIX}/share/texmf/fonts/tfm  ${PREFIX}/share/texmf/tex/latex
	@${INSTALL_DATA} ${WRKDIR}/dvips576/dvips/*.sty ${PREFIX}/share/texmf/tex/latex
	@${INSTALL_DATA} ${WRKDIR}/dvips576/PSlatex/*.sty ${PREFIX}/share/texmf/tex/latex
	@${INSTALL_DATA} ${WRKDIR}/dvips576/PStfms/*.tfm ${PREFIX}/share/texmf/fonts/tfm
	@${INSTALL_DATA} ${WRKDIR}/dvips576/PSvfs/*.vf ${PREFIX}/share/texmf/fonts/vf
	@if [ -f ${WRKDIR}/post-install ]; then ${SH} ${WRKDIR}/post-install; fi

pre-clean:
	@${RM} -f ${WRKDIR}/post-install

.include <bsd.port.mk>
