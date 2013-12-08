# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmpal
PORTVERSION=	0.6.1
CATEGORIES=	misc windowmaker
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	One of the most useless dockapps in the world

LICENSE=	GPLv2

USE_XORG=	xpm
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lX11

PORTDOCS=	README
PLIST_FILES=	bin/wmpal

post-patch:
	@${REINPLACE_CMD} -e 's|"dino"|"daemon"|g' ${WRKSRC}/wmpal.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
