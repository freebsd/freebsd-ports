PORTNAME=	rocs
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	math education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Graph theory IDE
WWW=		https://www.kde.org/applications/education/rocs

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake compiler:c++11-lang desktop-file-utils gettext \
		kde:6 qt:6 tar:xz
USE_KDE=	archive config coreaddons crash i18n itemviews \
		texteditor texttemplate textwidgets xmlgui \
		doctools:build ecm:build
USE_QT=		base svg
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
