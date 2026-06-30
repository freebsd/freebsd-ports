PORTNAME=	codex
DISTVERSIONPREFIX=	rust-v
DISTVERSION=	0.142.4
CATEGORIES=	misc devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Lightweight coding agent that runs in your terminal
WWW=		https://openai.com/codex \
		https://github.com/openai/codex

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	fails to build: rustc-LLVM ERROR: out of memory

BUILD_DEPENDS=	gn:devel/gn \
		icu>0:devel/icu
LIB_DEPENDS=	libzstd.so:archivers/zstd \
		libasound.so:audio/alsa-lib \
		libdbus-1.so:devel/dbus \
		libonig.so:devel/oniguruma
RUN_DEPENDS=	bash:shells/bash \
		rg:textproc/ripgrep
TEST_DEPENDS=	bash:shells/bash

USES=		cargo gnome llvm:min=21 ninja:build python:test \
		shebangfix ssl

USE_GITHUB=	yes
GH_ACCOUNT=	openai

USE_GNOME=	glib20

SHEBANG_FILES=	codex-rs/skills/src/assets/samples/imagegen/scripts/image_gen.py \
		codex-rs/skills/src/assets/samples/imagegen/scripts/remove_chroma_key.py \
		codex-rs/skills/src/assets/samples/plugin-creator/scripts/create_basic_plugin.py \
		codex-rs/skills/src/assets/samples/plugin-creator/scripts/read_marketplace_name.py \
		codex-rs/skills/src/assets/samples/plugin-creator/scripts/update_plugin_cachebuster.py \
		codex-rs/skills/src/assets/samples/plugin-creator/scripts/validate_plugin.py \
		codex-rs/skills/src/assets/samples/skill-creator/scripts/generate_openai_yaml.py \
		codex-rs/skills/src/assets/samples/skill-creator/scripts/init_skill.py \
		codex-rs/skills/src/assets/samples/skill-creator/scripts/quick_validate.py \
		codex-rs/skills/src/assets/samples/skill-installer/scripts/github_utils.py \
		codex-rs/skills/src/assets/samples/skill-installer/scripts/install-skill-from-github.py \
		codex-rs/skills/src/assets/samples/skill-installer/scripts/list-skills.py \
		codex-rs/vendor/bubblewrap/demos/userns-block-fd.py \
		codex-rs/vendor/bubblewrap/tests/test-seccomp.py \
		codex-rs/vendor/bubblewrap/tests/use-as-subproject/assert-correct-rpath.py

CARGO_CARGOTOML=	${BUILD_WRKSRC}/Cargo.toml
CARGO_CARGOLOCK=	${BUILD_WRKSRC}/Cargo.lock
CARGO_BUILD_ARGS=	--bin ${PORTNAME} \
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

BUILD_WRKSRC=	${WRKSRC}/codex-rs

PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-responses-api-proxy
PORTDOCS=	README.md config.md

OPTIONS_DEFINE=		COMPLETIONS DOCS
OPTIONS_DEFAULT=	COMPLETIONS

COMPLETIONS_DESC=	Build and/or install shell completions

COMPLETIONS_PLIST_FILES=etc/bash_completion.d/${PORTNAME} \
			share/fish/completions/${PORTNAME}.fish \
			share/zsh/site-functions/_${PORTNAME}

post-configure:
	@${MKDIR} ${WRKSRC_crate_v8}/third_party/icu/common
.for suffix in l b
	@if [ -r ${LOCALBASE}/share/icu/*/icudt*${suffix}.dat ]; then \
		${CP} ${LOCALBASE}/share/icu/*/icudt*${suffix}.dat \
			${WRKSRC_crate_v8}/third_party/icu/common/icudt${suffix}.dat; \
	fi
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}&|' \
		${BUILD_WRKSRC}/cli/src/debug_sandbox/pid_tracker.rs \
		${BUILD_WRKSRC}/core/src/command_canonicalization.rs \
		${BUILD_WRKSRC}/core/src/command_canonicalization_tests.rs \
		${BUILD_WRKSRC}/core/src/context/world_state/environment_render_tests.rs \
		${BUILD_WRKSRC}/core/src/exec_policy.rs \
		${BUILD_WRKSRC}/core/src/exec_policy_tests.rs \
		${BUILD_WRKSRC}/core/src/exec_tests.rs \
		${BUILD_WRKSRC}/core/src/shell_snapshot_tests.rs \
		${BUILD_WRKSRC}/core/src/shell_tests.rs \
		${BUILD_WRKSRC}/core/src/tasks/user_shell_tests.rs \
		${BUILD_WRKSRC}/core/src/tools/handlers/shell_tests.rs \
		${BUILD_WRKSRC}/core/src/tools/handlers/unified_exec_tests.rs \
		${BUILD_WRKSRC}/core/src/tools/runtimes/mod.rs \
		${BUILD_WRKSRC}/core/src/tools/runtimes/mod_tests.rs \
		${BUILD_WRKSRC}/core/src/tools/sandboxing_tests.rs \
		${BUILD_WRKSRC}/core/tests/suite/exec.rs \
		${BUILD_WRKSRC}/core/tests/suite/guardian_review.rs \
		${BUILD_WRKSRC}/core/tests/suite/unified_exec.rs \
		${BUILD_WRKSRC}/core/tests/suite/user_notification.rs \
		${BUILD_WRKSRC}/exec-server/src/process_sandbox_tests.rs \
		${BUILD_WRKSRC}/exec-server/tests/file_system_unix.rs \
		${BUILD_WRKSRC}/shell-command/src/parse_command.rs \
		${BUILD_WRKSRC}/shell-command/src/shell_detect.rs \
		${BUILD_WRKSRC}/shell-escalation/src/unix/escalate_server.rs \
		${BUILD_WRKSRC}/tui/src/exec_command.rs \
		${BUILD_WRKSRC}/utils/path-uri/src/tests.rs
	@${REINPLACE_CMD} -e 's|python3|${PYTHON_VERSION}|' \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/command_exec.rs \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/hooks_list.rs \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/thread_resume.rs \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/thread_shell_command.rs \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/turn_interrupt.rs \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/turn_start.rs \
		${BUILD_WRKSRC}/app-server/tests/suite/v2/turn_start_zsh_fork.rs \
		${BUILD_WRKSRC}/config/src/config_requirements.rs \
		${BUILD_WRKSRC}/config/src/hooks_tests.rs \
		${BUILD_WRKSRC}/core-skills/src/invocation_utils.rs \
		${BUILD_WRKSRC}/core-skills/src/invocation_utils_tests.rs \
		${BUILD_WRKSRC}/core/src/command_canonicalization_tests.rs \
		${BUILD_WRKSRC}/core/src/config/config_loader_tests.rs \
		${BUILD_WRKSRC}/core/src/exec_policy.rs \
		${BUILD_WRKSRC}/core/src/exec_policy_tests.rs \
		${BUILD_WRKSRC}/core/src/mcp_tool_call_tests.rs \
		${BUILD_WRKSRC}/core/src/session/tests.rs \
		${BUILD_WRKSRC}/core/tests/suite/approvals.rs \
		${BUILD_WRKSRC}/core/tests/suite/code_mode.rs \
		${BUILD_WRKSRC}/core/tests/suite/compact.rs \
		${BUILD_WRKSRC}/core/tests/suite/compact_remote_parity.rs \
		${BUILD_WRKSRC}/core/tests/suite/exec.rs \
		${BUILD_WRKSRC}/core/tests/suite/hooks.rs \
		${BUILD_WRKSRC}/core/tests/suite/hooks_mcp.rs \
		${BUILD_WRKSRC}/core/tests/suite/network_approval.rs \
		${BUILD_WRKSRC}/core/tests/suite/openai_file_mcp.rs \
		${BUILD_WRKSRC}/core/tests/suite/subagent_notifications.rs \
		${BUILD_WRKSRC}/core/tests/suite/tools.rs \
		${BUILD_WRKSRC}/core/tests/suite/unified_exec.rs \
		${BUILD_WRKSRC}/exec-server/tests/exec_process.rs \
		${BUILD_WRKSRC}/exec/tests/suite/sandbox.rs \
		${BUILD_WRKSRC}/execpolicy/tests/basic.rs \
		${BUILD_WRKSRC}/external-agent-migration/src/lib.rs \
		${BUILD_WRKSRC}/hooks/src/engine/mod_tests.rs \
		${BUILD_WRKSRC}/hooks/src/events/compact.rs \
		${BUILD_WRKSRC}/hooks/src/events/post_tool_use.rs \
		${BUILD_WRKSRC}/linux-sandbox/tests/suite/landlock.rs \
		${BUILD_WRKSRC}/linux-sandbox/tests/suite/managed_proxy.rs \
		${BUILD_WRKSRC}/shell-command/src/bash.rs \
		${BUILD_WRKSRC}/shell-command/src/command_safety/is_safe_command.rs \
		${BUILD_WRKSRC}/tui/src/app/tests.rs \
		${BUILD_WRKSRC}/tui/src/chatwidget/tests/app_server.rs \
		${BUILD_WRKSRC}/tui/src/chatwidget/tests/approval_requests.rs \
		${BUILD_WRKSRC}/tui/src/chatwidget/tests/exec_flow.rs \
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
.for prog in ${PORTNAME} ${PORTNAME}-responses-api-proxy
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/*/${prog} \
		${STAGEDIR}${PREFIX}/bin
.endfor

do-install-COMPLETIONS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/fish/completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${BUILD_WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
