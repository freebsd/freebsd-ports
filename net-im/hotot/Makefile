# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hotot
PORTVERSION=	0.9.8.8
CATEGORIES=	net-im www
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Lightweight, flexible microblogging client

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/webkit/__init__.py:${PORTSDIR}/www/py-webkitgtk \
		${PYTHON_SITELIBDIR}/keybinder/__init__.py:${PORTSDIR}/x11/keybinder

USE_GITHUB=	yes
GH_ACCOUNT=	shellex
GH_PROJECT=	Hotot
GH_TAGNAME=	master
GH_COMMIT=	9c8c8a2

USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_QT4=	moc_build qmake_build rcc_build uic_build \
		corelib gui sql webkit
USE_GNOME=	intltool
INSTALLS_ICONS=	yes

CFLAGS+=	-I${LOCALBASE}/include		# does not uphold CPPFLAGS

post-patch:
# Upstream should probably use platform.system() instead of hardcoding its
# name in Python code (at least)
	@${REINPLACE_CMD} -e 's,Linux,${OPSYS},' ${WRKSRC}/data/js/conf.js \
		${WRKSRC}/data/js/util.js ${WRKSRC}/hotot/view.py
# Strip shlib versions from the library filenames
	@${REINPLACE_CMD} -E 's,so\.[0-9]+,so,' ${WRKSRC}/hotot/utils.py
# Remove `sourceid' parameter from the search string
	@${REINPLACE_CMD} -e 's,sourceid=chrome&,,' \
		${WRKSRC}/data/js/ui.context_menu.js
# Sanitize font selection list
	@${REINPLACE_CMD} -e "/font_list/s/\[.*/['DejaVu Sans', 'Bitstream Vera Sans', 'Droid Sans', 'Verdana', 'Arial', 'Helvetica']/" \
		${WRKSRC}/data/js/conf.js
# Remove stale backup files (or they would pollute pkg-plist)
	@${FIND} ${WRKSRC} -type f -name *.bak -delete

.include <bsd.port.mk>
