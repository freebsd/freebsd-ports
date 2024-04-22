PORTNAME=	paicc
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SUNSITE/utils/shell

MAINTAINER=	peter@FreeBSD.org
COMMENT=	Paint Changed Characters

USES=		ncurses
MAKE_ENV+=	BIN=${STAGEDIR}${PREFIX}/bin \
		MAN=${STAGEDIR}${PREFIX}/share/man \
		DATA=${STAGEDIR}${PREFIX}/libdata

.include <bsd.port.mk>
