PORTNAME=	codex
DISTVERSIONPREFIX=	rust-v
DISTVERSION=	0.166.0
CATEGORIES=	misc devel
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTFILE_DEFAULT} \
		${DISTFILES:M*_cargo_*:C/:.*$//}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Lightweight coding agent that runs in your terminal
WWW=		https://openai.com/codex \
		https://github.com/openai/codex

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	fails to build: rustc-LLVM ERROR: out of memory

BUILD_DEPENDS=	gn:devel/gn \
		protoc:devel/protobuf
LIB_DEPENDS=	libzstd.so:archivers/zstd \
		libasound.so:audio/alsa-lib \
		libdbus-1.so:devel/dbus \
		libonig.so:devel/oniguruma
RUN_DEPENDS=	bash:shells/bash \
		rg:textproc/ripgrep
TEST_DEPENDS=	bash:shells/bash

USES=		cargo gnome llvm:min=21 ninja:build python:test shebangfix ssl

USE_GITHUB=	yes
GH_ACCOUNT=	openai

USE_GNOME=	glib20

SHEBANG_FILES=	\
		codex-rs/app-server-protocol/scripts/write_schema_fixtures.py \
		codex-rs/skills/src/assets/samples/imagegen/scripts/image_gen.py \
		codex-rs/skills/src/assets/samples/imagegen/scripts/remove_chroma_key.py \
		codex-rs/skills/src/assets/samples/skill-creator/scripts/generate_openai_yaml.py \
		codex-rs/skills/src/assets/samples/skill-creator/scripts/init_skill.py \
		codex-rs/skills/src/assets/samples/skill-creator/scripts/quick_validate.py \
		codex-rs/skills/src/assets/samples/skill-installer/scripts/github_utils.py \
		codex-rs/skills/src/assets/samples/skill-installer/scripts/install-skill-from-github.py \
		codex-rs/skills/src/assets/samples/skill-installer/scripts/list-skills.py \
		codex-rs/skills/tests/test_skill_installer.py \
		codex-rs/vendor/bubblewrap/demos/userns-block-fd.py \
		codex-rs/vendor/bubblewrap/tests/test-seccomp.py \
		codex-rs/vendor/bubblewrap/tests/use-as-subproject/assert-correct-rpath.py \
		codex-rs/windows-sandbox-rs/sandbox_smoketests.py

CARGO_CARGOTOML=	${BUILD_WRKSRC}/Cargo.toml
CARGO_CARGOLOCK=	${BUILD_WRKSRC}/Cargo.lock
CARGO_BUILD_ARGS=	--bin ${PORTNAME} \
			--bin ${PORTNAME}-code-mode-host \
			--bin ${PORTNAME}-responses-api-proxy
CARGO_TEST_ARGS=	--all-features --no-fail-fast
CARGO_ENV=		OPENSSL_NO_VENDOR=1 \
			V8_FROM_SOURCE=1 \
			GN=${LOCALBASE}/bin/gn \
			NINJA=${NINJA_CMD} \
			CLANG_BASE_PATH=${LLVM_PREFIX}

BINARY_ALIAS=	python3=${PYTHON_CMD} \
		cpp=${LOCALBASE}/bin/clang-cpp${LLVM_VERSION} \
		cc=${LOCALBASE}/bin/clang${LLVM_VERSION} \
		c++=${LOCALBASE}/bin/clang++${LLVM_VERSION} \
		ar=${LOCALBASE}/bin/llvm-ar${LLVM_VERSION} \
		nm=${LOCALBASE}/bin/llvm-nm${LLVM_VERSION} \
		ld=${LOCALBASE}/bin/ld.lld${LLVM_VERSION}
FETCH_CMD=	${SH} ${FILESDIR}/fetch-wrapper.sh
PORTSCOUT=	limit:^rust-v[0-9]\.

BUILD_WRKSRC=	${WRKSRC}/codex-rs

PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-code-mode-host \
		bin/${PORTNAME}-responses-api-proxy
PORTDOCS=	README.md config.md

OPTIONS_DEFINE=		COMPLETIONS DOCS
OPTIONS_DEFAULT=	COMPLETIONS

COMPLETIONS_DESC=	Build and/or install shell completions

COMPLETIONS_PLIST_FILES=etc/bash_completion.d/${PORTNAME} \
			share/fish/completions/${PORTNAME}.fish \
			share/zsh/site-functions/_${PORTNAME}

V8_GH_ACCOUNT=		seanh-oai
V8_GH_PROJECT=		rusty_v8
V8_GH_TAGNAME=		350c5a859a9b3c84ab8701b3ad51e3b7699b30c0
V8_SUBMODULES_TUPLE=	\
		https://github.com/denoland/chromium_build 2c779f961da7f5632d6836113112179e67938868 build build-2c779f961da7f5632d6836113112179e67938868.tar.gz \
		https://chromium.googlesource.com/chromium/src/buildtools 0d8a204ff274ee12fa9ace5e3ffd8e5fbcb54926 buildtools buildtools-0d8a204ff274ee12fa9ace5e3ffd8e5fbcb54926.tar.gz \
		https://chromium.googlesource.com/chromium/src/third_party/abseil-cpp d16e32215c3ab90ba57c2e904a5344d85c7353e4 third_party/abseil-cpp third_party__abseil__cpp-d16e32215c3ab90ba57c2e904a5344d85c7353e4.tar.gz \
		https://chromium.googlesource.com/external/github.com/jk-jeon/dragonbox beeeef91cf6fef89a4d4ba5e95d47ca64ccb3a44 third_party/dragonbox/src third_party__dragonbox__src-beeeef91cf6fef89a4d4ba5e95d47ca64ccb3a44.tar.gz \
		https://chromium.googlesource.com/external/github.com/fastfloat/fast_float 34164f547b7df3f5d794ff67e9f885c36819ebfc third_party/fast_float/src third_party__fast_float__src-34164f547b7df3f5d794ff67e9f885c36819ebfc.tar.gz \
		https://github.com/Maratyszcza/FP16 782eea126dc5c755827be751a099eb01826175cf third_party/fp16/src third_party__fp16__src-782eea126dc5c755827be751a099eb01826175cf.tar.gz \
		https://chromium.googlesource.com/external/github.com/google/highway 2607d3b5b0113992fe84d3848859eae13b3b52c1 third_party/highway/src third_party__highway__src-2607d3b5b0113992fe84d3848859eae13b3b52c1.tar.gz \
		https://chromium.googlesource.com/chromium/deps/icu d578f2e8b7bd5938e21cfb6bf15c079e0aa5b738 third_party/icu third_party__icu-d578f2e8b7bd5938e21cfb6bf15c079e0aa5b738.tar.gz \
		https://chromium.googlesource.com/chromium/src/third_party/jinja2 c3027d884967773057bf74b957e3fea87e5df4d7 third_party/jinja2 third_party__jinja2-c3027d884967773057bf74b957e3fea87e5df4d7.tar.gz \
		https://chromium.googlesource.com/external/github.com/llvm/llvm-project/libcxx b16984ce99c702355a5b2b4c52574e82cec41fb9 third_party/libc++/src third_party__libc______src-b16984ce99c702355a5b2b4c52574e82cec41fb9.tar.gz \
		https://chromium.googlesource.com/external/github.com/llvm/llvm-project/libcxxabi 8f11bb1d4438d0239d0dfc1bd9456a9f31629dda third_party/libc++abi/src third_party__libc____abi__src-8f11bb1d4438d0239d0dfc1bd9456a9f31629dda.tar.gz \
		https://chromium.googlesource.com/external/github.com/llvm/llvm-project/libunwind 1fd455816c724182cf8736811182bf0c37b03035 third_party/libunwind/src third_party__libunwind__src-1fd455816c724182cf8736811182bf0c37b03035.tar.gz \
		https://chromium.googlesource.com/external/github.com/llvm/llvm-project/libc 75ae50cd48c8a9d70f552ccff040029968778da9 third_party/llvm-libc/src third_party__llvm__libc__src-75ae50cd48c8a9d70f552ccff040029968778da9.tar.gz \
		https://chromium.googlesource.com/chromium/src/third_party/markupsafe 4256084ae14175d38a3ff7d739dca83ae49ccec6 third_party/markupsafe third_party__markupsafe-4256084ae14175d38a3ff7d739dca83ae49ccec6.tar.gz \
		https://chromium.googlesource.com/chromium/src/base/allocator/partition_allocator ff3b8b885b8374cbd3902642d94dc737bda93d5d third_party/partition_alloc third_party__partition_alloc-ff3b8b885b8374cbd3902642d94dc737bda93d5d.tar.gz \
		https://chromium.googlesource.com/chromium/src/third_party/rust afbc96607d0e659715d803cc099607dd1737fc41 third_party/rust third_party__rust-afbc96607d0e659715d803cc099607dd1737fc41.tar.gz \
		https://chromium.googlesource.com/chromium/src/third_party/simdutf f7356eed293f8208c40b3c1b344a50bd70971983 third_party/simdutf third_party__simdutf-f7356eed293f8208c40b3c1b344a50bd70971983.tar.gz \
		https://chromium.googlesource.com/chromium/src/tools/clang 56a7ab321b6840e949e3acf5f4528dadc6cb05bc tools/clang tools__clang-56a7ab321b6840e949e3acf5f4528dadc6cb05bc.tar.gz \
		https://chromium.googlesource.com/chromium/src/tools/win faefd1b6fa9eeb033ad6fe60368ccb9bf908cbd0 tools/win tools__win-faefd1b6fa9eeb033ad6fe60368ccb9bf908cbd0.tar.gz \
		https://github.com/denoland/v8 c4ca1eccb90c5464d826b7713dc27178a53b0cfe v8 v8-c4ca1eccb90c5464d826b7713dc27178a53b0cfe.tar.gz

.for url commit_hash path archive in ${V8_SUBMODULES_TUPLE}
.   if ${url:Mhttps\://github.com/*}
MASTER_SITES+=	${url:S|$|/archive/${commit_hash}${EXTRACT_SUFX}?dummy=/|}:_v8_submodule_${path:C|[^a-zA-Z0-9_]|__|g}
.   elif ${url:Mhttps\://*googlesource.com/*}
MASTER_SITES+=	${url:S|$|/+archive/${commit_hash}${EXTRACT_SUFX}?dummy=/|}:_v8_submodule_${path:C|[^a-zA-Z0-9_]|__|g}
.   endif
DISTFILES+=	${archive}:_v8_submodule_${path:C|[^a-zA-Z0-9_]|__|g}
.endfor

post-extract:
.for _ _ path archive in ${V8_SUBMODULES_TUPLE}
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_SUBDIR}/${archive} \
		${EXTRACT_AFTER_ARGS} -C ${WRKSRC_crate_v8}/${path}
.endfor

post-patch:
	@${BSDMAKE} PATCHDIR=${PATCHDIR}/mxc-sdk \
		WRKSRC=${WRKSRC_crate_mxc-sdk} do-patch
	@${BSDMAKE} PATCHDIR=${PATCHDIR}/rusty_v8 \
		WRKSRC=${WRKSRC_crate_v8} do-patch
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}&|' \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/environment_info.rs \
		${BUILD_WRKSRC}/cli/src/debug_sandbox/pid_tracker.rs \
		${BUILD_WRKSRC}/cli/tests/exec_server/pid_namespace_tests.rs \
		${BUILD_WRKSRC}/core/src/command_canonicalization.rs \
		${BUILD_WRKSRC}/core/src/command_canonicalization_tests.rs \
		${BUILD_WRKSRC}/core/src/context/world_state/environment_render_tests.rs \
		${BUILD_WRKSRC}/core/src/exec_policy.rs \
		${BUILD_WRKSRC}/core/src/exec_policy_tests.rs \
		${BUILD_WRKSRC}/core/src/exec_tests.rs \
		${BUILD_WRKSRC}/core/src/shell_snapshot_tests.rs \
		${BUILD_WRKSRC}/core/src/shell_tests.rs \
		${BUILD_WRKSRC}/core/src/tasks/user_shell_tests.rs \
		${BUILD_WRKSRC}/core/src/tools/handlers/unified_exec_tests.rs \
		${BUILD_WRKSRC}/core/src/tools/runtimes/mod.rs \
		${BUILD_WRKSRC}/core/src/tools/runtimes/mod_tests.rs \
		${BUILD_WRKSRC}/core/src/tools/sandboxing_tests.rs \
		${BUILD_WRKSRC}/core/src/unified_exec/process_manager_tests.rs \
		${BUILD_WRKSRC}/core/tests/suite/exec.rs \
		${BUILD_WRKSRC}/core/tests/suite/executor_discovery_v2.rs \
		${BUILD_WRKSRC}/core/tests/suite/guardian_review.rs \
		${BUILD_WRKSRC}/core/tests/suite/shell_snapshot.rs \
		${BUILD_WRKSRC}/core/tests/suite/unified_exec.rs \
		${BUILD_WRKSRC}/core/tests/suite/unified_exec_process_events.rs \
		${BUILD_WRKSRC}/core/tests/suite/unified_exec_stdin_approval.rs \
		${BUILD_WRKSRC}/core/tests/suite/unified_exec_stdin_review_size.rs \
		${BUILD_WRKSRC}/core/tests/suite/user_notification.rs \
		${BUILD_WRKSRC}/exec-server/src/environment/discovery_v2_tests.rs \
		${BUILD_WRKSRC}/exec-server/src/process_sandbox_tests.rs \
		${BUILD_WRKSRC}/exec-server/src/shell_snapshot_file_tests.rs \
		${BUILD_WRKSRC}/exec-server/src/shell_snapshot_tests.rs \
		${BUILD_WRKSRC}/exec-server/tests/common/fake_bwrap.rs \
		${BUILD_WRKSRC}/exec-server/tests/exec_process.rs \
		${BUILD_WRKSRC}/hooks/src/engine/command_runner_tests.rs \
		${BUILD_WRKSRC}/shell-command/src/parse_command.rs \
		${BUILD_WRKSRC}/shell-command/src/shell_detect.rs \
		${BUILD_WRKSRC}/shell-command/src/shell_snapshot_tests.rs \
		${BUILD_WRKSRC}/tui/src/exec_command.rs \
		${BUILD_WRKSRC}/utils/path-uri/src/tests.rs
	@${REINPLACE_CMD} -e 's|python3|${PYTHON_VERSION}|' \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/command_exec.rs \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/guardian_action_budget_tests.rs \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/guardian_v2.rs \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/hooks_list.rs \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/session_end.rs \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/thread_queue.rs \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/thread_resume.rs \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/thread_shell_command.rs \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/turn_interrupt.rs \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/turn_start.rs \
		${BUILD_WRKSRC}/cli/tests/sandbox_tty.rs \
		${BUILD_WRKSRC}/config/src/config_requirements.rs \
		${BUILD_WRKSRC}/config/src/hooks_tests.rs \
		${BUILD_WRKSRC}/core-plugins/src/script_attribution.rs \
		${BUILD_WRKSRC}/core-plugins/src/script_attribution_tests.rs \
		${BUILD_WRKSRC}/core/src/command_canonicalization_tests.rs \
		${BUILD_WRKSRC}/core/src/config/config_loader_tests.rs \
		${BUILD_WRKSRC}/core/src/exec_policy.rs \
		${BUILD_WRKSRC}/core/src/exec_policy_tests.rs \
		${BUILD_WRKSRC}/core/src/mcp_tool_call_tests.rs \
		${BUILD_WRKSRC}/core/src/session/tests.rs \
		${BUILD_WRKSRC}/core/tests/suite/approvals.rs \
		${BUILD_WRKSRC}/core/tests/suite/code_mode.rs \
		${BUILD_WRKSRC}/core/tests/suite/compact.rs \
		${BUILD_WRKSRC}/core/tests/suite/dynamic_tool_cancellation.rs \
		${BUILD_WRKSRC}/core/tests/suite/exec.rs \
		${BUILD_WRKSRC}/core/tests/suite/guardian_mcp_elicitation.rs \
		${BUILD_WRKSRC}/core/tests/suite/hooks.rs \
		${BUILD_WRKSRC}/core/tests/suite/hooks_cwd_tests.rs \
		${BUILD_WRKSRC}/core/tests/suite/hooks_mcp.rs \
		${BUILD_WRKSRC}/core/tests/suite/interrupt_hooks.rs \
		${BUILD_WRKSRC}/core/tests/suite/mcp_subagent_elicitation.rs \
		${BUILD_WRKSRC}/core/tests/suite/mcp_user_verification.rs \
		${BUILD_WRKSRC}/core/tests/suite/network_approval.rs \
		${BUILD_WRKSRC}/core/tests/suite/openai_file_mcp.rs \
		${BUILD_WRKSRC}/core/tests/suite/remote_env.rs \
		${BUILD_WRKSRC}/core/tests/suite/subagent_notifications.rs \
		${BUILD_WRKSRC}/core/tests/suite/token_budget.rs \
		${BUILD_WRKSRC}/core/tests/suite/tool_lifecycle.rs \
		${BUILD_WRKSRC}/core/tests/suite/unified_exec.rs \
		${BUILD_WRKSRC}/exec-server/tests/exec_process.rs \
		${BUILD_WRKSRC}/exec/tests/suite/sandbox.rs \
		${BUILD_WRKSRC}/exec/tests/suite/seatbelt.rs \
		${BUILD_WRKSRC}/execpolicy/tests/basic.rs \
		${BUILD_WRKSRC}/ext/queue/tests/queue_service.rs \
		${BUILD_WRKSRC}/external-agent-migration/src/lib_tests.rs \
		${BUILD_WRKSRC}/hooks/src/engine/command_runner_tests.rs \
		${BUILD_WRKSRC}/hooks/src/engine/mod_tests.rs \
		${BUILD_WRKSRC}/hooks/src/events/compact.rs \
		${BUILD_WRKSRC}/hooks/src/events/post_tool_use.rs \
		${BUILD_WRKSRC}/linux-sandbox/tests/suite/daemon_sockets_tests.rs \
		${BUILD_WRKSRC}/linux-sandbox/tests/suite/managed_proxy.rs \
		${BUILD_WRKSRC}/linux-sandbox/tests/suite/managed_proxy_unix_sockets_tests.rs \
		${BUILD_WRKSRC}/linux-sandbox/tests/suite/sandbox.rs \
		${BUILD_WRKSRC}/memories/write/src/startup_tests.rs \
		${BUILD_WRKSRC}/rmcp-client/tests/stdio_descriptor_boundary.rs \
		${BUILD_WRKSRC}/rmcp-client/tests/stdio_stderr_cleanup.rs \
		${BUILD_WRKSRC}/sandboxing/src/seatbelt_daemon_socket_tests.rs \
		${BUILD_WRKSRC}/skills/src/invocation.rs \
		${BUILD_WRKSRC}/skills/src/invocation_tests.rs \
		${BUILD_WRKSRC}/tui/src/app/tests.rs \
		${BUILD_WRKSRC}/tui/src/chatwidget/tests/app_server.rs \
		${BUILD_WRKSRC}/tui/src/chatwidget/tests/approval_requests.rs \
		${BUILD_WRKSRC}/tui/src/debug_config.rs \
		${BUILD_WRKSRC}/tui/src/exec_command.rs \
		${BUILD_WRKSRC}/tui/src/render/highlight.rs \
		${BUILD_WRKSRC}/utils/pty/src/tests.rs

post-build-COMPLETIONS-on:
	@${MKDIR} ${WRKSRC}/completions
.for sh in bash fish zsh
	${CARGO_TARGET_DIR}/*/${PORTNAME} completion ${sh} > \
		${WRKSRC}/completions/${PORTNAME}.${sh}
.endfor

do-install:
.for prog in ${PLIST_FILES:Mbin/*:T}
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/*/${prog} \
		${STAGEDIR}${PREFIX}/bin
.endfor

do-install-COMPLETIONS-on:
	@${MKDIR} ${COMPLETIONS_PLIST_FILES:H:S|^|${STAGEDIR}${PREFIX}/|}
.for sh in bash fish zsh
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.${sh} \
		${COMPLETIONS_PLIST_FILES:M*${sh}*:S|^|${STAGEDIR}${PREFIX}/|}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${BUILD_WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

# Use ThinLTO for test binaries while retaining the normal dependency cache.
# Disabling LTO for the whole Cargo profile would rebuild every dependency.
fast-build: configure
.for crate bin in ${PORTNAME}-cli ${PORTNAME} \
	${PORTNAME}-code-mode-host ${PORTNAME}-code-mode-host \
	${PORTNAME}-responses-api-proxy ${PORTNAME}-responses-api-proxy
	@${CARGO_CARGO_RUN} ${RUSTC} --manifest-path ${CARGO_CARGOTOML} \
		--offline --release -p ${crate} --bin ${bin} -- \
		-C lto=thin -C codegen-units=16
.endfor

#
# target for port maintainer(s)
#
generate-v8-submodules-tuple:
	@${SH} ${FILESDIR}/generate-submodules-tuple.sh \
		${V8_GH_ACCOUNT} ${V8_GH_PROJECT} ${V8_GH_TAGNAME}

.include <bsd.port.mk>
