# Created by: Sascha Holzleiter <sascha@root-login.org>
# $FreeBSD$

PORTNAME=	gopass
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.0
CATEGORIES=	security

MAINTAINER=	ed.arrakis@gmail.com
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
		FiloSottile:age:v1.0.0-beta4:filosottile_age/vendor/filippo.io/age \
		atotto:clipboard:v0.1.2:atotto_clipboard/vendor/github.com/atotto/clipboard \
		blang:semver:1a9109f8c4a1:blang_semver/vendor/github.com/blang/semver \
		caspr-io:yamlpath:502e8d113a9b:caspr_io_yamlpath/vendor/github.com/caspr-io/yamlpath \
		cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dominikschulz:github-releases:v0.0.3:dominikschulz_github_releases/vendor/github.com/dominikschulz/github-releases \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		go-ini:ini:v1.60.1:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:eeeca48fe776:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		godbus:dbus:8a1682060722:godbus_dbus/vendor/github.com/godbus/dbus \
		gokyle:twofactor:v1.0.1:gokyle_twofactor/vendor/github.com/gokyle/twofactor \
		golang:crypto:afb6bcd081ae:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:f5854403a974:golang_net/vendor/golang.org/x/net \
		golang:sys:9f70ab9862d5:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.5.2:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-github:v17.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		gotestyourself:gotest.tools:v2.2.0:gotestyourself_gotest_tools/vendor/gotest.tools \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		jsimonetti:pwscheme:76804708ecad:jsimonetti_pwscheme/vendor/github.com/jsimonetti/pwscheme \
		json-iterator:go:v1.1.10:json_iterator_go/vendor/github.com/json-iterator/go \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:cpuid:v1.3.1:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		martinhoefling:goxkcdpwgen:7dc3d102eca3:martinhoefling_goxkcdpwgen/vendor/github.com/martinhoefling/goxkcdpwgen \
		mattn:go-colorable:v0.1.7:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		minio:md5-simd:v1.1.0:minio_md5_simd/vendor/github.com/minio/md5-simd \
		minio:minio-go:v7.0.7:minio_minio_go_v7/vendor/github.com/minio/minio-go/v7 \
		minio:sha256-simd:v0.1.1:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-ps:v1.0.0:mitchellh_go_ps/vendor/github.com/mitchellh/go-ps \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		muesli:crunchy:v0.4.0:muesli_crunchy/vendor/github.com/muesli/crunchy \
		nbutton23:zxcvbn-go:ae427f1e4c1d:nbutton23_zxcvbn_go/vendor/github.com/nbutton23/zxcvbn-go \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rs:xid:v1.2.1:rs_xid/vendor/github.com/rs/xid \
		rsc:qr:v0.2.0:rsc_qr/vendor/rsc.io/qr \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		schollz:closestmatch:1fbe626be92e:schollz_closestmatch/vendor/github.com/schollz/closestmatch \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		skip2:go-qrcode:da1b6568686e:skip2_go_qrcode/vendor/github.com/skip2/go-qrcode \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		urfave:cli:v2.2.0:urfave_cli_v2/vendor/github.com/urfave/cli/v2 \
		xrash:smetrics:89a2a8a1fb0b:xrash_smetrics/vendor/github.com/xrash/smetrics

# Usage examples are in a separate repo
GH_TUPLE+=	gopasspw:password-store-example:8db75ba3b69c:password_store_example

PORTDOCS=	README.md docs/*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-build:
.for SHELL in bash fish zsh
	${GO_WRKDIR_BIN}/${PORTNAME} completion ${SHELL} > ${WRKSRC}/${SHELL}
.endfor

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

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC_password_store_example} && ${COPYTREE_SHARE} "README.md secrets templates" ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
