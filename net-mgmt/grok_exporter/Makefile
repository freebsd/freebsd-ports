PORTNAME=	grok_exporter
DISTVERSIONPREFIX=v
DISTVERSION=	1.0.0.RC4
PORTREVISION=	27
CATEGORIES=	net-mgmt

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Export Prometheus metrics from arbitrary unstructured log data
WWW=		https://github.com/fstab/grok_exporter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	fstab logstash-plugins:plugins
GH_PROJECT=	logstash-patterns-core:plugins
GH_TAGNAME=	6d25c13:plugins
GH_TUPLE=	\
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:c3de453c63f4:alecthomas_units/vendor/github.com/alecthomas/units \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bitly:go-simplejson:v0.5.0:bitly_go_simplejson/vendor/github.com/bitly/go-simplejson \
		cespare:xxhash:v2.1.1:cespare_xxhash/vendor/github.com/cespare/xxhash/v2 \
		go-yaml:yaml:v2.2.7:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:exp:da58074b4299:golang_exp/vendor/golang.org/x/exp \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:d4481acd189f:golang_sys/vendor/golang.org/x/sys \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		prometheus:client_golang:v1.3.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.1.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.7.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.8:prometheus_procfs/vendor/github.com/prometheus/procfs \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus
USERS=		prometheus
GROUPS=		prometheus

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
USE_RC_SUBR=	grok_exporter
SUB_FILES=	config.yml

post-patch:
	for f in `${FIND} ${WRKSRC}/tailer -name '*darwin*'`; do ${LN} -sf $${f} `echo $${f} | ${SED} 's/darwin/freebsd/g'`; done
	cd ${WRKSRC}/tailer/fswatcher && ${LN} -sf fswatcher_darwin_amd64.go fswatcher_freebsd_arm64.go

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/config.yml ${STAGEDIR}${ETCDIR}/config.yml.sample
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} example ${STAGEDIR}${DATADIR})
	@(cd ${WRKSRC_plugins} && ${COPYTREE_SHARE} patterns ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
