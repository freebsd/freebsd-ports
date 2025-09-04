PORTNAME=	writeas-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0-wf
PORTREVISION=	30
CATEGORIES=	www textproc
MASTER_SITES=	https://code.as/core/socks/archive/v1.0.0.tar.gz?dummy=/:core_socks
DISTFILES=	core-socks-v1.0.0.tar.gz:core_socks
DIST_SUBDIR=	writeas

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Command line client for Write.as / WriteFreely
WWW=		https://write.as/apps/cli

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	writeas
GH_TUPLE=	atotto:clipboard:v0.1.1:atotto_clipboard/vendor/github.com/atotto/clipboard \
		cloudfoundry:jibber_jabber:bcc4c8345a21:cloudfoundry_jibber_jabber/vendor/github.com/cloudfoundry/jibber_jabber \
		go-ini:ini:v1.39.3:go_ini_ini/vendor/gopkg.in/ini.v1 \
		golang:crypto:505ab145d0a9:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:e147a9138326:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.5.0:golang_sys/vendor/golang.org/x/sys \
		gopherjs:gopherjs:d547d1d9531e:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		howeyc:gopass:bf9dde6d0d2c:howeyc_gopass/vendor/github.com/howeyc/gopass \
		jtolds:gls:v4.2.1:jtolds_gls/vendor/github.com/jtolds/gls \
		microcosm-cc:bluemonday:v1.0.1:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mitchellh:go-homedir:v1.0.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		onsi:ginkgo:v1.8.0:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.5.0:onsi_gomega/vendor/github.com/onsi/gomega \
		shurcooL:sanitized_anchor_name:86672fcb3f95:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		smartystreets:assertions:b2de0cb4f26d:smartystreets_assertions/vendor/github.com/smartystreets/assertions \
		smartystreets:goconvey:044398e4856c:smartystreets_goconvey/vendor/github.com/smartystreets/goconvey \
		urfave:cli:v1.20.0:urfave_cli/vendor/gopkg.in/urfave/cli.v1 \
		writeas:go-writeas:v2.0.2:writeas_go_writeas_v2/vendor/github.com/writeas/go-writeas/v2 \
		writeas:impart:v1.1.0:writeas_impart/vendor/github.com/writeas/impart \
		writeas:saturday:f455b05c043f:writeas_saturday/vendor/github.com/writeas/saturday \
		writeas:web-core:05f387ffa1b3:writeas_web_core/vendor/github.com/writeas/web-core
GO_TARGET=	./cmd/wf ./cmd/writeas

PLIST_FILES=	bin/wf bin/writeas
PORTDOCS=	*/*.md

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/code.as/core
	@${RLN} ${WRKDIR}/socks ${WRKSRC}/vendor/code.as/core/socks

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/cmd && for doc in ${PORTDOCS} ; \
	do \
		${MKDIR} ${STAGEDIR}${DOCSDIR}/`${DIRNAME} $$doc` ; \
		${INSTALL_MAN} $$doc ${STAGEDIR}${DOCSDIR}/`${DIRNAME} $$doc` ; \
	done

.include <bsd.port.mk>
