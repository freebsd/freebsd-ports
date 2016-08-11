# Created by: Ralf Nolden <nolden@kde.org>
# $FreeBSD$

PORTNAME=	qt5-style-plugins
PORTVERSION=	5.0.0
CATEGORIES=	x11-themes
MASTER_SITES=	QT/community_releases/additional_qt_src_pkgs/
DISTNAME=	qtstyleplugins-src-${PORTVERSION}
DIST_SUBDIR=	KDE/Qt/addons

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Additional Styles for Qt 5 and KDE

LICENSE=	LGPL21

USES=		qmake
USE_QT5=	buildtools_build core gui widgets
USE_GL+=	gl

WRKSRC=		${WRKDIR}/qtstyleplugins-src-${PORTVERSION}

.include <bsd.port.mk>
