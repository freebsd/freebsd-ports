# $FreeBSD$

PORTNAME=	qupzilla
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	www
PKGNAMESUFFIX=  -qt5
DISTNAME=	QupZilla-${PORTVERSION}

MAINTAINER=	jmaloney@ixsystems.com
COMMENT=	Web browser based on WebKit engine and Qt Framework

LICENSE=	GPLv3

CONFLICTS_INSTALL=	${PORTNAME}-qt4*

USES=		desktop-file-utils execinfo pkgconfig qmake ssl tar:xz
USE_QT5=	core concurrent gui network printsupport script sql webkit \
		widgets x11extras xml imageformats_run sql-sqlite3_run \
		buildtools_build linguisttools_build webengine
USE_XORG=	x11
USE_GL=		gl
CONFIGURE_ENV=	QUPZILLA_PREFIX=${PREFIX}/
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
PLIST_SUB=	VERSION=${PORTVERSION}

USE_GITHUB=	yes

.include <bsd.port.options.mk>

GH_ACCOUNT=	qupzilla
GH_PROJECT=	qupzilla
GH_TAGNAME=	v2.1

.include <bsd.port.mk>
