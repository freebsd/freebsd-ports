# New ports collection makefile for:	geekcode generator
# Date created:		30 Aug 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geekcode
PORTVERSION=	1.7.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	geekcode

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Geek Code Generator

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/geekcode
PORTDOCS=	geekcode.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/geekcode ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/geekcode.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
