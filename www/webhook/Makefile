# $FreeBSD$

PORTNAME=	webhook
PORTVERSION=	2.7.0
CATEGORIES=	www

MAINTAINER=	stb@lassitu.de
COMMENT=	Easily create HTTP endpoints (hooks) to execute shell commands

LICENSE=	APACHE20 BSD3CLAUSE MIT
LICENSE_COMB=	multi

USES=		gmake go:modules
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	adnanh
GH_TUPLE=	\
		clbanning:mxj:v1.8.4:clbanning_mxj/vendor/github.com/clbanning/mxj \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fsnotify:fsnotify:v1.4.2:fsnotify_fsnotify/vendor/gopkg.in/fsnotify.v1 \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-chi:chi:v4.0.2:go_chi_chi/vendor/github.com/go-chi/chi \
		go-yaml:yaml:eb3733d160e7:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gofrs:uuid:v3.2.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		golang:sys:04cbcbbfeed8:golang_sys/vendor/golang.org/x/sys \
		gorilla:mux:v1.7.3:gorilla_mux/vendor/github.com/gorilla/mux

USE_RC_SUBR=	webhook

GO_TARGET=	:${PREFIX}/sbin/webhook

PLIST_FILES=	"@sample etc/webhook.yaml.sample" sbin/webhook

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
DAEMONARGS=	-S -l \$${webhook_facility} -s \$${webhook_priority} -t \$${name}
.else
DAEMONARGS=	-f
.endif

SUB_LIST+=	DAEMONARGS="${DAEMONARGS}"

post-install:
	${INSTALL_DATA}  ${FILESDIR}/webhook.yaml ${STAGEDIR}${PREFIX}/etc/webhook.yaml.sample

.include <bsd.port.mk>
