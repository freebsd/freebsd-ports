# Created by: Russell Francis
# $FreeBSD$

PORTNAME=	gutenfetch
PORTVERSION=	1.5
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	johntabularasa@users.sf.net
COMMENT=	Fetch listings and books from Project Gutenberg

LIB_DEPENDS=	gutenfetch:${PORTSDIR}/devel/libgutenfetch

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gmake tar:bzip2

MAN1=		gutenfetch.1
PLIST_FILES=	bin/gutenfetch
SUB_FILES=	pkg-message

NO_STAGE=	yes
post-install:
	${STRIP_CMD} ${PREFIX}/bin/gutenfetch
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
