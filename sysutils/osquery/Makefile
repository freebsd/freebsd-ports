PORTNAME=	osquery
DISTVERSION=	5.23.0
CATEGORIES=	sysutils
MASTER_SITES+=	https://github.com/ocochard/osquery/commit/:patches
DISTFILES+=	0c61e05a6.patch:patches
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		ocochard-linenoise-ng-2c90f29_GH0${EXTRACT_SUFX}

PATCH_SITES=	https://github.com/ocochard/osquery/commit/
PATCHFILES=	48489383b.patch:-p1 \
		410f2e4c1.patch:-p1 \
		3a9eca878.patch:-p1 \
		1adc6ed41.patch:-p1 \
		b8433155f.patch:-p1 \
		fb97abae5.patch:-p1 \
		797000ae7.patch:-p1

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	SQL powered operating system instrumentation and analytics
WWW=		https://osquery.io/

LICENSE=	APACHE20 GPLv2
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	osquery upstream only tests on x86_64 and aarch64

BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/include/rapidjson/document.h:devel/rapidjson \
		${LOCALBASE}/include/gtest/gtest_prod.h:devel/googletest
LIB_DEPENDS=	libaugeas.so:textproc/augeas \
		libxml2.so:textproc/libxml2 \
		liblz4.so:archivers/liblz4 \
		libboost_filesystem.so:devel/boost-libs \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		librocksdb.so:databases/rocksdb \
		libtsk.so:sysutils/sleuthkit \
		libthrift.so:devel/thrift-cpp \
		libyara.so:security/yara \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang localbase:ldflags \
		pkgconfig python:build,3.7+ sqlite ssl
USE_RC_SUBR=	osqueryd

USE_GITHUB=	yes
GH_ACCOUNT=	osquery
GH_TAGNAME=	${DISTVERSION}
GH_TUPLE=	ocochard:linenoise-ng:2c90f29:linenoiseng/libraries/cmake/source/linenoise-ng/src

EXTRA_PATCHES=	${WRKDIR}/0c61e05a6-freebsd.patch:-p1

CMAKE_OFF=	OSQUERY_BUILD_TESTS \
		OSQUERY_BUILD_BPF \
		OSQUERY_BUILD_DPKG \
		OSQUERY_BUILD_ETW \
		OSQUERY_BUILD_AWS

CMAKE_ARGS=	-DOSQUERY_TOOLCHAIN_SYSROOT= \
		-DOSQUERY_VERSION=${DISTVERSION}

PLIST_FILES=	bin/osqueryd \
		bin/osqueryi

post-extract:
	@${SED} \
		-e '/^diff --git a\/libraries\/cmake\/source\/linenoise-ng\/src/,/^diff --git/{/^diff --git a\/libraries\/cmake\/source\/linenoise-ng\/src/d; /^diff --git/!d;}' \
		${DISTDIR}/0c61e05a6.patch > ${WRKDIR}/0c61e05a6-freebsd.patch

.include <bsd.port.mk>
