# New ports collection makefile for:	tidy
# Version required:	0.1.98.9
# Date created:		27 Oct 1998
# Whom:			Abel Chow <achow@transoft.net>
#
# $Id$
#

DISTNAME=	tidy01sep98
PKGNAME=	tidy-0.1.98.9
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/People/Raggett/

MAINTAINER=	ports@FreeBSD.ORG

ALL_TARGET=	tidy
WRKSRC=		${WRKDIR}/tidy01sep98

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
