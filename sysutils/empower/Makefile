# New ports collection makefile for:	empower
# Date created:		2006-08-14
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	empower
PORTVERSION=	20111128
CATEGORIES=	sysutils enlightenment
MASTER_SITES=	http://files.roorback.net/e17/extra/

MAINTAINER=	magik@roorback.net
COMMENT=	A graphical sudo tool based on the EFL

DIST_SUBDIR=	e17

RUN_DEPENDS=	sudo:${PORTSDIR}/security/sudo

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	evas ecore edje elementary
USE_EFL_ECORE=	file imf evas
USE_GNOME=	gnomehack pkgconfig
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
