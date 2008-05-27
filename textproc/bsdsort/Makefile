# New ports collection makefile for:	bsd-sort
# Date created:				12 Juni 2007
# Whom:					Gabor Kovesdan <gabor@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sort
PORTVERSION=	20080526
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	gabor
PKGNAMEPREFIX=	bsd-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	BSD-licensed version of sort from OpenBSD

WRKSRC=		${WRKDIR}/${PORTNAME}
MANCOMPRESSED=	yes
MAN1=		sort.1

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		MANDIR="${MANPREFIX}/man/man" \
		CATDIR="${MANPREFIX}/man/man"

post-install:
	${LN} -s ${PREFIX}/bin/sort ${PREFIX}/bin/bsdsort
	${LN} -s /usr/bin/sort ${PREFIX}/bin/gnusort

.include <bsd.port.mk>
