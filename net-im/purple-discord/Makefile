PORTNAME=	purple-discord
PORTVERSION=	g20210729
PORTREVISION=	2
CATEGORIES=	net-im

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Discord plugin for libpurple
WWW=		https://github.com/EionRobb/purple-discord

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libpurple.so:net-im/libpurple

USES=		dos2unix gettext gmake gnome magick:6,build pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	EionRobb
GH_TAGNAME=	6c5a778

DOS2UNIX_FILES=	Makefile

.include <bsd.port.mk>
