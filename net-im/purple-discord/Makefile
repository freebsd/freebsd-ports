PORTNAME=	purple-discord
DISTVERSION=	g20251012
CATEGORIES=	net-im

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Discord plugin for libpurple
WWW=		https://github.com/EionRobb/purple-discord

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libpurple.so:net-im/libpurple \
		libqrencode.so:graphics/libqrencode

USES=		dos2unix gettext gmake gnome magick:build pkgconfig
DOS2UNIX_FILES=	Makefile
USE_GITHUB=	yes
GH_ACCOUNT=	EionRobb
GH_TAGNAME=	nightly-f60596c3e6a22f819ad408232257dca1757a8519
USE_GNOME=	glib20

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/purple-2/libdiscord.so

.include <bsd.port.mk>
