# New ports collection makefile for:    dvips
# Version required:     5.62
# Date created:         30 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.13 1996/11/18 14:11:09 asami Exp $
#

DISTNAME=	dvips562
PKGNAME=	dvips-5.62
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tex.ac.uk/tex-archive/dviware/dvips/

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/dvips562/dvips
IS_INTERACTIVE=	yes
MAN1=		dvips.1 afm2tfm.1

pre-install:
	@${MKDIR} ${PREFIX}/lib/texmf

post-install:
	@${MKDIR} ${PREFIX}/lib/texmf/fonts/vf
	@install -c  -m 644 ${WRKDIR}/dvips562/PSlatex/*.sty ${PREFIX}/lib/texmf/tex
	@install -c  -m 644 ${WRKDIR}/dvips562/PStfms/*.tfm ${PREFIX}/lib/texmf/fonts/tfm
	@install -c  -m 644 ${WRKDIR}/dvips562/PSvfs/*.vf ${PREFIX}/lib/texmf/fonts/vf

pre-clean:
	@rm -f ${SCRIPTDIR}/post-install

.include <bsd.port.mk>
