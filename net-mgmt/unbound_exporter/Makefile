# Created by: Athanasios Douitsis <aduitsis@cpan.org>
# $FreeBSD$

PORTNAME=		unbound_exporter
PORTVERSION=		0.1
DISTVERSIONPREFIX=	v
PORTREVISION=		3
CATEGORIES=		net-mgmt

MAINTAINER=		aduitsis@cpan.org
COMMENT=		Prometheus metrics exporter for the Unbound DNS resolver

LICENSE=		APACHE20

USES=			go
USE_GITHUB=		yes
USE_RC_SUBR=		unbound_exporter

GH_ACCOUNT=		kumina
GH_TAGNAME=		b7e842d893d29200a5108eab717f5ab01d783c0c
GH_TUPLE=		prometheus:client_golang:3fb53d:client_golang/vendor/github.com/prometheus/client_golang \
			prometheus:client_model:6f38060:client_model/vendor/github.com/prometheus/client_model \
			prometheus:common:49fee29:common/vendor/github.com/prometheus/common \
			prometheus:procfs:a1dba9c:procfs/vendor/github.com/prometheus/procfs \
			beorn7:perks:4c0e845:perks/vendor/github.com/beorn7/perks \
			golang:protobuf:2bba060:protobuf/vendor/github.com/golang/protobuf \
			matttproud:golang_protobuf_extensions:c12348c:extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
			sirupsen:logrus:91da99d:logrus/vendor/github.com/Sirupsen/logrus \
			golang:crypto:3d3f9f41:crypto/vendor/golang.org/x/crypto \
			golang:sys:93218def:sys/vendor/golang.org/x/sys

GO_PKGNAME=		github.com/${GH_ACCOUNT}/${PORTNAME}

USERS=			unbound
GROUPS=			unbound

PLIST_FILES=		bin/unbound_exporter

.include <bsd.port.mk>
