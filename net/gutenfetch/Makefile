# Created by: Russell Francis
# $FreeBSD$

PORTNAME=	gutenfetch
PORTVERSION=	1.5
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	johntabularasa@users.sf.net
COMMENT=	Fetch listings and books from Project Gutenberg

LIB_DEPENDS=	libgutenfetch.so:devel/libgutenfetch

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gmake tar:bzip2

PLIST_FILES=	bin/gutenfetch man/man1/gutenfetch.1.gz
SUB_FILES=	pkg-message

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gutenfetch

.include <bsd.port.mk>
