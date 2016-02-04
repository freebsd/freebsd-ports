# Created by: Daniel Harris <dannyboy@subdimension.com>
# $FreeBSD$

PORTNAME=	fortunelock
PORTVERSION=	0.1.2
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/dannyboy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Locks a terminal while showing fortunes

USES=		ncurses tar:bzip2
MAKE_ARGS=	LIBS="${LDFLAGS} -lncurses"

PLIST_FILES=	bin/fortunelock man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
