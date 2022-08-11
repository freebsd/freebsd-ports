PORTNAME=	writefreely
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.1
PORTREVISION=	4
CATEGORIES=	www textproc
MASTER_SITES=	https://code.as/core/socks/archive/v1.0.0.tar.gz?dummy=/:core_socks \
		https://git.mills.io/prologic/go-gopher/archive/:go_gopher
DISTFILES=	core-socks-v1.0.0.tar.gz:core_socks \
		b7ebb55feece2abb74a651c217db6f7ead778170.tar.gz:go_gopher
DIST_SUBDIR=	writeas

MAINTAINER=	fuz@fuz.su
COMMENT=	Clean, Markdown-based publishing platform made for writers

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_DISTFILES_CC-BY-NC-SA-4.0=	writefreely-documentation-${DISTVERSIONPREFIX}${DISTVERSION}_GH0.tar.gz

BUILD_DEPENDS=	go-bindata:devel/go-bindata

USES=		go:modules
USE_GITHUB=	yes
GH_TUPLE=	aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		beevik:etree:v1.1.0:beevik_etree/vendor/github.com/beevik/etree \
		captncraig:cors:e80254a89df1:captncraig_cors/vendor/github.com/captncraig/cors \
		chris-ramon:douceur:v0.2.0:chris_ramon_douceur \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		clbanning:mxj:v1.8.4:clbanning_mxj/vendor/github.com/clbanning/mxj \
		cpuguy83:go-md2man:f79a8a8ca69d:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dchest:uniuri:7aecb25e1fe5:dchest_uniuri/vendor/github.com/dchest/uniuri \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		go-fed:httpsig:0ef28562fabe:go_fed_httpsig/vendor/github.com/go-fed/httpsig \
		go-ini:ini:v1.62.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-sql-driver:mysql:v1.6.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-test:deep:v1.0.1:go_test_deep/vendor/github.com/go-test/deep \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		gofrs:uuid:v3.3.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:04defd469f4e:golang_net/vendor/golang.org/x/net \
		golang:sys:04245dca01da:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		gologme:log:v1.2.0:gologme_log/vendor/github.com/gologme/log \
		gopherjs:gopherjs:d547d1d9531e:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		gorilla:csrf:v1.7.0:gorilla_csrf/vendor/github.com/gorilla/csrf \
		gorilla:css:v1.0.0:gorilla_css/vendor/github.com/gorilla/css \
		gorilla:feeds:v1.1.1:gorilla_feeds/vendor/github.com/gorilla/feeds \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:schema:v1.2.0:gorilla_schema/vendor/github.com/gorilla/schema \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:sessions:v1.2.0:gorilla_sessions/vendor/github.com/gorilla/sessions \
		guregu:null:v3.5.0:guregu_null/vendor/github.com/guregu/null \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		ikeikeikeike:go-sitemap-generator:v2.0.2:ikeikeikeike_go_sitemap_generator_v2/vendor/github.com/ikeikeikeike/go-sitemap-generator/v2 \
		jtolds:gls:v4.2.1:jtolds_gls/vendor/github.com/jtolds/gls \
		juju:ansiterm:720a0952cc2a:juju_ansiterm/vendor/github.com/juju/ansiterm \
		kylemcc:twitter-text-go:7f582f6736ec:kylemcc_twitter_text_go/vendor/github.com/kylemcc/twitter-text-go \
		lunixbochs:vtclean:v1.0.0:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		manifoldco:promptui:v0.8.0:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-sqlite3:v1.14.6:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		microcosm-cc:bluemonday:v1.0.5:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mitchellh:go-wordwrap:v1.0.1:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rainycape:unidecode:cb7f23ec59be:rainycape_unidecode/vendor/github.com/rainycape/unidecode \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		smartystreets:assertions:b6c0e53d7304:smartystreets_assertions/vendor/github.com/smartystreets/assertions \
		smartystreets:goconvey:044398e4856c:smartystreets_goconvey/vendor/github.com/smartystreets/goconvey \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		urfave:cli:v2.3.0:urfave_cli_v2/vendor/github.com/urfave/cli/v2 \
		writeas:activity:v0.1.2:writeas_activity/vendor/github.com/writeas/activity \
		writeas:activityserve:d7ab3eaa4481:writeas_activityserve/vendor/github.com/writeas/activityserve \
		writeas:go-strip-markdown:v2.1.1:writeas_go_strip_markdown_v2/vendor/github.com/writeas/go-strip-markdown/v2 \
		writeas:go-webfinger:v1.1.0:writeas_go_webfinger/vendor/github.com/writeas/go-webfinger \
		writeas:go-writeas:v2.0.2:writeas_go_writeas_v2/vendor/github.com/writeas/go-writeas/v2 \
		writeas:httpsig:v1.0.0:writeas_httpsig/vendor/github.com/writeas/httpsig \
		writeas:impart:v1.1.1:writeas_impart/vendor/github.com/writeas/impart \
		writeas:import:v0.2.1:writeas_import/vendor/github.com/writeas/import \
		writeas:monday:54a7dd579219:writeas_monday/vendor/github.com/writeas/monday \
		writeas:openssl-go:v1.0.0:writeas_openssl_go/vendor/github.com/writeas/openssl-go \
		writeas:saturday:392b95a03320:writeas_saturday/vendor/github.com/writeas/saturday \
		writeas:slug:v1.2.0:writeas_slug/vendor/github.com/writeas/slug \
		writeas:web-core:95a3a717ed8f:writeas_web_core/vendor/github.com/writeas/web-core \
		writefreely:go-nodeinfo:v1.2.0:writefreely_go_nodeinfo/vendor/github.com/writefreely/go-nodeinfo
USE_RC_SUBR=	writefreely
GO_TARGET=	./cmd/writefreely

SUB_FILES=	pkg-message
USERS=		writefreely
GROUPS=		writefreely

OPTIONS_DEFINE=		DOCS SQLITE3
OPTIONS_DEFAULT=	CSS_DIST SQLITE3
OPTIONS_SINGLE=		CSS
OPTIONS_SINGLE_CSS=	CSS_DIST CSS_LESSC

CSS_DESC=			Stylesheets
CSS_DIST_DESC=			Use pre-generated stylesheets
CSS_LESSC_DESC=			Generate stylesheets with lessc (requires npm)
CSS_DIST_MASTER_SITES=		http://fuz.su/~fuz/distfiles/writefreely/:css
CSS_DIST_DISTFILES=		writefreely-css-${DISTVERSION}.tar.gz:css
CSS_LESSC_BUILD_DEPENDS=	npm:www/npm
CSS_LESSC_VARS=			LEGAL_PACKAGE=yes \
				NO_PACKAGE="uses www/npm to fetch files at build time (option CSS_LESSC)"
DOCS_GH_TUPLE=			writefreely:documentation:${DISTVERSIONPREFIX}${DISTVERSION}:docs
DOCS_VARS=			LICENSE+=CC-BY-NC-SA-4.0 \
				LICENSE_COMB=multi
SQLITE3_VARS=			GO_BUILDFLAGS+=-tags=sqlite

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/github.com/chris-ramon
	@${RLN} ${WRKSRC_aymerick_douceur} ${WRKSRC}/vendor/github.com/chris-ramon/douceur
	@${MKDIR} ${WRKSRC}/vendor/code.as/core
	@${RLN} ${WRKDIR}/socks ${WRKSRC}/vendor/code.as/core/socks
	@${MKDIR} ${WRKSRC}/vendor/git.mills.io/prologic
	@${RLN} ${WRKDIR}/go-gopher ${WRKSRC}/vendor/git.mills.io/prologic/go-gopher

# download the lessc program with npm for rolling the writefreely-css distfile
${WRKDIR}/npm/bin/lessc:
		@${ECHO_MSG} "=> downloading the lessc utility with NPM"
		${MKDIR} ${WRKDIR}/npm
		npm -C ${WRKDIR}/npm -g install less@3.5.3
		npm -C ${WRKDIR}/npm -g install less-plugin-clean-css

pre-build:
	cd ${WRKSRC} && go-bindata -pkg writefreely -ignore=\\.gitignore schema.sql sqlite.sql

# Packaging node.js applications is a PITA, so supply pre-generated CSS files as
# a custom distfile using lessc, a node.js application.
do-build-CSS_LESSC-on: ${WRKDIR}/npm/bin/lessc
	@${ECHO_MSG} "=> generating CSS files with lessc"
	${RM} -r ${WRKDIR}/css
	${MKDIR} ${WRKDIR}/css
	cd ${WRKSRC}/less && ${WRKDIR}/npm/bin/lessc app.less --clean-css="--s1 --advanced" ${WRKDIR}/css/write.css
	cd ${WRKSRC}/less && ${WRKDIR}/npm/bin/lessc fonts.less --clean-css="--s1 --advanced" ${WRKDIR}/css/fonts.css
	cd ${WRKSRC}/less && ${WRKDIR}/npm/bin/lessc icons.less --clean-css="--s1 --advanced" ${WRKDIR}/css/icons.css
	cd ${WRKSRC}/less && ${WRKDIR}/npm/bin/lessc prose.less --clean-css="--s1 --advanced" ${WRKDIR}/css/prose.css
	${TAR} -z -c -f ${WRKDIR}/writefreely-css-${DISTVERSION}.tar.gz -C ${WRKDIR} css

do-install-DOCS-on:
	cd ${WRKSRC_docs} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} '! -depth 1'

post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/keys
	cd ${WRKSRC} && ${COPYTREE_SHARE} pages ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} static ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKDIR}/css/*.css ${STAGEDIR}${WWWDIR}/static/css/
	cd ${WRKSRC} && ${COPYTREE_SHARE} templates ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
