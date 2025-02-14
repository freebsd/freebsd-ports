PORTNAME=	dikt
PORTVERSION=	3
PORTEPOCH=	1
CATEGORIES=	textproc net kde
MASTER_SITES=	https://gitlab.com/-/project/46530021/uploads/b7050a0b8397a27501e7c0be4f40066c/

MAINTAINER=	info@dikt.tv
COMMENT=	Dictionary for KDE
WWW=		https://dikt.tv/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang kde:6 qt:6 tar:txz \
		desktop-file-utils gettext
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons dbusaddons guiaddons i18n iconthemes itemviews \
		jobwidgets kio service solid widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base

PLIST_FILES=	bin/dikt \
		share/applications/dikt.desktop \
		share/dikt/dikt.css \
		share/dikt/format.conf \
		share/icons/hicolor/128x128/apps/dikt.png \
		share/kxmlgui5/dikt/diktui.rc

.include <bsd.port.mk>
