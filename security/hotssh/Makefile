# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	hotssh
PORTVERSION=	0.2.7
PORTREVISION=	5
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	HotSSH is an interface to Secure Shell, for GNOME and OpenSSH

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/libdata/pkgconfig/pygobject-2.0.pc:${PORTSDIR}/devel/py-gobject \
		${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:${PORTSDIR}/x11-toolkits/py-vte
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/libdata/pkgconfig/pygobject-2.0.pc:${PORTSDIR}/devel/py-gobject \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:${PORTSDIR}/x11-toolkits/py-vte

USE_GNOME=	pygtk2 gnomedocutils libxslt glib20
USES=		gettext python tar:bzip2 waf
INSTALLS_ICONS=	yes

B64DECODE?=	/usr/bin/b64decode
BSPATCH?=	/usr/bin/bspatch

post-extract:
	@${GREP} -Rl '^#!/usr/bin/python$$' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} -e 's|^#!/usr/bin/python$$|#!/usr/bin/env python|g'
	@${MV} ${WRKSRC}/waf ${WRKSRC}/waf.beforepatch
	@cd ${WRKSRC} && ${B64DECODE} -o waf.diff ${FILESDIR}/waf.diff && ${BSPATCH} waf.beforepatch waf waf.diff && ${CHMOD} 755 waf
	@${GREP} -Rl '%%LOCALBASE%%' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g"

.include <bsd.port.mk>
