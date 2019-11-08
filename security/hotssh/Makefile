# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	hotssh
PORTVERSION=	0.2.7
PORTREVISION=	7
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	HotSSH is an interface to Secure Shell, for GNOME and OpenSSH

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:devel/dbus-glib \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vte>=0:x11-toolkits/py-vte@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vte>=0:x11-toolkits/py-vte@${PY_FLAVOR}

USE_GNOME=	glib20 gnomedocutils intltool libxslt pygobject pygtk2
USES=		gettext gnome python:2.7 tar:bzip2 waf
INSTALLS_ICONS=	yes
NO_ARCH=	yes

B64DECODE?=	/usr/bin/b64decode
BSPATCH?=	/usr/bin/bspatch

post-extract:
	@${GREP} -Rl '^#!/usr/bin/python$$' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} -e 's|^#!/usr/bin/python$$|#!${PYTHON_CMD}|g'
	@${MV} ${WRKSRC}/waf ${WRKSRC}/waf.beforepatch
	@cd ${WRKSRC} && ${B64DECODE} -o waf.diff ${FILESDIR}/waf.diff && ${BSPATCH} waf.beforepatch waf waf.diff && ${CHMOD} 755 waf
	@${GREP} -Rl '%%LOCALBASE%%' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g"

post-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d ${PYTHONPREFIX_SITELIBDIR} -f ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -d ${PYTHONPREFIX_SITELIBDIR} -f ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
