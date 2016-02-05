# Created by: David O'Brien (obrien@cs.ucdavis.edu)
# $FreeBSD$

PORTNAME=	vnless
PORTVERSION=	1.0
CATEGORIES=	vietnamese
MASTER_SITES=	ftp://ftp.monash.edu.au/pub/vietnam/unix/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pager utility that speaks Vietnamese

USES=		ncurses
ALL_TARGET=	clobber all
MAKE_ARGS=	LIBS="-lncurses -lc"
CFLAGS+=	-Wno-return-type

PLIST_FILES=	bin/vnless \
		bin/vnlesskey \
		man/man1/vnless.1.gz \
		man/man1/vnlesskey.1.gz \
		share/misc/vnless.help

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
