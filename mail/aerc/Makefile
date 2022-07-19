PORTNAME=	aerc
DISTVERSION=	0.10.0
CATEGORIES=	mail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Email client for your terminal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	scdoc:textproc/scdoc

USES=		desktop-file-utils go:modules,no_targets ncurses:port python \
		shebangfix
SHEBANG_FILES=	filters/colorize \
		filters/show-ics-details.py

USE_GITHUB=	nodefault
GH_TUPLE=	\
		ProtonMail:go-crypto:71bec3603bf3:protonmail_crypto/vendor/golang.org/x/crypto \
		ProtonMail:go-crypto:a4f6767435ab:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		brunnre8:go.notmuch:caa2daf7093c:brunnre8_go_notmuch/vendor/github.com/zenhack/go.notmuch \
		creack:pty:v1.1.17:creack_pty/vendor/github.com/creack/pty \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		ddevault:go-libvterm:b7d861da3810:ddevault_go_libvterm/vendor/github.com/ddevault/go-libvterm \
		emersion:go-imap-sortthread:v1.2.0:emersion_go_imap_sortthread/vendor/github.com/emersion/go-imap-sortthread \
		emersion:go-imap:v1.2.0:emersion_go_imap/vendor/github.com/emersion/go-imap \
		emersion:go-maildir:v0.2.0:emersion_go_maildir/vendor/github.com/emersion/go-maildir \
		emersion:go-message:v0.15.0:emersion_go_message/vendor/github.com/emersion/go-message \
		emersion:go-pgpmail:v0.2.0:emersion_go_pgpmail/vendor/github.com/emersion/go-pgpmail \
		emersion:go-sasl:0b9dcfb154ac:emersion_go_sasl/vendor/github.com/emersion/go-sasl \
		emersion:go-smtp:v0.15.0:emersion_go_smtp/vendor/github.com/emersion/go-smtp \
		emersion:go-textwrapper:65d896831594:emersion_go_textwrapper/vendor/github.com/emersion/go-textwrapper \
		fsnotify:fsnotify:v1.5.1:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gatherstars-com:jwz:v1.3.0:gatherstars_com_jwz/vendor/github.com/gatherstars-com/jwz \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.4.0:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		go-ini:ini:v1.63.2:go_ini_ini/vendor/github.com/go-ini/ini \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:net:99673261e6eb:golang_net/vendor/golang.org/x/net \
		golang:oauth2:ba495a64dcb5:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:b3129d9d1021:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		imdario:mergo:v0.3.12:imdario_mergo/vendor/github.com/imdario/mergo \
		kyoh86:xdg:v1.2.0:kyoh86_xdg/vendor/github.com/kyoh86/xdg \
		lithammer:fuzzysearch:v1.1.3:lithammer_fuzzysearch/vendor/github.com/lithammer/fuzzysearch \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-pointer:v0.0.1:mattn_go_pointer/vendor/github.com/mattn/go-pointer \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		miolini:datacounter:v1.0.2:miolini_datacounter/vendor/github.com/miolini/datacounter \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		riywo:loginshell:7d26008be1ab:riywo_loginshell/vendor/github.com/riywo/loginshell \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		xo:terminfo:ca9a967f8778:xo_terminfo/vendor/github.com/xo/terminfo

# Additional distfiles to fetch from https://git.sr.ht
_SRHT_TUPLE=	rjarry:aerc:${DISTVERSIONFULL}:"" \
		sircmpwn:getopt:v1.0.0:vendor/git.sr.ht/~sircmpwn/getopt

MAKE_ENV=	${GO_ENV} \
		GOFLAGS="${GO_BUILDFLAGS}"

OPTIONS_DEFINE=		HTML_FILTER NOTMUCH
OPTIONS_DEFAULT=	HTML_FILTER NOTMUCH
OPTIONS_SUB=		yes

HTML_FILTER_DESC=	Install HTML filter (depends on w3m and socksify)
NOTMUCH_DESC=		Fast indexing and searching support via notmuch

HTML_FILTER_RUN_DEPENDS=	socksify:net/dante \
				w3m:www/w3m

NOTMUCH_LIB_DEPENDS=	libnotmuch.so:mail/notmuch
NOTMUCH_VARS=		GO_BUILDFLAGS+="-tags=notmuch"

.include <bsd.port.pre.mk>

.for account project tag subdir in ${_SRHT_TUPLE:S/:/ /g}
MASTER_SITES+=	https://git.sr.ht/~${account}/${project}/archive/${tag}${EXTRACT_SUFX}?dummy=/:${account}_${project}
DISTFILES+=	${account}-${project}-${tag}_SRHT0${EXTRACT_SUFX}:${account}_${project}
.endfor

post-extract:
.for account project tag subdir in ${_SRHT_TUPLE:S/:/ /g:[5..-1]}
	@${MKDIR} ${WRKSRC}/${subdir:H}
	@${MV} ${WRKDIR}/${project}-${tag} ${WRKSRC}/${subdir}
.endfor

post-patch:
	@${REINPLACE_CMD} -e '/BINDIR/ s,install -m755,${INSTALL_PROGRAM},' \
		-e 's,install -m755,${INSTALL_SCRIPT},' \
		-e '/MANDIR/ s,install -m644,${INSTALL_MAN},' \
		-e '/SHAREDIR/ s,install -m644,${INSTALL_DATA},' \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>
