# New ports collection makefile for:	tidy
# Version required:	0.1.98.9
# Date created:		27 Oct 1998
# Whom:			Abel Chow <achow@transoft.net>
#
# $Id: Makefile,v 1.4 1998/12/23 23:09:57 steve Exp $
#

DISTNAME=	tidy17dec98
PKGNAME=	tidy-0.1.98.12
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/People/Raggett/
EXTRACT_SUFX=	.tgz

MAINTAINER=	saken@budoir.net

ALL_TARGET=	tidy
WRKSRC=		${WRKDIR}/tidy17dec98

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
