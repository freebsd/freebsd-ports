PORTNAME=	plasmatube
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	multimedia kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Elegant user interface for YouTube
WWW=		https://apps.kde.org/plasmatube/

LIB_DEPENDS=	libmpv.so:multimedia/mpv \
		libMpvQt.so:multimedia/mpvqt \
		libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake gettext kde:6 localbase:ldflags pkgconfig qt:6 tar:xz
USE_KDE=	config coreaddons dbusaddons i18n kirigami-addons kirigami2 \
		windowsystem \
		ecm:build
USE_QT=		base declarative

# Replace default Invidious instance with one that currently works 
#post-patch:
#	@${REINPLACE_CMD} -e 's|https://inv.riverside.rocks|https://vid.puffyan.us|' \
#		${WRKSRC}/src/PlasmaTubeSettings.kcfg

.include <bsd.port.mk>
