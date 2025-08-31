PORTNAME=	purple-teams
PORTVERSION=	20240827
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Plugin for Pidgin to provide MS Teams connectivity
WWW=		https://github.com/EionRobb/purple-teams

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libpurple.so:net-im/libpurple
RUN_DEPENDS=	pidgin:net-im/pidgin \
				xdg-open:devel/xdg-utils

USES=		dos2unix gmake gnome pkgconfig
DOS2UNIX_REGEX=	.*\.([ch]|cpp)
DOS2UNIX_FILES=	Makefile

USE_GITHUB=	yes

GH_ACCOUNT=	EionRobb
GH_TAGNAME=	nightly-f4a02c5047ba296c76eb923f2ba83cabab8a8089
USE_GNOME=	glib20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
