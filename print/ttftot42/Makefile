# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ttftot42
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.nih.at/ttftot42/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TrueType to Type42 font converter

LIB_DEPENDS=	ttf:${PORTSDIR}/print/freetype
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ttftot42

CPPFLAGS+=	-I${LOCALBASE}/include/freetype1/freetype \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.mk>
