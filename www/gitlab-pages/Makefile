# $FreeBSD$

PORTNAME=	gitlab-pages
PORTVERSION=	1.16.0
CATEGORIES=	www

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Official GitLab Pages daemon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules

USE_GITLAB=	yes
USE_GITHUB=	nodefault

GL_ACCOUNT=	gitlab-org
# Find the here: https://gitlab.com/gitlab-org/gitlab-pages/tags
GL_COMMIT=	1fe3f552049912c98063d67ca6a0c2da626cb324

# Build with: make gomod-vendor
# 43dd
GH_TUPLE=	\
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		certifi:gocertifi:a5e0173ced67:certifi_gocertifi/vendor/github.com/certifi/gocertifi \
		client9:reopen:v1.0.0:client9_reopen/vendor/github.com/client9/reopen \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		fzipp:gocyclo:6acd4345c835:fzipp_gocyclo/vendor/github.com/fzipp/gocyclo \
		getsentry:raven-go:v0.1.2:getsentry_raven_go/vendor/github.com/getsentry/raven-go \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:227b76d455e7:golang_crypto/vendor/golang.org/x/crypto \
		golang:lint:16217165b5de:golang_lint/vendor/golang.org/x/lint \
		golang:mock:v1.3.1:golang_mock/vendor/github.com/golang/mock \
		golang:net:a7b16738d86b:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:bbd175535a8b:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		golang:tools:e5ffc44a6fee:golang_tools/vendor/golang.org/x/tools \
		gorilla:context:v1.1.1:gorilla_context/vendor/github.com/gorilla/context \
		gorilla:handlers:v1.4.2:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:sessions:v1.2.0:gorilla_sessions/vendor/github.com/gorilla/sessions \
		kardianos:osext:2bc1f35cddc0:kardianos_osext/vendor/github.com/kardianos/osext \
		karrick:godirwalk:v1.10.12:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		namsral:flag:v1.7.4-pre:namsral_flag/vendor/github.com/namsral/flag \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.1.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.6.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		sebest:xff:6c115e0ffa35:sebest_xff/vendor/github.com/sebest/xff \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:objx:v0.1.1:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tomasen:realip:f0c99a92ddce:tomasen_realip/vendor/github.com/tomasen/realip \
		wadey:gocovmerge:b5bfa59ec0ad:wadey_gocovmerge/vendor/github.com/wadey/gocovmerge

GL_TUPLE=	gitlab-org:labkit:3253d7975ca73714779c0a1fc95a27fb678071b6:gitlab_org_labkit/vendor/gitlab.com/gitlab-org/labkit \
		lupine:go-mimedb:e8af1d65987739a7ab277dedd9772c7398154ff3:lupine_go_mimedb/vendor/gitlab.com/lupine/go-mimedb

GO_BUILDFLAGS=	-ldflags="-X main.VERSION=${PORTVERSION} -X main.REVISION=${GITHASH}"
GO_PKGNAME=	gitlab.com/gitlab-org/gitlab-pages

PLIST_FILES=	bin/gitlab-pages

USE_RC_SUBR=	gitlab_pages

USERS=		gitlab-pages
GROUPS=		gitlab-pages

GO_BUILDFLAGS+=	--ldflags="-X main.VERSION=${PORTVERSION} -X main.REVISION=${GITHASH}"

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/gitlab-pages ${STAGEDIR}${PREFIX}/bin/gitlab-pages

.include <bsd.port.mk>
