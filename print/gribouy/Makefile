# Created by: bland@FreeBSD.org
# $FreeBSD$

PORTNAME=	gribouy
PORTVERSION=	0.0.8
PORTREVISION=	14
CATEGORIES=	print gnome
MASTER_SITES=	LOCAL/bland

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gribouy is a Type1 font editor

USES=		gmake pkgconfig pathfix gettext
USE_GNOME=	gnomeprefix libglade2 libgnomeui
GNU_CONFIGURE=	yes

USE_GCC=	any

post-patch:
	@${REINPLACE_CMD} -e '/^LIBS =/s|$$| -lm|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
