PORTNAME=	rman
PORTVERSION=	3.2
CATEGORIES=	textproc
MASTER_SITES=	SF/polyglotman/polyglotman/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reverse compile man pages from formatted form

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		BINDIR="${PREFIX}/bin" MANDIR="${MAN1PREFIX}/man/man1"

PLIST_FILES=	bin/rman man/man1/rman.1.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rman

.include <bsd.port.mk>
