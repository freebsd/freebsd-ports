PORTNAME=	libdiff
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://kristaps.bsd.lv/libdiff/snapshots/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Library to generate arbitrary sequence diffs
WWW=		https://github.com/kristapsdz/libdiff

LICENSE=	MIT

PLIST_FILES=	lib/libdiff.a \
		include/diff.h \
		share/man/man3/diff.3.gz
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	PREFIX="${PREFIX}" MANDIR="${PREFIX}/share/man"

.include <bsd.port.mk>
