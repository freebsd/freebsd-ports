# $FreeBSD$

PORTNAME=	falkon
PORTVERSION=	2.1.2
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	ken@ixsystems.com
COMMENT=	Web browser based on Qt Webengine

LICENSE=	GPLv3

LIB_DEPENDS=	libhunspell-1.6.so:textproc/hunspell

USES=		desktop-file-utils pkgconfig ssl tar:xz cmake
USE_QT5=	core concurrent gui network printsupport script sql webengine \
		widgets x11extras xml quick webchannel imageformats_run sql-sqlite3_run \
		buildtools_build linguisttools_build
USE_XORG=	x11 xcb
USE_GL=		gl
CONFIGURE_ENV=	FALKON_PREFIX=${PREFIX}/
USE_LDCONFIG=	yes
PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	DBUS DEBUG
OPTIONS_SUB=	yes

DBUS_USE=		QT5=dbus
DBUS_CONFIGURE_ENV_OFF=	DISABLE_DBUS="true"

USE_GITHUB=	yes
GH_ACCOUNT=	KDE
GH_PROJECT=	falkon
GH_TAGNAME=	b4eaa10c100bff53d7f53f283505a81fa5988966

.include <bsd.port.options.mk>

# work around for build failure in test plugin (single source file target)
.if ${PORT_OPTIONS:MDEBUG}
MAKE_JOBS_UNSAFE=	yes
.endif

.include <bsd.port.mk>
