# New ports collection makefile for:	bsd-diff
# Date created:				12 Juni 2007
# Whom:					Gabor Kovesdan <gabor@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	diff
PORTVERSION=	20080526
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	gabor
PKGNAMEPREFIX=	bsd-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	BSD-licensed version of diff from OpenBSD

WRKSRC=		${WRKDIR}/${PORTNAME}
MANCOMPRESSED=	yes
MAN1=		diff.1

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		MANDIR="${MANPREFIX}/man/man" \
		CATDIR="${MANPREFIX}/man/man"

post-install:
	${LN} -s ${PREFIX}/bin/diff ${PREFIX}/bin/bsddiff
	${LN} -s /usr/bin/diff ${PREFIX}/bin/gnudiff

.include <bsd.port.mk>
