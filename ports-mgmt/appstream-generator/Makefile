PORTNAME=	appstream-generator
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
PORTREVISION=	2
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

USES=		gnome libarchive meson pkgconfig

USE_GNOME=	glib20

USE_GITHUB=	yes
GH_ACCOUNT=	arrowd
GH_TAGNAME=	6645648126427ebdfe6debc45760ba8a351c3a5d

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
