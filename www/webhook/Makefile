PORTNAME=	webhook
DISTVERSION=	2.8.2
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	stb@lassitu.de
COMMENT=	Easily create HTTP endpoints (hooks) to execute shell commands
WWW=		https://github.com/adnanh/webhook

LICENSE=	APACHE20 BSD3CLAUSE MIT
LICENSE_COMB=	multi

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	adnanh
GH_TUPLE=	Microsoft:go-winio:v0.6.2:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		clbanning:mxj:v2.7.0:clbanning_mxj_v2/vendor/github.com/clbanning/mxj/v2 \
		coreos:go-systemd:v22.5.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fsnotify:fsnotify:v1.7.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-check:check:41f04d3bba15:go_check_check/vendor/gopkg.in/check.v1 \
		go-chi:chi:v5.0.12:go_chi_chi_v5/vendor/github.com/go-chi/chi/v5 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gofrs:uuid:v5.0.0:gofrs_uuid_v5/vendor/github.com/gofrs/uuid/v5 \
		golang:sys:v0.18.0:golang_sys/vendor/golang.org/x/sys \
		google:go-cmp:v0.6.0:google_go_cmp/vendor/github.com/google/go-cmp \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/github.com/gorilla/mux \
		kr:pretty:v0.1.0:kr_pretty/vendor/github.com/kr/pretty

USE_RC_SUBR=	webhook

GO_TARGET=	:${PREFIX}/sbin/webhook

PLIST_FILES=	"@sample etc/webhook.yaml.sample" \
		sbin/webhook

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
DAEMONARGS=	-S -l \$${webhook_facility} -s \$${webhook_priority} -t \
		\$${name}
.else
DAEMONARGS=	-f
.endif

SUB_LIST+=	DAEMONARGS="${DAEMONARGS}"

post-install:
	${INSTALL_DATA}  ${FILESDIR}/webhook.yaml ${STAGEDIR}${PREFIX}/etc/webhook.yaml.sample

.include <bsd.port.mk>
