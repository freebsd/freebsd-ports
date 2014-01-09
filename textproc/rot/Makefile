# Created by: ijliao
# $FreeBSD$

PORTNAME=	rot
PORTVERSION=	1.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.xs4all.nl/~henkoers/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rotates a file so that lines become columns and vice versa

ALL_TARGET=	${PORTNAME}
CFLAGS+=	-Wno-return-type

PLIST_FILES=	bin/rot man/man1/rot.1.gz

post-patch:
	@${REINPLACE_CMD} "s:^CFLAGS=:#CFLAGS=:" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rot ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rot.man ${STAGEDIR}${MAN1PREFIX}/man/man1/rot.1

.include <bsd.port.mk>
