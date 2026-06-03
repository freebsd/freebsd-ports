PORTNAME=	appstream-generator
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.2
PORTREVISION=	4
CATEGORIES=	ports-mgmt
MASTER_SITES=	LOCAL/arrowd/:assets
DISTFILES=	${_ASSETS_DISTNAME}${EXTRACT_SUFX}:assets

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Fast AppStream metadata generator
WWW=		https://github.com/ximion/appstream-generator

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>=3:devel/nlohmann-json \
		inja>=3:devel/inja \
		catch2>0:devel/catch2 \
		${LOCALBASE}/include/__generator.hpp:devel/stdgenerator \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl
LIB_DEPENDS=	libappstream.so:devel/appstream \
		libappstream-compose.so:devel/appstream-compose \
		libCatch2.so:devel/catch2 \
		libcurl.so:ftp/curl \
		liblmdb.so:databases/lmdb \
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
# only needed to fool meson
BINARY_ALIAS=	npm=true

_ASSETS_DISTNAME=${PORTNAME}-js-assets-${_ASSETS_VERSION}
_ASSETS_VERSION=${PORTVERSION}

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

repackage-js:
	pkg info npm > /dev/null
	cd ${WRKSRC}/contrib/setup && ./build_js.sh
	cd ${WRKDIR} && ${TAR} -czf /tmp/${_ASSETS_DISTNAME}${EXTRACT_SUFX} \
		${WRKSRC:T}/data/templates/default/static/js
	@cd /tmp && sha256 ${_ASSETS_DISTNAME}${EXTRACT_SUFX} \
		&& ${ECHO_CMD} -n "SIZE (${_ASSETS_DISTNAME}${EXTRACT_SUFX}) = " \
		&& ${STAT} -f %z ${_ASSETS_DISTNAME}${EXTRACT_SUFX} \

.include <bsd.port.post.mk>
