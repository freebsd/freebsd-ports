PORTNAME=	nsc
PORTVERSION=	2.6.1
CATEGORIES=	net
PKGNAMEPREFIX=	nats-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Tool for creating NATS account and user access configurations

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	nats-io
GH_TUPLE=	AlecAivazis:survey:v2.0.4:alecaivazis_survey_v2/vendor/github.com/AlecAivazis/survey/v2 \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		briandowns:spinner:195c31b675a7:briandowns_spinner/vendor/github.com/briandowns/spinner \
		cpuguy83:go-md2man:v1.0.10:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.3.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:5ff15b29337e:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:e18ecbb05110:golang_net/vendor/golang.org/x/net \
		golang:oauth2:d668ce993890:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:69cdffdb9359:golang_sys/vendor/golang.org/x/sys \
		golang:time:89c76fbcd5d1:golang_time/vendor/golang.org/x/time \
		google:go-github:v30.1.0:google_go_github_v30/vendor/github.com/google/go-github/v30 \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		inconshreveable:go-update:8152e7eb6ccf:inconshreveable_go_update/vendor/github.com/inconshreveable/go-update \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.13.4:klauspost_compress/vendor/github.com/klauspost/compress \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.11:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		minio:highwayhash:v1.0.1:minio_highwayhash/vendor/github.com/minio/highwayhash \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		nats-io:cliprompts:372d79b36768:nats_io_cliprompts_v2/vendor/github.com/nats-io/cliprompts \
		nats-io:jwt:v1.2.2:nats_io_jwt/vendor/github.com/nats-io/jwt \
		nats-io:jwt:v2.2.0:nats_io_jwt_v2 \
		nats-io:nats-server:v2.6.4:nats_io_nats_server_v2/vendor/github.com/nats-io/nats-server/v2 \
		nats-io:nats.go:f2416a8b1483:nats_io_nats_go/vendor/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.3.0:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		onsi:gomega:v1.4.3:onsi_gomega/vendor/github.com/onsi/gomega \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rhysd:go-github-selfupdate:v1.2.2:rhysd_go_github_selfupdate/vendor/github.com/rhysd/go-github-selfupdate \
		russross:blackfriday:v1.5.2:russross_blackfriday/vendor/github.com/russross/blackfriday \
		spf13:cobra:v0.0.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tcnksm:go-gitconfig:v0.1.2:tcnksm_go_gitconfig/vendor/github.com/tcnksm/go-gitconfig \
		ulikunitz:xz:v0.5.8:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		xlab:tablewriter:80b567a11ad5:xlab_tablewriter/vendor/github.com/xlab/tablewriter

PLIST_FILES=	bin/nsc \
		share/doc/${PORTNAME}/README.md

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/nats-io/jwt/v2
	@${RLN} ${WRKSRC_nats_io_jwt_v2}/v2 ${WRKSRC}/vendor/github.com/nats-io/jwt/v2

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
