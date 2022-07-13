PORTNAME=	certmgr
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.3
PORTREVISION=	3
CATEGORIES=	security net

MAINTAINER=	fuz@fuz.su
COMMENT=	Automated certificate management using a CFSSL CA

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	cloudflare
GH_TUPLE=	beorn7:perks:v1.0.0:beorn7_perks/vendor/github.com/beorn7/perks \
		cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		cloudflare:backoff:647f3cdfc87a:cloudflare_backoff/vendor/github.com/cloudflare/backoff \
		cloudflare:cfssl:2001f384ec4f:cloudflare_cfssl/vendor/github.com/cloudflare/cfssl \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:5c40567a22f8:golang_crypto/vendor/golang.org/x/crypto \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:5ed2794edfdc:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:certificate-transparency-go:v1.0.21:google_certificate_transparency_go/vendor/github.com/google/certificate-transparency-go \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v1.4.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:7f95ac13edff:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v0.9.4:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.4.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.2:prometheus_procfs/vendor/github.com/prometheus/procfs \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.4.0:spf13_viper/vendor/github.com/spf13/viper

CONFLICTS_INSTALL=	mono mono[0-9]* # bin/certmgr

GO_TARGET=	./certmgr
SUB_FILES=	certmgr.yaml.sample pkg-message

post-patch:
	${REINPLACE_CMD} -e 's,%%ETCDIR%%,${ETCDIR},' \
	    ${WRKSRC}/certmgr/cmd/genconfig.go \
	    ${WRKSRC}/certmgr/cmd/root.go \
	    ${WRKSRC}/README.md

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}.d
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${WRKSRC}/SPEC.rst ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKDIR}/certmgr.yaml.sample ${STAGEDIR}${ETCDIR}/

.include <bsd.port.mk>
