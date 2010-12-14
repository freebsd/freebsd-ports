# New ports collection makefile for:	elementary
# Date created:				07 January 2010
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	elementary
PORTVERSION=	0.7.0.52995
CATEGORIES=	x11-toolkits enlightenment
MASTER_SITES=	http://files.roorback.net/e17/2010-10-03/base/

MAINTAINER=	magik@roorback.net
COMMENT=	Simple widget toolkit using EFL

LIB_DEPENDS=	lua-5.1:${PORTSDIR}/lang/lua

LICENSE=	LGPL21
DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	ecore embryo edje libtool_hack librt_hack modarch_hack
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

post-patch:
	${LN} -s profile.src ${WRKSRC}/config/profile.cfg
	${LN} -s base.src ${WRKSRC}/config/default/base.cfg
	${LN} -s base.src ${WRKSRC}/config/illume/base.cfg
	${LN} -s base.src ${WRKSRC}/config/standard/base.cfg

.include <bsd.port.mk>
