# $FreeBSD$

PORTNAME=	kdiff3
DISTVERSION=	1.8.2
CATEGORIES=	textproc kde
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE graphical frontend for diff

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash ecm i18n iconthemes jobwidgets kio \
		parts service sonnet textwidgets widgetsaddons xmlgui
USE_QT=		concurrent core dbus gui network printsupport widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS
DOCSDIR_REL=	share/doc/HTML

.include <bsd.port.mk>
