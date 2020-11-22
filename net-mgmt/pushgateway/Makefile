# Created by: Athanasios Douitsis <aduitsis@cpan.org>
# $FreeBSD$

PORTNAME=	pushgateway
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	net-mgmt

MAINTAINER=	0xdutra@gmail.com
COMMENT=	Prometheus push acceptor for ephemeral and batch jobs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	prometheus

PLIST_FILES=	bin/pushgateway

GH_TUPLE=	\
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:f65c72e2690d:alecthomas_units/vendor/github.com/alecthomas/units \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		go-kit:kit:v0.9.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-logfmt:logfmt:v0.4.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:06d7bd2c5f4f:golang_sys/vendor/golang.org/x/sys \
		julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		kr:logfmt:b84e30acd515:kr_logfmt/vendor/github.com/kr/logfmt \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.1.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:14fe0d1b01d4:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.7.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.5:prometheus_procfs/vendor/github.com/prometheus/procfs \
		shurcooL:httpfs:8d4bc4ba7749:shurcool_httpfs/vendor/github.com/shurcooL/httpfs \
		shurcooL:vfsgen:6a9ea43bcacd:shurcool_vfsgen/vendor/github.com/shurcooL/vfsgen

USE_RC_SUBR=	pushgateway

USERS=		prometheus
GROUPS=		prometheus

do-test:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GMAKE} test)

.include <bsd.port.mk>
