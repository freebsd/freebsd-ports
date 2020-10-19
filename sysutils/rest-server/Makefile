# $FreeBSD$

PORTNAME=	rest-server
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Performant HTTP server for sysutils/restic backend API

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	restic
GH_TUPLE=	\
		beorn7:perks:4c0e84591b9a:beorn7_perks/vendor/github.com/beorn7/perks \
		goji:goji:v2.0.0:goji_goji/vendor/goji.io \
		goji:goji:v2.0.2:goji_goji_1 \
		golang:crypto:650f4a345ab4:golang_crypto/vendor/golang.org/x/crypto \
		golang:protobuf:v1.0.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:43a5402ce75a:golang_sync/vendor/golang.org/x/sync \
		gorilla:handlers:v1.3.0:gorilla_handlers/vendor/github.com/gorilla/handlers \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		matttproud:golang_protobuf_extensions:v1.0.0:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miolini:datacounter:fd4e42a1d5e0:miolini_datacounter/vendor/github.com/miolini/datacounter \
		prometheus:client_golang:v0.8.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:99fa1f4be8e5:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:89604d197083:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:282c8707aa21:prometheus_procfs/vendor/github.com/prometheus/procfs \
		spf13:cobra:v0.0.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.0:spf13_pflag/vendor/github.com/spf13/pflag

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/cmd/${PORTNAME}

post-extract:
	@${RLN} ${WRKSRC_goji_goji_1} ${WRKSRC}/vendor/goji.io

USE_RC_SUBR=	restserver

USERS=		restserver
GROUPS=		restserver

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
