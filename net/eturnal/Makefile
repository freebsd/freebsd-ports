PORTNAME=	eturnal
DISTVERSION=	1.12.2
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	yzrh@noema.org
COMMENT=	Modern, straightforward STUN and TURN server
WWW=		https://eturnal.net/

LICENSE=	APACHE20

LIB_DEPENDS=	libyaml.so:textproc/libyaml

USES=		compiler:c11 cpe erlang:rebar3 ssl
CPE_VENDOR=	process-one
USE_GITHUB=	yes
GH_TUPLE=	processone:eturnal:${DISTVERSION} \
		blt:port_compiler:${PC_VERSION}:pc/_checkouts/pc \
		ferd:recon:${RECON_VERSION}:recon/_checkouts/recon \
		odo:quantile_estimator:${QUANTILE_ESTIMATOR_VERSION}:quantile_estimator/_checkouts/quantile_estimator \
		processone:stun:${STUN_VERSION}:stun/_checkouts/stun \
		weiss:conf:${CONF_VERSION}:conf/_checkouts/conf \
		processone:yval:${YVAL_VERSION}:yval/_checkouts/yval \
		processone:fast_yaml:${FAST_YAML_VERSION}:fast_yaml/_checkouts/fast_yaml \
		processone:fast_tls:${FAST_TLS_VERSION}:fast_tls/_checkouts/fast_tls \
		processone:p1_utils:${P1_UTILS_VERSION}:p1_utils/_checkouts/p1_utils \
		palkan:influx_udp:${INFLUX_UDP_VERSION}:influx_udp/_checkouts/influx_udp \
		devinus:poolboy:${POOLBOY_VERSION}:poolboy/_checkouts/poolboy \
		palkan:ulitos:${ULITOS_VERSION}:ulitos/_checkouts/ulitos \
		prometheus-erl:prometheus-httpd:${PROMETHEUS_HTTPD_VERSION}:prometheus_httpd/_checkouts/prometheus_httpd \
		prometheus-erl:prometheus.erl:${PROMETHEUS_VERSION}:prometheus/_checkouts/prometheus \
		prometheus-erl:accept:${ACCEPT_VERSION}:accept/_checkouts/accept
USE_RC_SUBR=	${PORTNAME}

# USES=erlang related variables
REBAR_PROFILE=	distro
REBAR_TARGETS=	release

USERS=		${PORTNAME}
GROUPS=		${USERS}

.ifnmake portclippy
ACCEPT_VERSION=			e1faefa # 0.3.6
CONF_VERSION=			1d80a8b # 0.2.6
FAST_TLS_VERSION=		1.1.22
FAST_YAML_VERSION=		1.0.37
INFLUX_UDP_VERSION=		c744ccf # 1.1.2
P1_UTILS_VERSION=		1.0.26
PC_VERSION=			935c207 # 1.15.0
POOLBOY_VERSION=		1.5.2
PROMETHEUS_HTTPD_VERSION=	849deb3 # 2.1.14
PROMETHEUS_VERSION=		09b95f8 # 4.13.0
QUANTILE_ESTIMATOR_VERSION=	3c4c505 # 1.0.2
RECON_VERSION=			2.5.6
STUN_VERSION=			1.2.19
ULITOS_VERSION=			0.4.0
YVAL_VERSION=			1.0.10
.endif

PLIST_SUB=	CONF_VERSION=0.2.6 \
		FAST_TLS_VERSION=${FAST_TLS_VERSION} \
		FAST_YAML_VERSION=${FAST_YAML_VERSION} \
		P1_UTILS_VERSION=${P1_UTILS_VERSION} \
		STUN_VERSION=${STUN_VERSION} \
		YVAL_VERSION=${YVAL_VERSION}

post-patch:
	${REINPLACE_CMD} -e 's|/opt/eturnal|${LOCALBASE}/lib/eturnal|' \
		-e 's|/etc|${LOCALBASE}/etc/eturnal|' \
		-e 's|static|dynamic|' \
		${WRKSRC}/build.config
	${REINPLACE_CMD} 's|-/etc|-${LOCALBASE}/etc/eturnal|' \
		${WRKSRC}/overlay/eturnalctl

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/eturnal
	cd ${WRKSRC}/_build/${REBAR_PROFILE}/rel/eturnal && \
		${COPYTREE_BIN} bin ${STAGEDIR}${PREFIX}/lib/eturnal/
	cd ${WRKSRC}/_build/${REBAR_PROFILE}/rel/eturnal && \
		${COPYTREE_SHARE} lib ${STAGEDIR}${PREFIX}/lib/eturnal/
	cd ${WRKSRC}/_build/${REBAR_PROFILE}/rel/eturnal && \
		${COPYTREE_SHARE} releases ${STAGEDIR}${PREFIX}/lib/eturnal/
	${REINPLACE_CMD} 's|__erts_dir="$$RELEASE_ROOT_DIR/erts-$$ERTS_VSN"|__erts_dir="${LOCALBASE}/lib/erlang/erts-$$ERTS_VSN"|' \
		${STAGEDIR}${PREFIX}/lib/eturnal/bin/eturnal
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/eturnal
	${INSTALL_DATA} ${WRKSRC}/_build/${REBAR_PROFILE}/rel/eturnal/etc/eturnal.yml \
		${STAGEDIR}${PREFIX}/etc/eturnal/eturnal.yml.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/_build/${REBAR_PROFILE}/rel/eturnal/doc/README.md \
		${STAGEDIR}${DOCSDIR}/
	${RLN} ${STAGEDIR}${PREFIX}/lib/eturnal/bin/eturnalctl ${STAGEDIR}${PREFIX}/sbin/eturnalctl
	${MKDIR} ${STAGEDIR}/var/log/eturnal
	${FIND} ${STAGEDIR}${PREFIX}/lib/eturnal/lib -type f -name '*.so' \
		-exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
