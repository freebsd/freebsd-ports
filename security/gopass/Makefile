# Created by: Sascha Holzleiter <sascha@root-login.org>
# $FreeBSD$

PORTNAME=	gopass
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.2
CATEGORIES=	security

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Rewrite of the pass password manager in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Upstream only supports amd64

RUN_DEPENDS=	git:devel/git \
		gpg2:security/gnupg

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	gopasspw
GH_TUPLE=	\
		FiloSottile:age:v1.0.0-rc.1:filosottile_age/vendor/filippo.io/age \
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		blang:semver:v4.0.0:blang_semver_v4/vendor/github.com/blang/semver \
		caspr-io:yamlpath:502e8d113a9b:caspr_io_yamlpath/vendor/github.com/caspr-io/yamlpath \
		cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:496545a6307b:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		godbus:dbus:8a1682060722:godbus_dbus/vendor/github.com/godbus/dbus \
		gokyle:twofactor:v1.0.1:gokyle_twofactor/vendor/github.com/gokyle/twofactor \
		golang:crypto:eec23a3978ad:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:5f4716e94777:golang_net/vendor/golang.org/x/net \
		golang:sys:9a76102bfb43:golang_sys/vendor/golang.org/x/sys \
		golang:term:2321bbc49cbf:golang_term/vendor/golang.org/x/term \
		google:go-cmp:v0.5.5:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-github:v17.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		gotestyourself:gotest.tools:v2.2.0:gotestyourself_gotest_tools/vendor/gotest.tools \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		jsimonetti:pwscheme:76804708ecad:jsimonetti_pwscheme/vendor/github.com/jsimonetti/pwscheme \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		martinhoefling:goxkcdpwgen:7dc3d102eca3:martinhoefling_goxkcdpwgen/vendor/github.com/martinhoefling/goxkcdpwgen \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-ps:v1.0.0:mitchellh_go_ps/vendor/github.com/mitchellh/go-ps \
		muesli:crunchy:v0.4.0:muesli_crunchy/vendor/github.com/muesli/crunchy \
		nbutton23:zxcvbn-go:fa2cb2858354:nbutton23_zxcvbn_go/vendor/github.com/nbutton23/zxcvbn-go \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rsc:qr:v0.2.0:rsc_qr/vendor/rsc.io/qr \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		schollz:closestmatch:1fbe626be92e:schollz_closestmatch/vendor/github.com/schollz/closestmatch \
		skip2:go-qrcode:da1b6568686e:skip2_go_qrcode/vendor/github.com/skip2/go-qrcode \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		urfave:cli:v2.3.0:urfave_cli_v2/vendor/github.com/urfave/cli/v2 \
		xrash:smetrics:039620a65673:xrash_smetrics/vendor/github.com/xrash/smetrics
# Usage examples are in a separate repo
GH_TUPLE+=	gopasspw:password-store-example:8db75ba3b69c:password_store_example

PORTDOCS=	README.md docs/*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-build:
.for SHELL in bash fish zsh
	${GO_WRKDIR_BIN}/${PORTNAME} completion ${SHELL} > ${WRKSRC}/${SHELL}
.endfor
	cd ${GO_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} run ${GO_BUILDFLAGS} ./helpers/man/main.go > ${PORTNAME}.1

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}.sh
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC_password_store_example} && ${COPYTREE_SHARE} "README.md secrets templates" ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
