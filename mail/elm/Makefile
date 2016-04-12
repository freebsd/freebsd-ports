# Created by: dhagan@cs.vt.edu
# $FreeBSD$

PORTNAME=	elm
PORTVERSION=	2.5.8
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	http://instinct.org/elm/files/tarballs/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Once-popular mail user agent, version 2.5.x

LICENSE=	ELM
LICENSE_NAME=	Elm(tm) Mail System General Public License
LICENSE_FILE=	${WRKSRC}/NOTICE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	ispell:textproc/aspell-ispell

CFLAGS+=	-D_SIZE_T

WRKSRC=			${WRKDIR}/elm${PORTVERSION}
USES=		gettext ncurses
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ENV=		PREFIX="${PREFIX}"
CONFIGURE_ARGS=		-d
MAKE_ARGS+=		CATMAN=catman-none
MAKE_ARGS+=		DESTBIN="${STAGEDIR}${PREFIX}/bin"
MAKE_ARGS+=		DESTLIB="${STAGEDIR}${PREFIX}/lib"
MAKE_ARGS+=		LIB="${STAGEDIR}${PREFIX}/lib"
MAKE_ARGS+=		MAN="${STAGEDIR}${PREFIX}/man/man1"
MAKE_ARGS+=	-B
EXTRACT_AFTER_ARGS=	--exclude gencat

.include <bsd.port.mk>
