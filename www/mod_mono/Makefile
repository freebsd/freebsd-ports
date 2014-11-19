# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	mod_mono
PORTVERSION=	3.8
CATEGORIES=	www
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Apache module for serving ASP.NET applications

LICENSE=	APACHE20

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		xsp:${PORTSDIR}/www/xsp
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		xsp:${PORTSDIR}/www/xsp

USES=		libtool:oldver mono pkgconfig
GNU_CONFIGURE=	yes
USE_APACHE=	22+
CONFIGURE_ARGS=	--man=${PREFIX}/man
INSTALL_TARGET=	install

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} == 13
MOD_MONOCONFDIR=${APACHEETCDIR}
.else
MOD_MONOCONFDIR=${APACHEETCDIR}/Includes
.endif

PLIST_SUB+=	MOD_MONOCONFDIR=${MOD_MONOCONFDIR}

post-patch:
	@${REINPLACE_CMD} 's|%%MOD_MONOCONFDIR%%|${PREFIX}/${MOD_MONOCONFDIR}|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
