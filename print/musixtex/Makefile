# New ports collection makefile for:    musixtex
# Version required:     T80
# Date created:         9 july 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.15 1997/11/06 01:01:06 asami Exp $
#

DISTNAME=       musixtex-T80
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tex.ac.uk/tex-archive/macros/musixtex/taupin/
DISTFILES=      musixtex-T80.tar.gz musixexa-T79.tar.gz

MAINTAINER=	jmz@FreeBSD.org

BUILD_DEPENDS=	tex:${PORTSDIR}/print/tex
RUN_DEPENDS=	tex:${PORTSDIR}/print/tex

NO_WRKSUBDIR=	yes

pre-install:
	${MKDIR} ${PREFIX}/share/texmf/documentation

.include <bsd.port.mk>
