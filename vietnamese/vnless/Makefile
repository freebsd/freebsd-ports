PORTNAME=	vnless
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	vietnamese
MASTER_SITES=	ftp://ftp.monash.edu.au/pub/vietnam/unix/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pager utility that speaks Vietnamese

LICENSE=	LESSLICENSE
LICENSE_NAME=	less License
LICENSE_FILE=	${WRKSRC}/version.c
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

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
