# New ports collection makefile for:	sysutils/daa2iso
# Date created:				27 Jan 2008
# Whom:					Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $Carpetsmoker: ports/sysutils/daa2iso/Makefile,v 1.1 2008/01/27 05:41:11 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	daa2iso
PORTVERSION=	0.1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.carpetsmoker.net/distfiles/ \
		http://www.xs4all.nl/distfiles/

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	Convert PowerISO DAA files to ISO9660

PLIST_FILES=	bin/daa2iso

do-build:
	${CC} -o ${WRKSRC}/${PORTNAME} ${CFLAGS} -lz ${WRKSRC}/daa2iso.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/daa2iso ${PREFIX}/bin/

.include <bsd.port.mk>
