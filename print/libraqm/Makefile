# $FreeBSD$

PORTNAME=	libraqm
PORTVERSION=	0.6.0
CATEGORIES=	print
MASTER_SITES=	https://github.com/HOST-Oman/libraqm/releases/download/v${PORTVERSION}/
DISTNAME=	raqm-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library that encapsulates complex text layout logic

LICENSE=	MIT

LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libharfbuzz.so:print/harfbuzz \
		libfreetype.so:print/freetype2

USES=		gmake libtool pkgconfig

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
