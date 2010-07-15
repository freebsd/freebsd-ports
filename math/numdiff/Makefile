# New ports collection makefile for:   numdiff
# Date created:        18 October 2006
# Whom:                Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	numdiff
PORTVERSION=	5.2.1
CATEGORIES=	math textproc
MASTER_SITES=	SAVANNAH

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Compare putatively similar files, ignoring small numeric differences

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --exec-prefix=${PREFIX} --infodir=${PREFIX}/${INFO_PATH} LIBS=-lm --disable-nls
USE_GMAKE=	yes

INFO=	numdiff

.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--docdir=${WRKDIR}/doc
.endif

.include <bsd.port.post.mk>
