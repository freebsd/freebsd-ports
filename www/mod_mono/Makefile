# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	mod_mono
PORTVERSION=	3.12
CATEGORIES=	www
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Apache module for serving ASP.NET applications

LICENSE=	APACHE20

BUILD_DEPENDS=	mono:lang/mono \
		xsp:www/xsp
RUN_DEPENDS=	mono:lang/mono \
		xsp:www/xsp

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --man=${PREFIX}/man
INSTALL_TARGET=	install
USES=		libtool mono pkgconfig
USE_APACHE=	22+

.include <bsd.port.pre.mk>

MOD_MONOCONFDIR=${APACHEETCDIR}/Includes

PLIST_SUB+=	MOD_MONOCONFDIR=${MOD_MONOCONFDIR}

post-patch:
	@${REINPLACE_CMD} 's|%%MOD_MONOCONFDIR%%|${PREFIX}/${MOD_MONOCONFDIR}|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} '/^mod_mono_la_LDFLAGS =/s/$$/ -avoid-version/' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
