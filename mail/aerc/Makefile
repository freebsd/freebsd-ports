# $FreeBSD$

PORTNAME=	aerc
DISTVERSION=	0.1.1-37
DISTVERSIONSUFFIX=	-gd22a914
CATEGORIES=	mail

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Email client for your terminal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	scdoc:textproc/scdoc

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		ddevault:go-libvterm:b7d861da3810:ddevault_go_libvterm/vendor/github.com/ddevault/go-libvterm \
		emersion:go-imap-idle:2704abd7050e:emersion_go_imap_idle/vendor/github.com/emersion/go-imap-idle \
		emersion:go-imap:v1.0.0-beta.6:emersion_go_imap/vendor/github.com/emersion/go-imap \
		emersion:go-message:v0.10.3:emersion_go_message/vendor/github.com/emersion/go-message \
		emersion:go-sasl:47d427600317:emersion_go_sasl/vendor/github.com/emersion/go-sasl \
		emersion:go-smtp:v0.11.1:emersion_go_smtp/vendor/github.com/emersion/go-smtp \
		emersion:go-textwrapper:d0e65e56babe:emersion_go_textwrapper/vendor/github.com/emersion/go-textwrapper \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:b5d0c1ac5702:gdamore_tcell/vendor/github.com/gdamore/tcell \
		go-ini:ini:v1.42.0:go_ini_ini/vendor/github.com/go-ini/ini \
		golang:sys:4c4f7f33c9ed:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:shlex:c34317bd91bf:google_shlex/vendor/github.com/google/shlex \
		kyoh86:xdg:v1.0.0:kyoh86_xdg/vendor/github.com/kyoh86/xdg \
		lucasb-eyer:go-colorful:v1.0.2:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		martinlindhe:base36:7c6542dfbb41:martinlindhe_base36/vendor/github.com/martinlindhe/base36 \
		mattn:go-isatty:v0.0.8:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-pointer:49522c3f3791:mattn_go_pointer/vendor/github.com/mattn/go-pointer \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		miolini:datacounter:fd4e42a1d5e0:miolini_datacounter/vendor/github.com/miolini/datacounter \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		riywo:loginshell:c2f4167b2303:riywo_loginshell/vendor/github.com/riywo/loginshell \
		stretchr:testify:v1.3.0:stretchr_testify/vendor/github.com/stretchr/testify

# Additional distfiles to fetch from https://git.sr.ht
SRHT_TUPLE=	sircmpwn aerc ${DISTVERSIONFULL} \
		sircmpwn getopt e7e23d1cd3a3 \
		sircmpwn pty 3a43678975a9

MAKE_ARGS=	MANDIR=${STAGEDIR}${PREFIX}/man
MAKE_ENV=	${GO_ENV} \
		GOFLAGS="${GO_BUILDFLAGS}"

OPTIONS_DEFINE=		HTML_FILTER
OPTIONS_DEFAULT=	HTML_FILTER
OPTIONS_SUB=		yes

HTML_FILTER_DESC=	Install HTML filter (depends on w3m and socksify)

HTML_FILTER_RUN_DEPENDS=	socksify:net/dante \
				w3m:www/w3m

.include <bsd.port.pre.mk>

.for account project tag in ${SRHT_TUPLE}
MASTER_SITES+=	https://git.sr.ht/~${account}/${project}/archive/${tag}${EXTRACT_SUFX}?dummy=/:${account}_${project}
DISTFILES+=	${account}-${project}-${tag}_SRHT0${EXTRACT_SUFX}:${account}_${project}
.endfor

post-extract:
.for account project tag in ${SRHT_TUPLE:[4..-1]}
	@${MKDIR} ${WRKSRC}/vendor/git.sr.ht/~${account}
	@${MV} ${WRKDIR}/${project}-${tag} ${WRKSRC}/vendor/git.sr.ht/~${account}/${project}
.endfor

post-patch:
	@${REINPLACE_CMD} -e '/BINDIR/ s,install -m755,${INSTALL_PROGRAM},' \
		-e 's,install -m755,${INSTALL_SCRIPT},' \
		-e '/MANDIR/ s,install -m644,${INSTALL_MAN},' \
		-e '/SHAREDIR/ s,install -m644,${INSTALL_DATA},' \
		${WRKSRC}/Makefile

# Prevent USES=go do-{build,install} targets.  We do want the
# environmental setup USES=go does though.
do-build:
	@${DO_MAKE_BUILD} -C ${WRKSRC} ${ALL_TARGET}

do-install:
	@${DO_MAKE_BUILD} -C ${WRKSRC} DESTDIR=${STAGEDIR} ${INSTALL_TARGET}

.include <bsd.port.post.mk>
