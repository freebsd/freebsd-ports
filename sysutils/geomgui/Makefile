# Created by: Soeren Straarup <xride@FreeBSD.org>
# $FreeBSD$

PORTNAME=	geomgui
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://tinkering.hambrew.net/geomgui/ \
		LOCAL/xride

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Viewer for kernel geom layer

DEPRECATED=	Development stopped years ago.
EXPIRATION_DATE=	2016-12-31

LIB_DEPENDS=	libgvc.so:graphics/graphviz

USE_GNOME=	gtk20 librsvg2
USES=		iconv pkgconfig libtool tar:bzip2
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/geomgui \
		man/man1/geomgui.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${STAGEDIR}${PREFIX}|' \
		-e 's,-o root -g wheel,,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
