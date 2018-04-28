# $FreeBSD$

PORTNAME=	kbackup
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Backup program with an easy to use user interface

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons ecm i18n iconthemes itemviews jobwidgets kio \
		notifications service solid widgetsaddons xmlgui
USE_QT5=	core dbus gui network widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
