PORTNAME=	kdesignerplugin
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 integration of Frameworks widgets in Qt Designer/Creator

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons i18n iconthemes itemviews \
		jobwidgets kio plotting service solid sonnet \
		textwidgets widgetsaddons xmlgui \
		ecm:build
USE_QT=		concurrent core dbus designer gui linguisttools \
		network widgets xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS
OPTIONS_SUB=		yes

.include <bsd.port.options.mk>

.if !${ABI:Mpurecap}
USE_KDE+=	kdewebkit
USE_QT+=	webkit
.endif

.include <bsd.port.mk>
