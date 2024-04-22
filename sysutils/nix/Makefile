PORTNAME=	nix
DISTVERSION=	2.20.2
CATEGORIES=	sysutils

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Purely functional package manager
WWW=		https://nixos.org/nix/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/ax_cxx_compile_stdcxx.m4:devel/autoconf-archive \
		gsed:textproc/gsed \
		bash:shells/bash \
		docbook-xsl-ns>=0:textproc/docbook-xsl-ns \
		gnustat:sysutils/coreutils \
		grealpath:sysutils/coreutils \
		xmllint:textproc/libxml2 \
		xsltproc:textproc/libxslt \
		jq:textproc/jq \
		nlohmann-json>=3.9:devel/nlohmann-json
LIB_DEPENDS=	libaws-cpp-sdk-core.so:devel/aws-sdk-cpp \
		libaws-crt-cpp.so:devel/aws-crt-cpp \
		libboost_context.so:devel/boost-libs \
		libbrotlienc.so:archivers/brotli \
		libcurl.so:ftp/curl \
		libeditline.so:devel/editline \
		libgc.so:devel/boehm-gc \
		libsodium.so:security/libsodium \
		libcpuid.so:sysutils/libcpuid \
		libgit2.so:devel/libgit2 \
		liblowdown.so:textproc/lowdown
TEST_DEPENDS=	dot:graphics/graphviz \
		git:devel/git \
		gxargs:misc/findutils \
		hg:devel/mercurial

USES=		autoreconf bison compiler:c++17-lang cpe gmake localbase libarchive \
		pkgconfig sqlite:3 ssl
USE_GITHUB=	yes
GH_ACCOUNT=	NixOS
USE_LDCONFIG=	yes

CPE_VENDOR=	nix_project

HAS_CONFIGURE=		yes
# Workaround for bashisms in the configure script.
CONFIGURE_SHELL=	${_BASH}
CONFIGURE_ARGS=		--disable-seccomp-sandboxing \
			--enable-gc \
			--disable-unit-tests
CONFIGURE_ENV=		OPENSSL_CFLAGS="-I ${OPENSSLINC}" \
			OPENSSL_LIBS="-L ${OPENSSLLIB}"
# Workaround for:
#   /usr/bin/ld: error: undefined symbol: SHA512_Update
MAKE_ARGS=		libutil_ALLOW_UNDEFINED=yes
# XXX: Tests require the port to be installed on the system. It is not enough
# to have the port staged.
TEST_ARGS=		nix_tests="${_PASSING_TESTS}"
TEST_TARGET=		installcheck

# grealpath and gnustat are needed for tests.
BINARY_ALIAS=	realpath=grealpath stat=gnustat sed=gsed

SUB_FILES=	pkg-message

GROUPS=		nixbld

OPTIONS_DEFINE=	DOCS

DOCS_CONFIGURE_ENABLE=	doc-gen
DOCS_BUILD_DEPENDS=	mdbook>=0:textproc/mdbook \
			mdbook-linkcheck>=0:textproc/mdbook-linkcheck

_BASH=		${LOCALBASE}/bin/bash
_STRIP_TARGETS=	bin/nix bin/nix-build bin/nix-channel bin/nix-collect-garbage \
		bin/nix-copy-closure bin/nix-daemon bin/nix-env \
		bin/nix-instantiate bin/nix-prefetch-url bin/nix-store \
		lib/libnixexpr.so lib/libnixmain.so lib/libnixstore.so \
		lib/libnixutil.so lib/libnixcmd.so lib/libnixfetchers.so
# Regenerate the list of all tests with:
# make patch && make -f $(make -V WRKSRC)/tests/local.mk -V nix_tests

_ALL_TESTS=	test-infra.sh init.sh flakes/flakes.sh flakes/develop.sh \
		flakes/run.sh flakes/mercurial.sh flakes/circular.sh \
		flakes/init.sh flakes/inputs.sh flakes/follow-paths.sh \
		flakes/bundle.sh flakes/check.sh flakes/unlocked-override.sh \
		flakes/absolute-paths.sh flakes/absolute-attr-paths.sh \
		flakes/build-paths.sh flakes/flake-in-submodule.sh gc.sh \
		nix-collect-garbage-d.sh remote-store.sh legacy-ssh-store.sh \
		lang.sh lang-test-infra.sh experimental-features.sh \
		fetchMercurial.sh gc-auto.sh user-envs.sh \
		user-envs-migration.sh binary-cache.sh multiple-outputs.sh \
		nix-build.sh gc-concurrent.sh repair.sh fixed.sh export-graph.sh \
		timeout.sh fetchGitRefs.sh gc-runtime.sh tarball.sh fetchGit.sh \
		fetchurl.sh fetchPath.sh fetchTree-file.sh simple.sh referrers.sh \
		optimise-store.sh substitute-with-invalid-ca.sh signing.sh hash.sh \
		gc-non-blocking.sh check.sh nix-shell.sh check-refs.sh \
		build-remote-input-addressed.sh secure-drv-outputs.sh restricted.sh \
		fetchGitSubmodules.sh fetchGitVerification.sh flakes/search-root.sh \
		readfile-context.sh nix-channel.sh recursive.sh dependencies.sh \
		check-reqs.sh build-remote-content-addressed-fixed.sh \
		build-remote-content-addressed-floating.sh \
		build-remote-trustless-should-pass-0.sh \
		build-remote-trustless-should-pass-1.sh \
		build-remote-trustless-should-pass-2.sh \
		build-remote-trustless-should-pass-3.sh \
		build-remote-trustless-should-fail-0.sh \
		build-remote-with-mounted-ssh-ng.sh \
		nar-access.sh impure-eval.sh pure-eval.sh eval.sh repl.sh \
		binary-cache-build-remote.sh search.sh logging.sh export.sh config.sh \
		add.sh local-store.sh filter-source.sh misc.sh dump-db.sh \
		linux-sandbox.sh supplementary-groups.sh build-dry.sh \
		structured-attrs.sh shell.sh brotli.sh zstd.sh compression-levels.sh \
		nix-copy-ssh.sh nix-copy-ssh-ng.sh post-hook.sh function-trace.sh \
		flakes/config.sh fmt.sh eval-store.sh why-depends.sh derivation-json.sh \
		import-derivation.sh nix_path.sh case-hack.sh placeholders.sh \
		ssh-relay.sh build.sh build-delete.sh output-normalization.sh \
		selfref-gc.sh db-migration.sh bash-profile.sh pass-as-file.sh \
		nix-profile.sh suggestions.sh store-info.sh fetchClosure.sh completions.sh \
		flakes/show.sh impure-derivations.sh path-from-hash-part.sh path-info.sh \
		toString-path.sh read-only-store.sh nested-sandboxing.sh impure-env.sh \
		compute-levels.sh test-libstoreconsumer.sh plugins.sh

# Remove problematic tests from the list:
# - restricted.sh is hanging and never finishes.
_PASSING_TESTS=	${_ALL_TESTS:Nrestricted.sh}

post-patch:
	${REINPLACE_CMD} -e 's,=/dummy,=${WRKDIR}/dummy,g' \
		${WRKSRC}/doc/manual/local.mk

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${FILESDIR}/add-nixbld-users ${STAGEDIR}${DATADIR}

	@${RM} ${STAGEDIR}${PREFIX}/libexec/nix/build-remote
	@${RLN} ${STAGEDIR}${PREFIX}/bin/nix ${STAGEDIR}${PREFIX}/libexec/nix/build-remote

	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} ${_STRIP_TARGETS}

pre-test:
	${MKDIR} /tmp/nix-test

	${REINPLACE_CMD} -e 's| xargs | gxargs |g' ${WRKSRC}/tests/push-to-store.sh
	${REINPLACE_CMD} -e 's| touch | /usr/bin/touch |g' ${WRKSRC}/tests/timeout.nix
	${REINPLACE_CMD} -e 's| touch | /usr/bin/touch |g' ${WRKSRC}/tests/check-reqs.nix
	${REINPLACE_CMD} -e 's| touch | /usr/bin/touch |g' ${WRKSRC}/tests/nar-access.nix
	${REINPLACE_CMD} -e 's| touch | /usr/bin/touch |g' ${WRKSRC}/tests/pass-as-file.sh
	${REINPLACE_CMD} -e 's| date | ${LOCALBASE}/bin/gdate |g' ${WRKSRC}/tests/check.nix

	${REINPLACE_CMD} -e 's| wc -l)| /usr/bin/grep -c .)|g' ${WRKSRC}/tests/gc-auto.sh
	${REINPLACE_CMD} -e 's| tar c tarball)| tar -cf - tarball)|' ${WRKSRC}/tests/tarball.sh
	${REINPLACE_CMD} -e 's|^grep |/usr/bin/grep |' ${WRKSRC}/tests/check.sh

post-test:
	${RM} -r /tmp/nix-test

.include <bsd.port.mk>
