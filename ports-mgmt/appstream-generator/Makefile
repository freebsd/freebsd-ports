PORTNAME=	appstream-generator
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
PORTREVISION=	3
CATEGORIES=	ports-mgmt

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Fast AppStream metadata generator
WWW=		https://github.com/ximion/appstream-generator

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	girtod:lang/gir-to-d \
		ldc2:lang/ldc \
		xsltproc:textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl
LIB_DEPENDS=	libappstream.so:devel/appstream \
		libappstream-compose.so:devel/appstream-compose \
		libcurl.so:ftp/curl \
		libglibd-2.0.so:devel/glibd \
		liblmdb.so:databases/lmdb \
		libphobos2-ldc-shared.so:lang/ldc
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme

USES=		gnome libarchive meson pkgconfig

USE_GNOME=	glib20

USE_GITHUB=	yes
GH_ACCOUNT=	arrowd
GH_TAGNAME=	5e71cac08bae0aa8e812f5dc5508b3b501ee5678

OPTIONS_DEFINE=		MANPAGES
MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt

MESON_ARGS=	-Ddownload-js=false -Dlocalbase=${LOCALBASE} -Drpmmd=false

DATADIR=	${PREFIX}/share/appstream
OPTIONS_SUB=	yes

PIE_UNSAFE=	yes

post-install:
	cd ${WRKSRC}/data && \
		${COPYTREE_SHARE} templates ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${PATCHDIR}/poudriere-hook-bulk.sh ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
