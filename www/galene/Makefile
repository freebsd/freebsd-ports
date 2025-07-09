PORTNAME=	galene
DISTVERSION=	0.96.3
PORTREVISION=	3
CATEGORIES=	www net-im

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	The Galène videoconference server
WWW=		https://galene.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	jech
GH_TAGNAME=	${PORTNAME}-${DISTVERSION}

GO_TARGET=	galene ./galenectl

GH_TUPLE=	\
		at-wat:ebml-go:v0.17.1:at_wat_ebml_go/vendor/github.com/at-wat/ebml-go \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang-jwt:jwt:v5.2.1:golang_jwt_jwt_v5/vendor/github.com/golang-jwt/jwt/v5 \
		golang:crypto:v0.31.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.33.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.28.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.27.0:golang_term/vendor/golang.org/x/term \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		jech:cert:f491cf43a77d:jech_cert/vendor/github.com/jech/cert \
		jech:samplebuilder:6cbba09fc1c9:jech_samplebuilder/vendor/github.com/jech/samplebuilder \
		pion:datachannel:v1.5.10:pion_datachannel/vendor/github.com/pion/datachannel \
		pion:dtls:v2.2.12:pion_dtls_v2/vendor/github.com/pion/dtls/v2 \
		pion:ice:v2.3.37:pion_ice_v2/vendor/github.com/pion/ice/v2 \
		pion:interceptor:v0.1.37:pion_interceptor/vendor/github.com/pion/interceptor \
		pion:logging:v0.2.2:pion_logging/vendor/github.com/pion/logging \
		pion:mdns:v0.0.12:pion_mdns/vendor/github.com/pion/mdns \
		pion:randutil:v0.1.0:pion_randutil/vendor/github.com/pion/randutil \
		pion:rtcp:v1.2.15:pion_rtcp/vendor/github.com/pion/rtcp \
		pion:rtp:v1.8.10:pion_rtp/vendor/github.com/pion/rtp \
		pion:sctp:v1.8.35:pion_sctp/vendor/github.com/pion/sctp \
		pion:sdp:v3.0.9:pion_sdp_v3/vendor/github.com/pion/sdp/v3 \
		pion:srtp:v2.0.20:pion_srtp_v2/vendor/github.com/pion/srtp/v2 \
		pion:stun:v0.6.1:pion_stun/vendor/github.com/pion/stun \
		pion:transport:v2.2.10:pion_transport_v2/vendor/github.com/pion/transport/v2 \
		pion:transport:v3.0.7:pion_transport_v3/vendor/github.com/pion/transport/v3 \
		pion:turn:v2.1.6:pion_turn_v2/vendor/github.com/pion/turn/v2 \
		pion:webrtc:v3.3.5:pion_webrtc_v3/vendor/github.com/pion/webrtc/v3 \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		stretchr:testify:v1.10.0:stretchr_testify/vendor/github.com/stretchr/testify \
		wlynxg:anet:v0.0.5:wlynxg_anet/vendor/github.com/wlynxg/anet

CGO_ENABLED=	0

PORTDOCS=	README README.FRONTEND README.PROTOCOL

OPTIONS_DEFINE=	DOCS

USE_RC_SUBR=	${PORTNAME}

USERS=	${PORTNAME}
GROUPS=	${PORTNAME}

SUB_LIST=	USERS="${USERS}" GROUPS="${GROUPS}"
PLIST_SUB=	USERS="${USERS}" GROUPS="${GROUPS}"

post-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/galenectl ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/static ; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}/var/db/galene/recordings \
		${STAGEDIR}/var/db/galene/data \
		${STAGEDIR}/var/db/galene/groups

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
