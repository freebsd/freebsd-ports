# New ports collection makefile for:	geekcode generator
# Date created:		30 Aug 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geekcode
PORTVERSION=	1.7
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://seymour.lazygenes.net/ \
		http://www.zort.on.ca/software/
MASTER_SITE_SUBDIR=	geekcode

MAINTAINER=	cpiazza@FreeBSD.org

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/geekcode ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/geekcode
	${INSTALL_DATA} ${WRKSRC}/geekcode.txt ${PREFIX}/share/doc/geekcode
.endif

.include <bsd.port.mk>
