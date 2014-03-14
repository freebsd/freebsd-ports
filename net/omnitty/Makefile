# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	omnitty
PORTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A curses-based SSH multiplexer

LIB_DEPENDS=	librote.so:${PORTSDIR}/devel/rote

USES=		gmake
GNU_CONFIGURE=	yes

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/omnitty man/man1/omnitty.1.gz

post-patch:
	${REINPLACE_CMD} 's|<alloca.h>|<stdlib.h>|' \
		${WRKSRC}/machmgr.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
