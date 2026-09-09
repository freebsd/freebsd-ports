PORTNAME=	appstream-generator
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	ports-mgmt

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Fast AppStream metadata generator
WWW=		https://github.com/ximion/appstream-generator

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>=3:devel/nlohmann-json \
		inja>=3:devel/inja \
		catch2>0:devel/catch2 \
		${LOCALBASE}/include/__generator.hpp:devel/stdgenerator \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
		${LOCALBASE}/lib/cmake/quill/quill-config.cmake:devel/quill \
		docbook-xsl-ns>=0:textproc/docbook-xsl-ns
LIB_DEPENDS=	libappstream.so:devel/appstream \
		libappstream-compose.so:devel/appstream-compose \
		libCatch2.so:devel/catch2 \
		libcurl.so:ftp/curl \
		liblmdb.so:databases/lmdb0 \
		libicuuc.so:devel/icu \
		libtbb.so:devel/onetbb \
		libfyaml.so:textproc/libfyaml

USES=		compiler:c++23-lang gnome libarchive meson pkgconfig

USE_GNOME=	glib20 libxml2 libxslt:build
USE_CXXSTD=	c++23

USE_GITHUB=	yes
GH_ACCOUNT=	ximion

OPTIONS_DEFINE=		MANPAGES
MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt

MESON_ARGS=	-Dbackward=false

CFLAGS+=	-fexperimental-library

DATADIR=	${PREFIX}/share/appstream
OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == i386 || ${ARCH} == powerpc || ${ARCH:Marmv?}
post-patch:
	@${REINPLACE_CMD} -e "/tbb_dep/s|'tbb'|'tbb32'|" \
		${WRKSRC}/meson.build
.endif

post-install:
	cd ${WRKSRC}/data && \
		${COPYTREE_SHARE} templates ${STAGEDIR}${DATADIR}
	@${MKDIR} -p ${STAGEDIR}${PREFIX}/etc/poudriere.d/hooks
	${INSTALL_SCRIPT} ${PATCHDIR}/poudriere-hook-bulk.sh \
		${STAGEDIR}${PREFIX}/etc/poudriere.d/hooks/appstream-post-bulk.sh.sample

.include <bsd.port.post.mk>
