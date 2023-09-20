PORTNAME=	plasmatube
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	multimedia kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Elegant user interface for YouTube
WWW=		https://apps.kde.org/plasmatube/

LIB_DEPENDS=	libmpv.so:multimedia/mpv

USES=		cmake kde:5 localbase:ldflags pkgconfig qt:5 tar:xz
USE_KDE=	config coreaddons i18n kirigami2 \
		ecm:build
USE_QT=		core declarative gui network quickcontrols2 svg \
		widgets xml \
		buildtools:build qmake:build testlib:build

# Replace default Invidious instance with one that currently works 
post-patch:
	@${REINPLACE_CMD} -e 's|https://inv.riverside.rocks|https://vid.puffyan.us|' \
		${WRKSRC}/src/PlasmaTubeSettings.kcfg

.include <bsd.port.mk>
