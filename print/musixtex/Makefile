# New ports collection makefile for:    musixtex
# Version required:     ?
# Date created:         9 july 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.4 1996/11/17 08:44:59 obrien Exp $
#

DISTNAME=       musixtex-3.96
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tex.ac.uk//tex-archive/macros/musixtex/taupin/
DISTFILES=      musixtex-T396.tar.gz musixexa-0375.tar.gz

MAINTAINER=	jmz@FreeBSD.org

BUILD_DEPENDS=	tex:${PORTSDIR}/print/tex
RUN_DEPENDS=	tex:${PORTSDIR}/print/tex

NO_WRKSUBDIR=	yes

pre-install:
	${MKDIR} ${PREFIX}/lib/texmf/fonts/tfm
	${MKDIR} ${PREFIX}/lib/texmf/documentation

.include <bsd.port.mk>
