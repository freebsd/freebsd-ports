# New ports collection makefile for:	straw
# Date created:				06 March 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	straw
PORTVERSION=	0.27
PORTREVISION=	7
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME 2 desktop weblog aggregator written in Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb \
		${PYTHON_SITELIBDIR}/dbus/_dbus.py:${PORTSDIR}/devel/py-dbus

DEPRECATED=	abandoned upstream and does not work with python 2.6+
EXPIRATION_DATE=2011-03-31

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehier libglade2 pygnome2 pygnomeextras
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Straw
PYDISTUTILS_EGGINFODIR=	${PREFIX}/share
PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} \
				--install-lib=${PREFIX}/share \
				--with-desktop-file-dir=share/applications

GCONF_SCHEMAS=	straw.schemas

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g' \
		${WRKSRC}/src/straw

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
