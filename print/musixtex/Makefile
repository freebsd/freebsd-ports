# New ports collection makefile for:    musixtex
# Date created:         9 july 1995
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	musixtex
PORTVERSION=	T98
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tex.ac.uk/tex-archive/macros/musixtex/taupin/
DISTFILES=	musixtex-T98.tar.gz musixexa-T90.tar.gz

MAINTAINER=	jmz@FreeBSD.org

BUILD_DEPENDS=	tex:${PORTSDIR}/print/tex
RUN_DEPENDS=	tex:${PORTSDIR}/print/tex

NO_WRKSUBDIR=	yes

pre-install:
	${MKDIR} ${PREFIX}/share/texmf/documentation

.include <bsd.port.mk>
