# New ports collection makefile for:    musixtex
# Version required:     T64
# Date created:         9 july 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.5 1996/11/26 08:05:07 asami Exp $
#

DISTNAME=       musixtex-T64
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tex.ac.uk//tex-archive/macros/musixtex/taupin/
DISTFILES=      musixtex-T64.tar.gz musixexa-T64.tar.gz

MAINTAINER=	jmz@FreeBSD.org

BUILD_DEPENDS=	tex:${PORTSDIR}/print/tex
RUN_DEPENDS=	tex:${PORTSDIR}/print/tex

NO_WRKSUBDIR=	yes

pre-install:
	${MKDIR} ${PREFIX}/lib/texmf/fonts/tfm
	${MKDIR} ${PREFIX}/lib/texmf/documentation

.include <bsd.port.mk>
