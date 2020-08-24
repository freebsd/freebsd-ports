# $FreeBSD$

PORTNAME=	miniflux
DISTVERSION=	2.0.23
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
GH_TUPLE=	PuerkitoBio:goquery:v1.5.1:goquery/vendor/github.com/PuerkitoBio/goquery \
		andybalholm:cascadia:v1.1.0:cascadia/vendor/github.com/andybalholm/cascadia \
		coreos:go-oidc:v2.2.1:go_oidc/vendor/github.com/coreos/go-oidc \
		golang:crypto:4bdfaf469ed5:crypto/vendor/golang.org/x/crypto \
		golang:net:ff2c4b7c35a0:net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.0:protobuf/vendor/github.com/golang/protobuf \
		golang:sys:1957bb5e6d1f:sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:text/vendor/golang.org/x/text \
		gorilla:mux:v1.7.4:gorilla/vendor/github.com/gorilla/mux \
		lib:pq:v1.8.0:pq/vendor/github.com/lib/pq \
		pquerna:cachecontrol:1555304b9b35:cachecontrol/vendor/github.com/pquerna/cachecontrol \
		square:go-jose:v2.5.0:go_jose/vendor/gopkg.in/square/go-jose.v2 \
		tdewolff:minify:v2.7.4:minify/vendor/github.com/tdewolff/minify/v2

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
