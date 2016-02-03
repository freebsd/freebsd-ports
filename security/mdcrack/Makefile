# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mdcrack
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://membres.lycos.fr/mdcrack/download/

MAINTAINER=	lasg@lasg.dk
COMMENT=	Bruteforce password MD5 hashes

ALL_TARGET=	little
PLIST_FILES=	bin/mdcrack
MAKE_ARGS=	LDFLAGS="${LDFLAGS} -lncurses"

USES=		compiler:features ncurses

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} < 36
post-patch:
	@${REINPLACE_CMD} -e 's|-fforce-addr||' ${WRKSRC}/Makefile
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
