PORTNAME=	parley
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	misc education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Vocabulary trainer for KDE
WWW=		https://edu.kde.org/applications/all/parley

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml

USES=		cmake desktop-file-utils gettext gnome kde:6 qt:6 tar:xz xorg
USE_GNOME=	libxml2 libxslt
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		crash doctools i18n jobwidgets kcmutils kio libkeduvocdocument \
		newstuff sonnet textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base multimedia webengine
USE_XORG=	ice sm x11 xext xrender

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
