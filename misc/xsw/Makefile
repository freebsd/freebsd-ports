# Created by: corky1951@comcast.net
# $FreeBSD$

PORTNAME=	xsw
PORTVERSION=	0.3.5
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Tool for creating presentations

OPTIONS_DEFINE=	DOCS

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_SDL=	sdl ttf image gfx

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

DOCS=		AUTHORS \
		COPYING \
		NEWS \
		README \
		REFERENCE \
		THANKS \
		TODO \
		doc/xsw.vim

post-patch:
	@${REINPLACE_CMD} -e "s,./install-fonts ,./install-fonts \$$(DESTDIR)," \
		${WRKSRC}/data/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
