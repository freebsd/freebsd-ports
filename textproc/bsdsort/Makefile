# New ports collection makefile for:	bsd-sort
# Date created:				12 Juni 2007
# Whom:					Gabor Kovesdan <gabor@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sort
PORTVERSION=	20070612
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	gabor
PKGNAMEPREFIX=	bsd-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	BSD-licensed version of sort from OpenBSD

MAN1=		sort.1
PLIST_FILES=	bin/sort

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		MANDIR="${MANPREFIX}/man/man" \
		CATDIR="${MANPREFIX}/man/man"

.include <bsd.port.mk>
