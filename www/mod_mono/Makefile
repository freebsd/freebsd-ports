PORTNAME=	mod_mono
PORTVERSION=	3.13
CATEGORIES=	www
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Apache module for serving ASP.NET applications

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xsp:www/xsp
RUN_DEPENDS=	xsp:www/xsp

USES=		apache:2.2+ libtool mono pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --man=${PREFIX}/man
INSTALL_TARGET=	install
PLIST_SUB=	MOD_MONOCONFDIR=${MOD_MONOCONFDIR}

MOD_MONOCONFDIR=${APACHEETCDIR}/Includes

post-patch:
	@${REINPLACE_CMD} 's|%%MOD_MONOCONFDIR%%|${PREFIX}/${MOD_MONOCONFDIR}|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} '/^mod_mono_la_LDFLAGS =/s/$$/ -avoid-version/' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
