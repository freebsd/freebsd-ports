# New ports collection makefile for:	Revelation
# Date created:				2004-08-10
# Whom:					ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	revelation
PORTVERSION=	0.4.3
PORTREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	ftp://oss.codepoet.no/revelation/

MAINTAINER=	ports@c0decafe.net
COMMENT=	Password manager for the GNOME 2 desktop

LIB_DEPENDS=	crack:${PORTSDIR}/security/cracklib
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Crypto/test.py:${PORTSDIR}/security/py-pycrypto
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Crypto/test.py:${PORTSDIR}/security/py-pycrypto

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pygnome2 gnomeprefix gnomehack desktopfileutils
USE_PYTHON=	yes
GCONF_SCHEMAS=	revelation.schemas
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|\(-Wl\)|$$(LDFLAGS) \1|' \
		${WRKSRC}/wrap/crack/Makefile.in
	@${REINPLACE_CMD} -e 's|#include <crack.h>||' \
		${WRKSRC}/wrap/crack/crack.c.in

post-install:
	-@update-desktop-database

.include <bsd.port.mk>
