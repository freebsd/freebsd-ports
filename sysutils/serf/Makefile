PORTNAME=	serf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.2
PORTREVISION=	7
CATEGORIES=	sysutils
PKGNAMEPREFIX=	hashicorp-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Service discovery and configuration made easy
WWW=		https://www.serf.io/

LICENSE=	MPL20

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_TUPLE=	\
		Masterminds:goutils:v1.1.1:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v3.1.1:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.2.1:masterminds_sprig_v3/vendor/github.com/Masterminds/sprig/v3 \
		armon:circbuf:bbbad097214e:armon_circbuf/vendor/github.com/armon/circbuf \
		armon:go-metrics:v0.4.1:armon_go_metrics/vendor/github.com/armon/go-metrics \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		bgentry:speakeasy:v0.1.0:bgentry_speakeasy/vendor/github.com/bgentry/speakeasy \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		golang:crypto:v0.17.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.13.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.17.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.15.0:golang_sys/vendor/golang.org/x/sys \
		golang:tools:v0.14.0:golang_tools/vendor/golang.org/x/tools \
		google:btree:v1.1.2:google_btree/vendor/github.com/google/btree \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-immutable-radix:v1.3.1:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-metrics:v0.5.4:hashicorp_go_metrics/vendor/github.com/hashicorp/go-metrics \
		hashicorp:go-msgpack:v2.1.2:hashicorp_go_msgpack_v2/vendor/github.com/hashicorp/go-msgpack/v2 \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-sockaddr:v1.0.5:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-syslog:v1.0.0:hashicorp_go_syslog/vendor/github.com/hashicorp/go-syslog \
		hashicorp:go-uuid:v1.0.1:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:golang-lru:v1.0.2:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:logutils:v1.0.0:hashicorp_logutils/vendor/github.com/hashicorp/logutils \
		hashicorp:mdns:v1.0.5:hashicorp_mdns/vendor/github.com/hashicorp/mdns \
		hashicorp:memberlist:v0.5.2:hashicorp_memberlist/vendor/github.com/hashicorp/memberlist \
		huandu:xstrings:v1.3.2:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.11:imdario_mergo/vendor/github.com/imdario/mergo \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		miekg:dns:v1.1.56:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:cli:v1.1.5:mitchellh_cli/vendor/github.com/mitchellh/cli \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.0:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		posener:complete:v1.2.3:posener_complete/vendor/github.com/posener/complete \
		ryanuber:columnize:v2.1.2:ryanuber_columnize/vendor/github.com/ryanuber/columnize \
		sean-:seed:e2103e2c3529:sean__seed/vendor/github.com/sean-/seed \
		shopspring:decimal:v1.2.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast
USE_RC_SUBR=	serf

GO_TARGET=	./cmd/${PORTNAME}

USERS=		serf
GROUPS=		serf

PLIST_FILES=	bin/serf

.include <bsd.port.mk>
