# New ports collection makefile for:	tidy
# Version required:	0.1.98.9
# Date created:		27 Oct 1998
# Whom:			Abel Chow <achow@transoft.net>
#
# $Id: Makefile,v 1.5 1999/01/06 03:34:34 jkoshy Exp $
#

DISTNAME=	tidy22jan99
PKGNAME=	tidy-0.1.99.1
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/People/Raggett/
EXTRACT_SUFX=	.tgz

MAINTAINER=	saken@hotel.rmta.org

ALL_TARGET=	tidy

DOCFILES=	Overview.html tidy.gif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tidy ${PREFIX}/bin/tidy
.if !defined(NOPORTDOCS)
	@echo "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${PREFIX}/share/doc/tidy
.for docfile in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${PREFIX}/share/doc/tidy
.endfor
.endif

.include <bsd.port.mk>
