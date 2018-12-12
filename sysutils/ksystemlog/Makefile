# $FreeBSD$

PORTNAME=	ksystemlog
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE system log application

USES=		cmake:outsource compiler:c++11-lang gettext kde:5 pkgconfig \
		qt:5 tar:xz
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		doctools ecm i18n iconthemes itemviews jobwidgets kio \
		service sonnet textwidgets widgetsaddons xmlgui
USE_QT=		core dbus gui network printsupport testlib widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
