# New ports collection makefile for:    musixtex
# Version required:     T89
# Date created:         9 july 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.18 1998/01/26 12:01:18 asami Exp $
#

DISTNAME=       musixtex-T89
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tex.ac.uk/tex-archive/macros/musixtex/taupin/
DISTFILES=      musixtex-T89.tar.gz musixexa-T86.tar.gz

MAINTAINER=	jmz@FreeBSD.org

BUILD_DEPENDS=	tex:${PORTSDIR}/print/tex
RUN_DEPENDS=	tex:${PORTSDIR}/print/tex

NO_WRKSUBDIR=	yes

pre-install:
	${MKDIR} ${PREFIX}/share/texmf/documentation

.include <bsd.port.mk>
