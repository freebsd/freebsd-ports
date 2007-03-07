# New ports collection makefile for:	straw
# Date created:				06 March 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	straw
PORTVERSION=	0.26
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=sources/${PORTNAME}/${PORTVERSION}

MAINTAINER=	R.Mahmatkhanov@SKYLINK.RU
COMMENT=	A GNOME 2 desktop weblog aggregator written in Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb \
		${PYTHON_SITELIBDIR}/dbus/_dbus.py:${PORTSDIR}/devel/py-dbus

USE_GMAKE=	yes
USE_XLIB=	yes
USE_GNOME=	gnomehier libglade2 pygnome2 pygnomeextras
USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} \
				--install-lib=${PREFIX}/share/gnome \
				--with-desktop-file-dir=share/gnome/applications

GCONF_SCHEMAS=	straw.schemas

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g' \
		${WRKSRC}/src/straw

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
