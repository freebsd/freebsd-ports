# New ports collection makefile for:	Revelation
# Date created:				2004-08-10
# Whom:					ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	revelation
PORTVERSION=	0.4.0
CATEGORIES=	security gnome
MASTER_SITES=	ftp://oss.codepoet.no/revelation/

MAINTAINER=	ports@c0decafe.net
COMMENT=	Password manager for the GNOME 2 desktop

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Crypto/test.py:${PORTSDIR}/security/py-pycrypto

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pygnome2 gnomeprefix gnomehack desktopfileutils
USE_PYTHON=	yes
GCONF_SCHEMAS=	revelation.schemas

post-install:
	-@update-desktop-database

.include <bsd.port.mk>
