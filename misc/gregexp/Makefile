# Created by: ijliao
# $FreeBSD$

PORTNAME=	gregexp
PORTVERSION=	0.3
PORTREVISION=	13
CATEGORIES=	misc
MASTER_SITES=	http://dentrassi.de/download/gregexp/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical regular expression explorer

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		pkgconfig
USE_GNOME=	gnomeprefix libgnomeui
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
