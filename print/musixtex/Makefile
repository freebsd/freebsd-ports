# New ports collection makefile for:    musixtex
# Version required:     T76
# Date created:         9 july 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.9 1997/08/25 00:26:59 jmz Exp $
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

.include <bsd.port.mk>
