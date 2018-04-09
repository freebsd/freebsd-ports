# $FreeBSD$

PORTNAME=	ksystemlog
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE system log application

USES=		cmake:outsource gettext kde:5 pkgconfig tar:xz
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		doctools ecm i18n iconthemes itemviews jobwidgets kio \
		service sonnet textwidgets widgetsaddons xmlgui
USE_QT5=	core dbus gui network printsupport testlib widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
