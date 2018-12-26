# $FreeBSD$

PORTNAME=	purple-discord
PORTVERSION=	g20181219
CATEGORIES=	net-im

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Discord plugin for libpurple

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpurple.so:net-im/libpurple \
		libjson-glib-1.0.so:devel/json-glib

USES=		dos2unix gettext gmake pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	EionRobb
GH_TAGNAME=	95d247c

DOS2UNIX_FILES=	Makefile

.include <bsd.port.mk>
