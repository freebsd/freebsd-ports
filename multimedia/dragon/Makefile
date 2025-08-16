PORTNAME=	dragon
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	multimedia kde kde-applications
PKGNAMESUFFIX=	-player

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE multimedia player with a focus on simplicity
WWW=		https://www.kde.org/applications/multimedia/dragonplayer/

LICENSE=	GPLv2

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USES=		cmake compiler:c++23-lang desktop-file-utils gettext kde:6 \
		pkgconfig qt:6 tar:xz xorg
USE_KDE=	config coreaddons crash i18n kio kirigami2 windowsystem \
		doctools:build ecm:build
USE_QT=		base multimedia
USE_XORG=	x11

CONFLICTS_INSTALL=	dragon # bin/dragon

OPTIONS_DEFINE=	DOCS

# Support for 13.5-RELEASE and 14.2-RELEASE
.if !exists(/usr/bin/clang-scan-deps)
USES+=		llvm
.endif

.include <bsd.port.mk>
