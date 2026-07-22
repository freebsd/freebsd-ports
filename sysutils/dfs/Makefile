PORTNAME=	dfs
DISTVERSION=	0.8.2
CATEGORIES=	sysutils

MAINTAINER=	slowdive@me.com
COMMENT=	Config manager with a true two-way synchronization
WWW=		https://codeberg.org/charlesrocket/dfs

LICENSE=	Apache-2.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		zig:016

USE_FORGEJO=	yes
FJ_ACCOUNT=	charlesrocket

PLIST_FILES+=	bin/dfs \
		share/icons/hicolor/symbolic/apps/dfs-symbolic.svg

OPTIONS_DEFINE=			DBUS
OPTIONS_DEFAULT=		BASH DBUS ZSH
OPTIONS_GROUP=			COMPLETION
OPTIONS_GROUP_COMPLETION=	BASH ZSH

DBUS_DESC=	System tray support
BASH_DESC=	Install BASH completion
ZSH_DESC=	Install ZSH completion

_MAN_PAGES=	dfs-daemon.1 dfs-init-bootstrap.1 dfs-init.1 dfs-purge.1 \
		dfs-sync.1 dfs-validate.1 dfs-version.1 dfs.1

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_ZIG_BOOL=		dbus
.for mp in ${_MAN_PAGES}
DBUS_PLIST_FILES+=	share/man/man1/${mp}.gz
.endfor

BASH_PLIST_FILES=	share/bash-completion/completions/dfs-completion.bash
ZSH_PLIST_FILES=	share/zsh/site-functions/_dfs-completion.zsh

post-build:
	@cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${ZIG_ENV} ${ZIG_CMD} build ${_MAKE_JOBS} ${ZIG_ARGS} docs-meta

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dfs
	${RM} ${STAGEDIR}${PREFIX}/bin/cova_generator_dfs

post-install-DBUS-on:
.for mp in ${_MAN_PAGES}
	${INSTALL_MAN} ${WRKSRC}/meta/help_docs/manpages/${mp} \
		${STAGEDIR}${PREFIX}/share/man/man1
.endfor

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/meta/tab_completions/dfs-completion.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/dfs-completion.bash

post-install-ZSH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/meta/tab_completions/_dfs-completion.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_dfs-completion.zsh

do-test:
	@cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} zig build test ${ZIG_ARGS}

.include <bsd.port.mk>
