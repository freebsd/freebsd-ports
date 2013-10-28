# Created by: Abel Chow <achow@transoft.net>
# $FreeBSD$

PORTNAME=	tidy4
PORTVERSION=	20000804
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/People/Raggett/
DISTNAME=	tidy4aug00
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Fixes and tidies up HTML files

LICENSE=	BSD
LICENSE_FILE=	${FILESDIR}/COPYRIGHT

ALL_TARGET=	tidy
DOCFILES=	Overview.html tidy.gif release-notes.html grid.gif

.include <bsd.port.options.mk>

do-configure:
	${REINPLACE_CMD} -e 's|tidy|tidy4|' ${WRKSRC}/man_page.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tidy ${STAGEDIR}${PREFIX}/bin/tidy4
	${INSTALL_MAN}	${WRKSRC}/man_page.txt	${STAGEDIR}${MANPREFIX}/man/man1/tidy4.1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in ${DOCFILES}
	${INSTALL_MAN} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
