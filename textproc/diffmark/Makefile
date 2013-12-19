# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	diffmark
PORTVERSION=	0.10
CATEGORIES=	textproc
MASTER_SITES=	http://www.mangrove.cz/diffmark/ \
		http://penguin.cz/~vbarta/diffmark/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML diff and merge package

USES=		pkgconfig
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lstdc++||' ${WRKSRC}/lib/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdiffmark.so.2

.include <bsd.port.mk>
