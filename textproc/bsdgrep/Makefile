# New ports collection makefile for:	bsd-grep
# Date created:				12 Juni 2007
# Whom:					Gabor Kovesdan <gabor@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	grep
PORTVERSION=	20070612
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	gabor
PKGNAMEPREFIX=	bsd-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	BSD-licensed version of grep from OpenBSD

MAN1=		grep.1
MLINKS=		grep.1 egrep.1 \
		grep.1 fgrep.1 \
		grep.1 zgrep.1 \
		grep.1 zegrep.1 \
		grep.1 zfgrep.1
PLIST_FILES=	bin/grep bin/egrep bin/fgrep bin/zgrep bin/zegrep bin/zfgrep

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		MANDIR="${MANPREFIX}/man/man" \
		CATDIR="${MANPREFIX}/man/man"

.include <bsd.port.mk>
