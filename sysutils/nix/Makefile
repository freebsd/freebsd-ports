PORTNAME=	nix
DISTVERSION=	2.31.1
CATEGORIES=	sysutils

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Purely functional package manager
WWW=		https://nixos.org/nix/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		jq:textproc/jq \
		nlohmann-json>=3.9:devel/nlohmann-json \
		toml11>=0:devel/toml11
LIB_DEPENDS=	libaws-cpp-sdk-core.so:devel/aws-sdk-cpp \
		libaws-crt-cpp.so:devel/aws-crt-cpp \
		libblake3.so:devel/libblake3 \
		libboost_context.so:devel/boost-libs \
		libbrotlienc.so:archivers/brotli \
		libcpuid.so:sysutils/libcpuid \
		libcurl.so:ftp/curl \
		libeditline.so:devel/editline \
		libgc-threaded.so:devel/boehm-gc-threaded \
		libgit2.so:devel/libgit2 \
		liblowdown.so:textproc/lowdown \
		libsodium.so:security/libsodium

USES=		bison cmake:indirect compiler:c++23-lang cpe libarchive localbase \
		meson ninja pkgconfig sqlite:3 ssl
USE_GITHUB=	yes
GH_ACCOUNT=	NixOS
USE_LDCONFIG=	yes

CPE_VENDOR=	nix_project

MESON_ARGS=	-Dbenchmarks=false \
		-Dbindings=false \
		-Dunit-tests=false
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

GROUPS=		nixbld

OPTIONS_DEFINE=		DOCS
DOCS_USES=		python:build
DOCS_MESON_TRUE=	doc-gen
DOCS_BUILD_DEPENDS=	mdbook-linkcheck>=0:textproc/mdbook-linkcheck \
			mdbook>=0:textproc/mdbook \
			rsync:net/rsync

_STRIP_TARGETS=	bin/nix bin/nix-build bin/nix-channel bin/nix-collect-garbage \
		bin/nix-copy-closure bin/nix-daemon bin/nix-env \
		bin/nix-instantiate bin/nix-prefetch-url bin/nix-store \
		lib/libnixexpr.so lib/libnixmain.so lib/libnixstore.so \
		lib/libnixutil.so lib/libnixcmd.so lib/libnixfetchers.so

post-patch:
	${REINPLACE_CMD} -e "/seccomp-sandboxing/s/,$$/, value : 'disabled',/" \
		${WRKSRC}/src/libstore/meson.options
	${REINPLACE_CMD} -e "/^bdw_gc/s/'bdw-gc'/'bdw-gc-threaded'/" \
		${WRKSRC}/src/libexpr/meson.build
	${FIND} ${WRKSRC} -type f -name meson.build | \
		${XARGS} ${GREP} -E -R -l 'Werror=(suggest-override|undef)|/dummy' | \
		${XARGS} ${REINPLACE_CMD} -E -e '/Werror=(suggest-override|undef)/d' \
			-e 's,/dummy,/tmp/dummy,g'

post-patch-DOCS-on:
	${REINPLACE_CMD} -E -e '/(internal|external)-api-docs/d' \
		${WRKSRC}/meson.build
	${FIND} ${WRKSRC} -type f -name 'book.toml.in' | ${XARGS} \
		${REINPLACE_CMD} -e "s,'python3','${PYTHON_CMD}'," \
			-e 's,"python3 ,"${PYTHON_CMD} ,' \
			${WRKSRC}/src/nix-manual/meson.build

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${FILESDIR}/add-nixbld-users ${STAGEDIR}${DATADIR}

	@${RM} ${STAGEDIR}${PREFIX}/libexec/nix/build-remote
	@${RLN} ${STAGEDIR}${PREFIX}/bin/nix ${STAGEDIR}${PREFIX}/libexec/nix/build-remote

	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} ${_STRIP_TARGETS}

.include <bsd.port.mk>
