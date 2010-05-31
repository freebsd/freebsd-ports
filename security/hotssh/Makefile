# New ports collection makefile for:	hotssh
# Date created:		2009-01-30
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hotssh
PORTVERSION=	0.2.7
PORTREVISION=	2
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MAINTAINER=	wahjava@gmail.com
COMMENT=	HotSSH is an interface to Secure Shell, for GNOME and OpenSSH

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/libdata/pkgconfig/pygobject-2.0.pc:${PORTSDIR}/devel/py-gobject \
		${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib \
		${PYTHON_SITELIBDIR}/pysqlite2/test/__init__.py:${PORTSDIR}/databases/py-pysqlite23 \
		${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:${PORTSDIR}/x11-toolkits/py-vte
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/libdata/pkgconfig/pygobject-2.0.pc:${PORTSDIR}/devel/py-gobject \
		${PYTHON_SITELIBDIR}/pysqlite2/test/__init__.py:${PORTSDIR}/databases/py-pysqlite23 \
		${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:${PORTSDIR}/x11-toolkits/py-vte

USE_GNOME=	pygtk2 gnomedocutils libxslt glib20
USE_GETTEXT=	yes
USE_PYTHON=	2.5+
INSTALLS_ICONS=	yes
USE_BZIP2=	yes

B64DECODE?=	/usr/bin/b64decode
BSPATCH?=	/usr/bin/bspatch

post-extract:
	${GREP} -Rl '^#!/usr/bin/python$$' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} -e 's|^#!/usr/bin/python$$|#!/usr/bin/env python|g'
	${MV} ${WRKSRC}/waf ${WRKSRC}/waf.beforepatch
	cd ${WRKSRC} && ${B64DECODE} -o waf.diff ${FILESDIR}/waf.diff && ${BSPATCH} waf.beforepatch waf waf.diff && ${CHMOD} 755 waf
	${GREP} -Rl '%%LOCALBASE%%' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g"

do-configure:
	cd ${WRKSRC} && ./waf configure --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ./waf

do-install:
	cd ${WRKSRC} && ./waf install

.include <bsd.port.mk>
