PORTNAME=	mailpit
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.1
CATEGORIES=	mail devel
MASTER_SITES=	https://www.madpilot.net/mailpit/:npmcache \
		LOCAL/madpilot/mailpit:npmcache
DISTFILES=	${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}:npmcache

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Mailpit development mail server
WWW=		https://github.com/axllent/mailpit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	npm>0:www/npm

USES=		go:modules tar:zstd
USE_RC_SUBR=	mailpit
GO_BUILDFLAGS+=	-ldflags="-s -w -X \"github.com/axllent/mailpit/config.Version=${DISTVERSIONPREFIX}${DISTVERSION}\""
MAKE_ENV=	npm_config_offline=true

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	axllent
GH_TUPLE=	\
		DATA-DOG:go-sqlmock:v1.5.0:data_dog_go_sqlmock/vendor/github.com/DATA-DOG/go-sqlmock \
		GehirnInc:crypt:8cc1b52080c5:gehirninc_crypt/vendor/github.com/GehirnInc/crypt \
		GuiaBolso:darwin:fd6d2aa3d244:guiabolso_darwin/vendor/github.com/GuiaBolso/darwin \
		PuerkitoBio:goquery:v1.8.1:puerkitobio_goquery/vendor/github.com/PuerkitoBio/goquery \
		andybalholm:cascadia:v1.3.2:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		axllent:semver:v0.0.1:axllent_semver/vendor/github.com/axllent/semver \
		cention-sany:utf7:26cad61bd60a:cention_sany_utf7/vendor/github.com/cention-sany/utf7 \
		cznic:ql:v1.2.0:cznic_ql/vendor/github.com/cznic/ql \
		disintegration:imaging:v1.6.2:disintegration_imaging/vendor/github.com/disintegration/imaging \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		go-check:check:41f04d3bba15:go_check_check/vendor/gopkg.in/check.v1 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		gogs:chardet:b7413eaefb8f:gogs_chardet/vendor/github.com/gogs/chardet \
		golang:crypto:v0.16.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:image:v0.14.0:golang_image/vendor/golang.org/x/image \
		golang:mod:v0.14.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.19.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.15.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.5.0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.16.1:golang_tools/vendor/golang.org/x/tools \
		gomarkdown:markdown:a660076da3fd:gomarkdown_markdown/vendor/github.com/gomarkdown/markdown \
		google:uuid:v1.5.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:css:v1.0.1:gorilla_css/vendor/github.com/gorilla/css \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.5.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jaytaylor:html2text:74c2419ad056:jaytaylor_html2text/vendor/github.com/jaytaylor/html2text \
		jhillyerd:enmime:v1.1.0:jhillyerd_enmime/vendor/github.com/jhillyerd/enmime \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.17.4:klauspost_compress/vendor/github.com/klauspost/compress \
		kr:pretty:v0.3.0:kr_pretty/vendor/github.com/kr/pretty \
		leporo:sqlf:v1.4.0:leporo_sqlf/vendor/github.com/leporo/sqlf \
		lukechampine:uint128:v1.3.0:lukechampine_uint128/vendor/lukechampine.com/uint128 \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.15:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mhale:smtpd:v0.8.1:mhale_smtpd/vendor/github.com/mhale/smtpd \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		reiver:go-oi:v1.0.0:reiver_go_oi/vendor/github.com/reiver/go-oi \
		reiver:go-telnet:9ff0b2ab096e:reiver_go_telnet/vendor/github.com/reiver/go-telnet \
		remyoudompheng:bigfft:24d4a6f8daec:remyoudompheng_bigfft/vendor/github.com/remyoudompheng/bigfft \
		rivo:uniseg:v0.4.4:rivo_uniseg/vendor/github.com/rivo/uniseg \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cobra:v1.8.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		ssor:bom:6386211fdfcf:ssor_bom/vendor/github.com/ssor/bom \
		tg123:go-htpasswd:v1.2.1:tg123_go_htpasswd/vendor/github.com/tg123/go-htpasswd \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		vanng822:css:v1.0.1:vanng822_css \
		vanng822:go-premailer:v1.20.2:vanng822_go_premailer/vendor/github.com/vanng822/go-premailer

USE_GITLAB=	nodefault
GL_TUPLE=	\
		cznic:cc:473a39888db348dde70ba9a01d27d3be2da0a93d:cznic_cc/vendor/modernc.org/cc/v3 \
		cznic:ccgo:62fe9994b77907e147c1317c03f1ab9fe63297da:cznic_ccgo/vendor/modernc.org/ccgo/v3 \
		cznic:libc:5b8af7eee37c9232c76d814f6a34697c7e80f39e:cznic_libc/vendor/modernc.org/libc \
		cznic:mathutil:aabd79189264b253ce2360e80193242239022080:cznic_mathutil/vendor/modernc.org/mathutil \
		cznic:memory:dda74182ee99cca437f9abb436d906192e090c70:cznic_memory/vendor/modernc.org/memory \
		cznic:opt:6b647abadf922391a4527f3a4fa1817eff08b7cd:cznic_opt/vendor/modernc.org/opt \
		cznic:sqlite:3706cfd2cf323472272357b4f9b9e8c963aaca35:cznic_sqlite/vendor/modernc.org/sqlite \
		cznic:strutil:f4c290107e9e43b1bb4a8bc7dcd154eb9b565cd8:cznic_strutil/vendor/modernc.org/strutil \
		cznic:token:24e30cd78ee0f2d5d4516917d9cc1101e3ccc1ab:cznic_token/vendor/modernc.org/token

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/github.com/vanng822
	@${RLN} ${WRKSRC_gorilla_css} ${WRKSRC}/vendor/github.com/vanng822/css

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm ci --legacy-peer-deps
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm run build

# (for maintainer) helper target to generate node_modules tarball
make-npm-cache: patch
	@cd ${WRKDIR} && ${RM} -r .npm
	@cd ${WRKSRC} && ${SETENV} HOME=${WRKDIR} npm ci --legacy-peer-deps
	@cd ${WRKDIR} \
		&& ${TAR} -c --zstd -f ${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} .npm \
		&& ${ECHO} "Please upload the file ${WRKDIR}/${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}"

.include <bsd.port.mk>
