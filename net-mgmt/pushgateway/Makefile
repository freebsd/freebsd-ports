# Created by: Athanasios Douitsis <aduitsis@cpan.org>
# $FreeBSD$

PORTNAME=	pushgateway
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
CATEGORIES=	net-mgmt

MAINTAINER=	aduitsis@cpan.org
COMMENT=	Prometheus push acceptor for ephemeral and batch jobs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
GH_TUPLE=       \
                alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
                alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
                alecthomas:units:c3de453c63f4:alecthomas_units/vendor/github.com/alecthomas/units \
                beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
                go-kit:kit:v0.9.0:go_kit_kit/vendor/github.com/go-kit/kit \
                go-logfmt:logfmt:v0.4.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
                golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
                golang:sys:cbf593c0f2f3:golang_sys/vendor/golang.org/x/sys \
                julienschmidt:httprouter:v1.2.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
                kr:logfmt:b84e30acd515:kr_logfmt/vendor/github.com/kr/logfmt \
                matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
                pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
                prometheus:client_golang:v1.1.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
                prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
                prometheus:common:v0.6.0:prometheus_common/vendor/github.com/prometheus/common \
                prometheus:procfs:v0.0.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
                shurcooL:httpfs:8d4bc4ba7749:shurcool_httpfs/vendor/github.com/shurcooL/httpfs \
                shurcooL:vfsgen:6a9ea43bcacd:shurcool_vfsgen/vendor/github.com/shurcooL/vfsgen

USE_RC_SUBR=	pushgateway

USERS=		prometheus
GROUPS=		prometheus

do-test:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GMAKE} test)

.include <bsd.port.mk>
