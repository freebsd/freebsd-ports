PORTNAME=	lowdown
PORTVERSION=	3.0.1
CATEGORIES=	textproc
MASTER_SITES=	https://kristaps.bsd.lv/lowdown/snapshots/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Simple Markdown translator
WWW=		https://kristaps.bsd.lv/lowdown/

LICENSE=	ISCL

LDFLAGS+=	-lmd
MAKE_ARGS=	LDFLAGS="${LDFLAGS}" MANDIR=${PREFIX}/share/man

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	PREFIX="${PREFIX}"
INSTALL_TARGET=	install install_libs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-diff
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblowdown.so.3

.include <bsd.port.mk>
