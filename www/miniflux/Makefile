# $FreeBSD$

PORTNAME=	miniflux
DISTVERSION=	2.0.24
CATEGORIES=	www

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Self-hosted software to read RSS/Atom/JSON feeds

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		go:modules

USERS=	miniflux
GROUPS=	miniflux

WANT_PGSQL=	client
USE_RC_SUBR=	miniflux

USE_GITHUB=	yes
GH_TUPLE=	PuerkitoBio:goquery:v1.6.0:goquery/vendor/github.com/PuerkitoBio/goquery \
		andybalholm:cascadia:v1.1.0:cascadia/vendor/github.com/andybalholm/cascadia \
		beorn7:perks:v1.0.1:perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:xxhash/vendor/github.com/cespare/xxhash/v2 \
		coreos:go-oidc:v2.2.1:go_oidc/vendor/github.com/coreos/go-oidc \
		golang:crypto:75b288015ac9:crypto/vendor/golang.org/x/crypto \
		golang:net:4c5254603344:net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.2:protobuf/vendor/github.com/golang/protobuf \
		golang:sys:9d91bd62050c:sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:text/vendor/golang.org/x/text \
		gorilla:mux:v1.8.0:gorilla/vendor/github.com/gorilla/mux \
		lib:pq:v1.8.0:pq/vendor/github.com/lib/pq \
		matttproud:golang_protobuf_extensions:v1.0.1:protobuf_ext/vendor/github.com/matttproud/golang_protobuf_extensions \
		pquerna:cachecontrol:1555304b9b35:cachecontrol/vendor/github.com/pquerna/cachecontrol \
		protocolbuffers:protobuf-go:v1.25.0:protobuf_go/vendor/google.golang.org/protobuf \
		prometheus:client_golang:v1.7.1:client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.14.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.2.0:procfs/vendor/github.com/prometheus/procfs \
		rylans:getlang:4c3188ff8a2d:getlang/vendor/github.com/rylans/getlang \
		square:go-jose:v2.5.0:go_jose/vendor/gopkg.in/square/go-jose.v2 \
		tdewolff:minify:v2.9.7:minify/vendor/github.com/tdewolff/minify/v2

GO_PKGNAME=	miniflux.app
GO_TARGET=	:${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X miniflux.app/version.Version=${DISTVERSION} \
		-X miniflux.app/version.BuildDate=$$(date +'%Y-%m-%dT%H:%M:%SZ')"

OPTIONS_DEFINE=		PGSQL_SERVER
PGSQL_SERVER_DESC=	Install the PostgreSQL Server Component
PGSQL_SERVER_VARS=	WANT_PGSQL=server,contrib

post-install:
	${INSTALL_MAN} ${WRKSRC}/miniflux.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_DATA} ${FILESDIR}/miniflux.env.sample \
		${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
