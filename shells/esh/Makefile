# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=	esh
PORTVERSION=	0.8.5
PORTREVISION=	4
CATEGORIES=	shells
MASTER_SITES=	GENTOO

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The "easy shell", a small shell with Lisp-like syntax

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		ncurses readline
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} ${CPPFLAGS}" \
		LIB="${LDFLAGS} -lreadline -lncurses"

INFO=		esh

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

post-patch:
	@${REINPLACE_CMD} -e \
		's|<readline.h>|<readline/readline.h>| ; \
		s|<history.h>|<readline/history.h>|' ${WRKSRC}/read-rl.c

pre-build:
	@(cd ${WRKSRC} && ${MAKE} clean)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esh ${STAGEDIR}${PREFIX}/bin/esh
	${INSTALL_DATA} ${WRKSRC}/doc/esh.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

.include <bsd.port.mk>
