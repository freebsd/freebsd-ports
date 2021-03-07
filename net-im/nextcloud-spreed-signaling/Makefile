# $FreeBSD$

PORTNAME=	nextcloud-spreed-signaling
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	net-im

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Signaling server used for Nextcloud Talk

LICENSE=	AGPLv3

BUILD_DEPENDS=	go:lang/go

USES=		gmake
USERS=		signaling
GROUPS=		signaling

USE_RC_SUBR=	ncs_signaling

USE_GITHUB=	yes
GH_ACCOUNT=	strukturag
GH_TUPLE=	coreos:go-semver:v0.2.0:coreos_go_semver/vendor/src/github.com/coreos/go-semver \
		coreos:go-systemd:39ca1b05acc7:coreos_go_systemd/vendor/src/github.com/coreos/go-systemd \
		coreos:pkg:3ac0863d7acf:coreos_pkg/vendor/src/github.com/coreos/pkg \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/src/gopkg.in/dgrijalva/jwt-go.v3 \
		dlintw:goconf:dcc070983490:dlintw_goconf/vendor/src/github.com/dlintw/goconf \
		etcd-io:etcd:ae9734ed278b:etcd_io_etcd/vendor/src/go.etcd.io/etcd \
		gogo:protobuf:v1.2.1:gogo_protobuf/vendor/src/github.com/gogo/protobuf \
		golang:crypto:0ec3e9974c59:golang_crypto/vendor/src/golang.org/x/crypto \
		golang:net:74dc4d7220e7:golang_net/vendor/src/golang.org/x/net \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/src/github.com/golang/protobuf \
		golang:sys:c7b8b68b1456:golang_sys/vendor/src/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/src/golang.org/x/text \
		google:go-genproto:24fa4b261c55:google_go_genproto/vendor/src/google.golang.org/genproto \
		google:uuid:v1.1.2:google_uuid/vendor/src/github.com/google/uuid \
		gorilla:context:v1.1.1:gorilla_context/vendor/src/github.com/gorilla/context \
		gorilla:mux:ac112f7d75a0:gorilla_mux/vendor/src/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/src/github.com/gorilla/securecookie \
		gorilla:websocket:v1.2.0:gorilla_websocket/vendor/src/github.com/gorilla/websocket \
		grpc:grpc-go:v1.26.0:grpc_grpc_go/vendor/src/google.golang.org/grpc \
		mailru:easyjson:2f5df55504eb:mailru_easyjson/vendor/src/github.com/mailru/easyjson \
		nats-io:jwt:v0.3.2:nats_io_jwt/vendor/src/github.com/nats-io/jwt \
		nats-io:nats.go:v1.10.0:nats_io_nats_go/vendor/src/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.1.4:nats_io_nkeys/vendor/src/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/src/github.com/nats-io/nuid \
		notedit:janus-go:10eb8b95d1a0:notedit_janus_go/vendor/src/github.com/notedit/janus-go \
		oschwald:maxminddb-golang:1960b16a5147:oschwald_maxminddb_golang/vendor/src/github.com/oschwald/maxminddb-golang \
		uber-go:atomic:v1.3.2:uber_go_atomic/vendor/src/go.uber.org/atomic \
		uber-go:multierr:v1.1.0:uber_go_multierr/vendor/src/go.uber.org/multierr \
		uber-go:zap:v1.10.0:uber_go_zap/vendor/src/go.uber.org/zap 

MAKE_ENV=	GO111MODULE="off"

.include <bsd.port.mk>
