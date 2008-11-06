# New ports collection makefile for:	ranlib
# Date created:		06 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ranlib
PORTVERSION=	1.0
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/random/
DISTNAME=	ranlib.c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of Routines for Random Number Generation

USE_LDCONFIG=	yes
MAKE_ENV=	NOPROFILE=true
WRKSRC=		${WRKDIR}/${DISTNAME}/src
PORTDOCS=	Basegen.c.doc ranlib.c.chs ranlib.c.fdoc
PLIST_FILES=	include/ranlib.h \
		lib/libranlib.a \
		lib/libranlib.so \
		lib/libranlib.so.1

post-extract:
	${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKDIR}/${DISTNAME}/doc/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
