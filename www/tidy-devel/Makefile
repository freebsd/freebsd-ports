# New ports collection makefile for:	tidy
# Version required:	0.10.99.1
# Date created:		27 Oct 1998
# Whom:			Abel Chow <achow@transoft.net>
#
# $FreeBSD$
#

DISTNAME=	tidy22oct99
PKGNAME=	tidy-0.10.99.1
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/People/Raggett/
EXTRACT_SUFX=	.tgz
MAN1=	tidy.1

MAINTAINER=	saken@hotel.rmta.org

ALL_TARGET=	tidy

DOCFILES=	Overview.html tidy.gif release-notes.html grid.gif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tidy ${PREFIX}/bin/tidy
	@${INSTALL_MAN}	${WRKSRC}/man_page.txt	${PREFIX}/man/man1/tidy.1
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${PREFIX}/share/doc/tidy
.for docfile in ${DOCFILES}
	@${INSTALL_MAN} ${WRKSRC}/${docfile} ${PREFIX}/share/doc/tidy
.endfor
.endif

.include <bsd.port.mk>
