PORTNAME=	elephant
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1
CATEGORIES=	sysutils

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Powerful data provider service and backend for application launchers
WWW=		https://github.com/abenz1267/elephant

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		aarch64 armv7 i386
NOT_FOR_ARCHS_REASON=	-buildmode=plugin not supported on these architectures

USES=		go:modules

GO_MODULE=	github.com/abenz1267/elephant/v2
GO_TARGET=	./cmd/elephant

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	${OPTIONS_GROUP_PROVIDERS:NNIRISESSIONS}
OPTIONS_GROUP=		PROVIDERS
OPTIONS_GROUP_PROVIDERS=CALC CLIPBOARD DESKTOPAPPLICATIONS FILES MENUS \
			NIRISESSIONS PROVIDERLIST RUNNER SNIPPETS SYMBOLS \
			TODO UNICODE WEBSEARCH WINDOWS

PROVIDERS_DESC=		Enabled providers
CALC_DESC=		Perform calculation and unit-conversions
CLIPBOARD_DESC=		Store clipboard history
DESKTOPAPPLICATIONS_DESC=Run installed desktop applications
FILES_DESC=		Find files/folders
NIRISESSIONS_DESC=	Create predefined session layouts and open them
MENUS_DESC=		Create custom menus
PROVIDERLIST_DESC=	Lists all providers and configured menus
RUNNER_DESC=		Execute everything installed in your PATH
SNIPPETS_DESC=		Create and access text snippets
SYMBOLS_DESC=		Search for emojis and symbols
TODO_DESC=		Basic Todolist
UNICODE_DESC=		Search for unicode symbols
WEBSEARCH_DESC=		Search web with custom defined search engines
WINDOWS_DESC=		Find and focus opened windows

CALC_RUN_DEPENDS=	qalc:math/libqalculate \
			wl-copy:x11/wl-clipboard
CALC_PLIST_FILES=	etc/xdg/elephant/providers/calc.so
CLIPBOARD_RUN_DEPENDS=	wl-copy:x11/wl-clipboard
CLIPBOARD_PLIST_FILES=	etc/xdg/elephant/providers/clipboard.so
DESKTOPAPPLICATIONS_PLIST_FILES=etc/xdg/elephant/providers/desktopapplications.so
FILES_RUN_DEPENDS=	fd:sysutils/fd
FILES_PLIST_FILES=	etc/xdg/elephant/providers/files.so
MENUS_PLIST_FILES=	etc/xdg/elephant/providers/menus.so
NIRISESSIONS_RUN_DEPENDS=niri:x11-wm/niri
NIRISESSIONS_PLIST_FILES=etc/xdg/elephant/providers/nirisessions.so
PROVIDERLIST_PLIST_FILES=etc/xdg/elephant/providers/providerlist.so
RUNNER_PLIST_FILES=	etc/xdg/elephant/providers/runner.so
SNIPPETS_RUN_DEPENDS=	wtype:x11/wtype
SNIPPETS_PLIST_FILES=	etc/xdg/elephant/providers/snippets.so
SYMBOLS_RUN_DEPENDS=	wl-copy:x11/wl-clipboard
SYMBOLS_PLIST_FILES=	etc/xdg/elephant/providers/symbols.so
TODO_RUN_DEPENDS=	notify-send:devel/libnotify
TODO_PLIST_FILES=	etc/xdg/elephant/providers/todo.so
UNICODE_RUN_DEPENDS=	wl-copy:x11/wl-clipboard
UNICODE_PLIST_FILES=	etc/xdg/elephant/providers/unicode.so
WEBSEARCH_PLIST_FILES=	etc/xdg/elephant/providers/websearch.so
WINDOWS_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WINDOWS_PLIST_FILES=	etc/xdg/elephant/providers/windows.so

.include <bsd.port.options.mk>

ENABLED_PROVIDERS=	${SELECTED_OPTIONS:NDOCS:tl}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|; \
				s|/run/user|/var&|' \
		${GO_WRKSRC}/vendor/github.com/adrg/xdg/paths_unix.go

post-build:
.for provider in ${ENABLED_PROVIDERS}
	@${ECHO_MSG} "===>  Building ${provider} from ./internal/providers/${provider}"
	@cd ${GO_WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${GO_ENV} \
		GOMAXPROCS=${MAKE_JOBS_NUMBER} GOPROXY=off \
		${GO_CMD} build ${GO_BUILDFLAGS:C/-buildmode=.*//} -buildmode=plugin \
			-o ${GO_WRKDIR_BIN}/${provider}.so \
			./internal/providers/${provider}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/elephant/providers
	${INSTALL_LIB} ${GO_WRKDIR_BIN}/*.so \
		${STAGEDIR}${PREFIX}/etc/xdg/elephant/providers

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
