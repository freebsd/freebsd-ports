# $FreeBSD$

PORTNAME=	netdata-go
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
CATEGORIES=	net-mgmt

MAINTAINER=	driesm.michiels@gmail.com
COMMENT=	External netdata collection plugin written in Go

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	netdata
GH_PROJECT=	go.d.plugin
GH_TUPLE=	Wing924:ltsv:v0.3.1:wing924_ltsv/vendor/github.com/Wing924/ltsv \
		axiomhq:hyperloglog:a4c4c47bc57f:axiomhq_hyperloglog/vendor/github.com/axiomhq/hyperloglog \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgryski:go-metro:280f6062b5bc:dgryski_go_metro/vendor/github.com/dgryski/go-metro \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:v2.2.7:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:87dc89f01550:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:83d349e8ac1a:golang_net/vendor/golang.org/x/net \
		golang:sys:33540a1f6037:golang_sys/vendor/golang.org/x/sys \
		golang:xerrors:1b5146add898:golang_xerrors/vendor/golang.org/x/xerrors \
		google:uuid:6a5e28554805:google_uuid/vendor/github.com/google/uuid \
		jessevdk:go-flags:v1.4.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		layeh:radius:890bc1058917:layeh_radius/vendor/layeh.com/radius \
		mattn:go-isatty:v0.0.7:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		miekg:dns:v1.1.27:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		netdata:go-orchestrator:c793edba0e8f:netdata_go_orchestrator/vendor/github.com/netdata/go-orchestrator \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:prometheus:v2.5.0:prometheus_prometheus/vendor/github.com/prometheus/prometheus \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		vmware:govmomi:v0.22.1:vmware_govmomi/vendor/github.com/vmware/govmomi

GO_TARGET=	./cmd/godplugin:${PREFIX}/libexec/netdata/plugins.d/god.plugin

post-patch:
	${REINPLACE_CMD} -e 's|/etc/netdata|${PREFIX}/etc/netdata|g' ${WRKSRC}/cmd/godplugin/main.go

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/netdata/conf.d
	${INSTALL_DATA} ${WRKSRC}/config/go.d.conf ${STAGEDIR}${PREFIX}/lib/netdata/conf.d/go.d.conf.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/netdata/conf.d/go.d
	cd ${WRKSRC}/config/go.d && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/netdata/conf.d/go.d
	(for file in ${STAGEDIR}${PREFIX}/lib/netdata/conf.d/go.d/*.conf; do \
		${MV} $$file $$file".sample"; \
	done)

.include <bsd.port.mk>
