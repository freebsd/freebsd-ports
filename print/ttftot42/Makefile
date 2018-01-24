# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ttftot42
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://www.nih.at/ttftot42/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TrueType to Type42 font converter

LIB_DEPENDS=	libttf.so:print/freetype
GNU_CONFIGURE=	yes

USES=		localbase
PLIST_FILES=	bin/ttftot42

CPPFLAGS+=	-isystem${LOCALBASE}/include/freetype1/freetype

.include <bsd.port.mk>
