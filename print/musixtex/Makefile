# New ports collection makefile for:    musixtex
# Version required:     T76
# Date created:         9 july 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.10 1997/09/11 21:38:01 jmz Exp $
#

DISTNAME=       musixtex-T77
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tex.ac.uk//tex-archive/macros/musixtex/taupin/
DISTFILES=      musixtex-T77.tar.gz musixexa-T74.tar.gz

MAINTAINER=	jmz@FreeBSD.org

BUILD_DEPENDS=	tex:${PORTSDIR}/print/tex
RUN_DEPENDS=	tex:${PORTSDIR}/print/tex

NO_WRKSUBDIR=	yes

pre-install:
	${MKDIR} ${PREFIX}/share/texmf/documentation
	${MKDIR} ${PREFIX}/share/texmf/mf

.include <bsd.port.mk>
