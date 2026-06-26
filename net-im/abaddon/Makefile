PORTNAME=	abaddon
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.4
CATEGORIES=	net-im

MAINTAINER=	seafork@disroot.org
COMMENT=	Alternative Discord client with voice support
WWW=		https://github.com/uowuo/abaddon

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfmt.so:devel/libfmt \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libhandy-1.so:x11-toolkits/libhandy \
		libopus.so:audio/opus \
		librnnoise.so:audio/rnnoise \
		libsecret-1.so:security/libsecret \
		libsodium.so:security/libsodium \
		libspdlog.so:devel/spdlog

USES=		cmake compiler:c++17-lang gnome pkgconfig sqlite ssl

USE_GITHUB=	yes
GH_ACCOUNT=	uowuo
GH_TUPLE=	machinezone:IXWebSocket:bc765e7:ixwebsocket/subprojects/ixwebsocket \
		hrantzsch:keychain:8846e78:keychain/subprojects/keychain \
		discord:libdave:52cd56d:libdave/subprojects/libdave \
		mackron:miniaudio:9634bed:miniaudio/subprojects/miniaudio \
		cisco:mlspp:1cc50a1:mlspp/subprojects/mlspp \
		nayuki:QR-Code-generator:22fac31:qrcodegenerator/subprojects/qrcodegen
USE_GNOME=	gdkpixbufextra gtkmm30

.include <bsd.port.mk>
