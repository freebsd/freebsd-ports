# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hotot
PORTVERSION=	0.9.8.14
PORTREVISION=	5
CATEGORIES=	net-im www

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Lightweight, flexible microblogging client

LICENSE=	LGPL3

USE_GITHUB=	yes
GH_ACCOUNT=	lyricat
GH_PROJECT=	Hotot

USES=		cmake gettext python:2.7
USE_GNOME=	intltool
INSTALLS_ICONS=	yes

CFLAGS+=	-I${LOCALBASE}/include		# does not uphold CPPFLAGS
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=	GTK2 QT4
OPTIONS_DEFAULT=	GTK2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/webkit/__init__.py:www/py-webkitgtk \
		${PYTHON_SITELIBDIR}/keybinder/__init__.py:x11/keybinder
PLIST_SUB+=	GTK2=""
.else
CMAKE_ARGS+=	-DWITH_GTK=off
PLIST_SUB+=	GTK2="@comment "
.endif

.if ${PORT_OPTIONS:MQT4}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
USES+=		qt:4
USE_QT=		moc_build qmake_build rcc_build uic_build \
		corelib gui sql webkit
PLIST_SUB+=	QT4=""
.else
CMAKE_ARGS+=	-DWITH_QT=off
INSTALL_TARGET=	install
PLIST_SUB+=	QT4="@comment "
.endif

CMAKE_ARGS+=	-DWITH_KDE=off

post-patch:
# Fix hardcoded platform name (it is not always Linux)
	@${REINPLACE_CMD} -e 's,Linux,${OPSYS},' ${WRKSRC}/data/js/conf.js \
		${WRKSRC}/data/js/util.js ${WRKSRC}/qt/mainwindow.cpp
# Strip shlib versions from the library filenames
	@${REINPLACE_CMD} -E 's,so\.[0-9]+,so,' ${WRKSRC}/hotot/utils.py
# Remove `sourceid' parameter from Google search string
	@${REINPLACE_CMD} -e 's,sourceid=chrome&,,' \
		${WRKSRC}/data/js/ui.context_menu.js
# Sanitize font selection list
	@${REINPLACE_CMD} -e "/font_list/s/\[.*/['DejaVu Sans', 'Bitstream Vera Sans', 'Droid Sans', 'Verdana', 'Arial', 'Helvetica']/" \
		${WRKSRC}/data/js/conf.js

.include <bsd.port.mk>
