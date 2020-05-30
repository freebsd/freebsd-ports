# $FreeBSD$

PORTNAME=	aerc
DISTVERSION=	0.4.0
CATEGORIES=	mail

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Email client for your terminal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	scdoc:textproc/scdoc

USES=		go:modules,no_targets
USE_GITHUB=	nodefault
GH_TUPLE=	ProtonMail:crypto:71bec3603bf3:protonmail_crypto/vendor/golang.org/x/crypto \
		creack:pty:v1.1.10:creack_pty/vendor/github.com/creack/pty \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		ddevault:go-libvterm:b7d861da3810:ddevault_go_libvterm/vendor/github.com/ddevault/go-libvterm \
		emersion:go-imap-idle:2704abd7050e:emersion_go_imap_idle/vendor/github.com/emersion/go-imap-idle \
		emersion:go-imap:v1.0.4:emersion_go_imap/vendor/github.com/emersion/go-imap \
		emersion:go-maildir:v0.2.0:emersion_go_maildir/vendor/github.com/emersion/go-maildir \
		emersion:go-message:v0.11.1:emersion_go_message/vendor/github.com/emersion/go-message \
		emersion:go-pgpmail:db035a3a4139:emersion_go_pgpmail/vendor/github.com/emersion/go-pgpmail \
		emersion:go-sasl:430746ea8b9b:emersion_go_sasl/vendor/github.com/emersion/go-sasl \
		emersion:go-smtp:v0.12.1:emersion_go_smtp/vendor/github.com/emersion/go-smtp \
		emersion:go-textwrapper:d0e65e56babe:emersion_go_textwrapper/vendor/github.com/emersion/go-textwrapper \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		go-ini:ini:v1.52.0:go_ini_ini/vendor/github.com/go-ini/ini \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:net:244492dfa37a:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.4:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:5c8b2ff67527:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		imdario:mergo:v0.3.8:imdario_mergo/vendor/github.com/imdario/mergo \
		kyoh86:xdg:v1.2.0:kyoh86_xdg/vendor/github.com/kyoh86/xdg \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		martinlindhe:base36:v1.0.0:martinlindhe_base36/vendor/github.com/martinlindhe/base36 \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-pointer:a0a44394634f:mattn_go_pointer/vendor/github.com/mattn/go-pointer \
		mattn:go-runewidth:v0.0.8:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		miolini:datacounter:v1.0.2:miolini_datacounter/vendor/github.com/miolini/datacounter \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		riywo:loginshell:2ed199a032f6:riywo_loginshell/vendor/github.com/riywo/loginshell \
		stretchr:testify:v1.3.0:stretchr_testify/vendor/github.com/stretchr/testify \
		zenhack:go.notmuch:5a1961965cfb:zenhack_go_notmuch/vendor/github.com/zenhack/go.notmuch

# Additional distfiles to fetch from https://git.sr.ht
_SRHT_TUPLE=	sircmpwn:aerc:${DISTVERSIONFULL}:"" \
		sircmpwn:getopt:daaf1274538b:vendor/git.sr.ht/~sircmpwn/getopt \
		sircmpwn:tcell:3fdb6bc01a50:vendor/github.com/gdamore/tcell

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
