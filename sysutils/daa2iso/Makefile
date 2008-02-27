# New ports collection makefile for:	sysutils/daa2iso
# Date created:				27 Jan 2008
# Whom:					Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $Carpetsmoker: ports/sysutils/daa2iso/Makefile,v 1.2 2008/02/27 01:22:34 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	daa2iso
PORTVERSION=	0.1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://aluigi.altervista.org/mytoolz/ \
		http://www.carpetsmoker.net/distfiles/ \
		http://www.xs4all.nl/distfiles/

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	Convert PowerISO DAA files to ISO9660

NO_WRKSUBDIR=	yes
EXTRACT_SUFX=	.tgz
PLIST_FILES=	bin/daa2iso

do-build:
	${CC} -o ${WRKSRC}/${PORTNAME} ${CFLAGS} -lz ${WRKSRC}/daa2iso.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/daa2iso ${PREFIX}/bin/

.include <bsd.port.mk>
