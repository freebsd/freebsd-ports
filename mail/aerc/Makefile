PORTNAME=	aerc
DISTVERSION=	0.20.1
PORTREVISION=	5
CATEGORIES=	mail

MAINTAINER=	iamsleepy@ryuki.me
COMMENT=	Email client for your terminal
WWW=		https://aerc-mail.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	base64:converters/base64 \
		scdoc:textproc/scdoc

USES=		desktop-file-utils gmake go:modules ncurses:port python \
		shebangfix

USE_GITHUB=	nodefault

GH_TUPLE=	ProtonMail:go-crypto:v1.1.4:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		arran4:golang-ical:v0.3.1:arran4_golang_ical/vendor/github.com/arran4/golang-ical \
		cloudflare:circl:v1.4.0:cloudflare_circl/vendor/github.com/cloudflare/circl \
		containerd:console:v1.0.4:containerd_console/vendor/github.com/containerd/console \
		creack:pty:v1.1.24:creack_pty/vendor/github.com/creack/pty \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		emersion:go-imap-sortthread:v1.2.0:emersion_go_imap_sortthread/vendor/github.com/emersion/go-imap-sortthread \
		emersion:go-imap:v1.2.1:emersion_go_imap/vendor/github.com/emersion/go-imap \
		emersion:go-maildir:v0.5.0:emersion_go_maildir/vendor/github.com/emersion/go-maildir \
		emersion:go-mbox:v1.0.3:emersion_go_mbox/vendor/github.com/emersion/go-mbox \
		emersion:go-message:v0.18.2:emersion_go_message/vendor/github.com/emersion/go-message \
		emersion:go-msgauth:v0.6.8:emersion_go_msgauth/vendor/github.com/emersion/go-msgauth \
		emersion:go-pgpmail:v0.2.2:emersion_go_pgpmail/vendor/github.com/emersion/go-pgpmail \
		emersion:go-sasl:b788ff22d5a6:emersion_go_sasl/vendor/github.com/emersion/go-sasl \
		emersion:go-smtp:v0.21.3:emersion_go_smtp/vendor/github.com/emersion/go-smtp \
		fsnotify:fsevents:v0.2.0:fsnotify_fsevents/vendor/github.com/fsnotify/fsevents \
		fsnotify:fsnotify:v1.8.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/github.com/go-ini/ini \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.31.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:image:v0.23.0:golang_image/vendor/golang.org/x/image \
		golang:mod:v0.20.0:golang_mod/vendor/golang.org/x/mod \
		golang:oauth2:v0.24.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:v0.10.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.28.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.21.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.24.0:golang_tools/vendor/golang.org/x/tools \
		konimarti:jwz:81c07e9284c3:konimarti_jwz/vendor/github.com/gatherstars-com/jwz \
		kr:pretty:v0.3.0:kr_pretty/vendor/github.com/kr/pretty \
		lithammer:fuzzysearch:v1.1.8:lithammer_fuzzysearch/vendor/github.com/lithammer/fuzzysearch \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.16:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-sixel:v0.0.5:mattn_go_sixel/vendor/github.com/mattn/go-sixel \
		onsi:gomega:v1.20.0:onsi_gomega/vendor/github.com/onsi/gomega \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		riywo:loginshell:7d26008be1ab:riywo_loginshell/vendor/github.com/riywo/loginshell \
		rogpeppe:go-internal:v1.8.1:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		soniakeys:quant:v1.0.0:soniakeys_quant/vendor/github.com/soniakeys/quant \
		stretchr:testify:v1.10.0:stretchr_testify/vendor/github.com/stretchr/testify \
		syndtr:goleveldb:v1.0.0:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb

# Additional distfiles to fetch from https://git.sr.ht
_SRHT_TUPLE=	rjarry:aerc:${DISTVERSIONFULL}:"" \
		rjarry:go-opt:v2.0.1:vendor/git.sr.ht/~rjarry/go-opt/v2 \
		rockorager:go-jmap:v0.5.0:vendor/git.sr.ht/~rockorager/go-jmap \
		rockorager:vaxis:v0.11.1:vendor/git.sr.ht/~rockorager/vaxis

SHEBANG_FILES=	contrib/carddav-query filters/show-ics-details.py

MAKEFILE=	GNUmakefile
MAKE_ARGS=	GO_BUILDFLAGS="${GO_BUILDFLAGS}" \
		VERSION="${DISTVERSION}"
MAKE_ENV=	${GO_ENV} \
		CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		GOFLAGS="${GO_BUILDFLAGS}"

OPTIONS_DEFINE=		HTML_FILTER NOTMUCH
OPTIONS_DEFAULT=	HTML_FILTER NOTMUCH
OPTIONS_SUB=		yes

HTML_FILTER_DESC=	Install HTML filter (depends on w3m and socksify)
NOTMUCH_DESC=		Fast indexing and searching support via notmuch

HTML_FILTER_RUN_DEPENDS=	socksify:net/dante \
				w3m:www/w3m
NOTMUCH_LIB_DEPENDS=		libnotmuch.so:mail/notmuch
NOTMUCH_VARS=			GO_BUILDFLAGS+="-tags=notmuch"

.include <bsd.port.pre.mk>

.for account project tag subdir in ${_SRHT_TUPLE:S/:/ /g}
MASTER_SITES+=	https://git.sr.ht/~${account}/${project}/archive/${tag}${EXTRACT_SUFX}?dummy=/:${account}_${project:S/-/_/g}
DISTFILES+=	${account}-${project}-${tag}_SRHT0${EXTRACT_SUFX}:${account}_${project:S/-/_/g}
.endfor

post-extract:
.for account project tag subdir in ${_SRHT_TUPLE:S/:/ /g:[5..-1]}
	@${MKDIR} ${WRKSRC}/${subdir:H}
	@${MV} ${WRKDIR}/${project}-${tag} ${WRKSRC}/${subdir}
.endfor

do-build:
	(cd ${WRKSRC} && ${DO_MAKE_BUILD} ${ALL_TARGET})

do-install:
	${REINPLACE_CMD} 's,PREFIX ?=.*,PREFIX= ${STAGEDIR}${PREFIX},' \
	    ${WRKSRC}/${MAKEFILE}
	(cd ${WRKSRC} && ${DO_MAKE_BUILD} ${INSTALL_TARGET})

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/libexec/aerc/filters/wrap
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/libexec/aerc/filters/colorize

.include <bsd.port.post.mk>
