PORTNAME=	aerc
DISTVERSION=	0.16.0
PORTREVISION=	1
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
GH_TUPLE=	ProtonMail:go-crypto:71bec3603bf3:protonmail_crypto/vendor/golang.org/x/crypto \
		ProtonMail:go-crypto:8ee5748c52b5:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		arran4:golang-ical:19abf92700cc:arran4_golang_ical/vendor/github.com/arran4/golang-ical \
		cloudflare:circl:v1.3.2:cloudflare_circl/vendor/github.com/cloudflare/circl \
		creack:pty:v1.1.18:creack_pty/vendor/github.com/creack/pty \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		emersion:go-imap-sortthread:v1.2.0:emersion_go_imap_sortthread/vendor/github.com/emersion/go-imap-sortthread \
		emersion:go-imap:v1.2.1:emersion_go_imap/vendor/github.com/emersion/go-imap \
		emersion:go-maildir:v0.3.0:emersion_go_maildir/vendor/github.com/emersion/go-maildir \
		emersion:go-mbox:v1.0.3:emersion_go_mbox/vendor/github.com/emersion/go-mbox \
		emersion:go-message:v0.17.0:emersion_go_message/vendor/github.com/emersion/go-message \
		emersion:go-msgauth:v0.6.6:emersion_go_msgauth/vendor/github.com/emersion/go-msgauth \
		emersion:go-pgpmail:v0.2.0:emersion_go_pgpmail/vendor/github.com/emersion/go-pgpmail \
		emersion:go-sasl:0145f2c60ead:emersion_go_sasl/vendor/github.com/emersion/go-sasl \
		emersion:go-smtp:v0.16.0:emersion_go_smtp/vendor/github.com/emersion/go-smtp \
		emersion:go-textwrapper:65d896831594:emersion_go_textwrapper/vendor/github.com/emersion/go-textwrapper \
		fsnotify:fsevents:v0.1.1:fsnotify_fsevents/vendor/github.com/fsnotify/fsevents \
		fsnotify:fsnotify:v1.6.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gatherstars-com:jwz:v1.4.0:gatherstars_com_jwz/vendor/github.com/gatherstars-com/jwz \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.6.0:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/github.com/go-ini/ini \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:net:v0.9.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.7.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:v0.7.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.7.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.12.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.6.0:golang_tools/vendor/golang.org/x/tools \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		kr:pretty:v0.3.0:kr_pretty/vendor/github.com/kr/pretty \
		lithammer:fuzzysearch:v1.1.5:lithammer_fuzzysearch/vendor/github.com/lithammer/fuzzysearch \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.18:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.14:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		onsi:gomega:v1.20.0:onsi_gomega/vendor/github.com/onsi/gomega \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.30.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rivo:uniseg:v0.4.4:rivo_uniseg/vendor/github.com/rivo/uniseg \
		riywo:loginshell:7d26008be1ab:riywo_loginshell/vendor/github.com/riywo/loginshell \
		rogpeppe:go-internal:v1.8.1:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		stretchr:testify:v1.8.2:stretchr_testify/vendor/github.com/stretchr/testify \
		syndtr:goleveldb:v1.0.0:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		xo:terminfo:abceb7e1c41e:xo_terminfo/vendor/github.com/xo/terminfo

# Additional distfiles to fetch from https://git.sr.ht
_SRHT_TUPLE=	rjarry:aerc:${DISTVERSIONFULL}:"" \
		rockorager:go-jmap:v0.3.0:vendor/git.sr.ht/~rockorager/go-jmap \
		rockorager:tcell-term:v0.8.0:vendor/git.sr.ht/~rockorager/tcell-term \
		sircmpwn:getopt:v1.0.0:vendor/git.sr.ht/~sircmpwn/getopt

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
