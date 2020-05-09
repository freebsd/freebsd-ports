# $FreeBSD$

PORTNAME=	gopherus
DISTVERSION=	1.2.1
CATEGORIES=	www
MASTER_SITES=	SF/gopherus/v${DISTVERSION}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Classic text interface to the gopherspace

LICENSE=	BSD2CLAUSE

USES=		ncurses tar:xz uidfix
MAKEFILE=	${FILESDIR}/Makefile
CFLAGS+=	-I${NCURSESINC}
LDFLAGS+=	-L${NCURSESLIB} -l${NCURSES_IMPL}

PLIST_FILES=	bin/gopherus

.include <bsd.port.mk>
