# New ports collection makefile for:	Revelation
# Date created:				2004-08-10
# Whom:					ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	revelation
PORTVERSION=	0.4.11
PORTREVISION=	11
CATEGORIES=	security gnome
MASTER_SITES=	ftp://oss.codepoet.no/revelation/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Password manager for the GNOME 2 desktop

LIB_DEPENDS=	crack:${PORTSDIR}/security/cracklib
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pygnome2 pygnomeextras gnomeprefix gnomehack desktopfileutils \
		pygnomedesktop
USE_PYTHON=	yes
GCONF_SCHEMAS=	revelation.schemas revelation-applet.schemas
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_DISPLAY=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|\(rvl_py_version=\)".*$$|\1""|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\(-Wl\)|$$(LDFLAGS) \1|' \
		${WRKSRC}/src/wrap/crack/Makefile.in
	@${REINPLACE_CMD} -e 's|#include <crack.h>||' \
		${WRKSRC}/src/wrap/crack/crack.c.in

.include <bsd.port.mk>
