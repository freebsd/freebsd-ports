# New ports collection makefile for:	sysutils/daa2iso
# Date created:				27 Jan 2008
# Whom:					Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $Carpetsmoker: ports/sysutils/daa2iso/Makefile,v 1.3 2008/03/27 14:43:02 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	daa2iso
PORTVERSION=	0.1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.carpetsmoker.net/distfiles/ \
		http://www.xs4all.nl/distfiles/ \
		http://www.rwxrwxrwx.net/distfiles/

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	Convert PowerISO DAA files to ISO9660

PLIST_FILES=	bin/daa2iso
PORTDOCS=	daa2iso.txt

do-build:
	${CC} -o ${WRKSRC}/${PORTNAME} ${CFLAGS} -lz ${WRKSRC}/daa2iso.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/daa2iso ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/daa2iso.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
