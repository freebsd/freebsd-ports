# New ports collection makefile for:	xmbibtex
# Date created:				06 Nov 1997
# Whom:					Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmbibtex
PORTVERSION=	1.5
CATEGORIES=	print databases
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/tex

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A reference manager based on the BibTeX file format

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_MOTIF=	yes
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile (bad C++ code)"
.endif

.include <bsd.port.post.mk>
