# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	diffmark
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.mangrove.cz/diffmark/ \
		http://penguin.cz/~vbarta/diffmark/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML diff and merge package

USES=		gnome libtool pkgconfig
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lstdc++||' ${WRKSRC}/lib/Makefile.in

.include <bsd.port.mk>
