PORTNAME=	purple-discord
DISTVERSION=	g20250810
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

USES=		dos2unix gettext-runtime gettext-tools gmake gnome \
		magick:build pkgconfig
DOS2UNIX_FILES=	Makefile
USE_GITHUB=	yes
GH_ACCOUNT=	EionRobb
GH_TAGNAME=	nightly-e39f97e59c446d6af5d2ef2ef259391867fd95e4
USE_GNOME=	glib20

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/purple-2/libdiscord.so

.include <bsd.port.mk>
