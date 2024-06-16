PORTNAME=	diffmark
PORTVERSION=	0.10
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://www.mangrove.cz/diffmark/ \
		http://penguin.cz/~vbarta/diffmark/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML diff and merge package
WWW=		http://www.mangrove.cz/diffmark/

BROKEN=		Unfetchable
DEPRECATED=	Fails to build with libxml2 2.13.0 (PR 279705)
EXPIRATION_DATE=2024-07-16

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
