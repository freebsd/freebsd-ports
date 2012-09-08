# New ports collection makefile for:	elementary
# Date created:				07 January 2010
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	elementary
PORTVERSION=	0.8.0.65643
CATEGORIES=	x11-toolkits enlightenment
MASTER_SITES=	http://download.enlightenment.org/snapshots/2011-11-28/ \
		http://files.roorback.net/e17/base/

MAINTAINER=	magik@roorback.net
COMMENT=	Simple widget toolkit using EFL

LICENSE=	LGPL21

LIB_DEPENDS=	lua-5.1:${PORTSDIR}/lang/lua

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	ecore embryo edje libtool_hack librt_hack modarch_hack
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CONFIGURE_ARGS=	--disable-install-examples

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${LN} -s profile.src ${WRKSRC}/config/profile.cfg
	@${LN} -s base.src ${WRKSRC}/config/default/base.cfg
	@${LN} -s base.src ${WRKSRC}/config/illume/base.cfg
	@${LN} -s base.src ${WRKSRC}/config/standard/base.cfg

post-install:
	@${RMDIR} ${PREFIX}/share/elementary/examples

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64: signal 10
.endif

.include <bsd.port.post.mk>
