# New ports collection makefile for:    musixtex
# Version required:     T90
# Date created:         9 july 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.19 1998/04/08 21:28:48 jmz Exp $
#

DISTNAME=       musixtex-T90
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tex.ac.uk/tex-archive/macros/musixtex/taupin/
DISTFILES=      musixtex-T90.tar.gz musixexa-T90.tar.gz

MAINTAINER=	jmz@FreeBSD.org

BUILD_DEPENDS=	tex:${PORTSDIR}/print/tex
RUN_DEPENDS=	tex:${PORTSDIR}/print/tex

NO_WRKSUBDIR=	yes

pre-install:
	${MKDIR} ${PREFIX}/share/texmf/documentation

.include <bsd.port.mk>
