PORTNAME=	omnitty
PORTVERSION=	0.3.0
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	SF/omnitty/omnitty/omnitty-${PORTVERSION}

MAINTAINER=	david@catwhisker.org
COMMENT=	Curses-based SSH multiplexer
WWW=		https://omnitty.sourceforge.net/

LIB_DEPENDS=	librote.so:devel/rote

USES=		gmake ncurses
GNU_CONFIGURE=	yes
LIBS+=		-lncurses

ALL_TARGET=	omnitty
PLIST_FILES=	bin/omnitty share/man/man1/omnitty.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omnitty ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/omnitty.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
