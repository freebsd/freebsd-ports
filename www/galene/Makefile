PORTNAME=	galene
DISTVERSION=	1.0
PORTREVISION=	1
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
		golang-jwt:jwt:v5.3.0:golang_jwt_jwt_v5/vendor/github.com/golang-jwt/jwt/v5 \
		golang:crypto:v0.33.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.35.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.30.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.29.0:golang_term/vendor/golang.org/x/term \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		jech:cert:f491cf43a77d:jech_cert/vendor/github.com/jech/cert \
		jech:samplebuilder:76c654ae55e1:jech_samplebuilder/vendor/github.com/jech/samplebuilder \
		pion:datachannel:v1.5.10:pion_datachannel/vendor/github.com/pion/datachannel \
		pion:dtls:v3.0.6:pion_dtls_v3/vendor/github.com/pion/dtls/v3 \
		pion:ice:v4.0.10:pion_ice_v4/vendor/github.com/pion/ice/v4 \
		pion:interceptor:v0.1.40:pion_interceptor/vendor/github.com/pion/interceptor \
		pion:logging:v0.2.4:pion_logging/vendor/github.com/pion/logging \
		pion:mdns:v2.0.7:pion_mdns_v2/vendor/github.com/pion/mdns/v2 \
		pion:randutil:v0.1.0:pion_randutil/vendor/github.com/pion/randutil \
		pion:rtcp:v1.2.15:pion_rtcp/vendor/github.com/pion/rtcp \
		pion:rtp:v1.8.20:pion_rtp/vendor/github.com/pion/rtp \
		pion:sctp:v1.8.39:pion_sctp/vendor/github.com/pion/sctp \
		pion:sdp:v3.0.14:pion_sdp_v3/vendor/github.com/pion/sdp/v3 \
		pion:srtp:v3.0.6:pion_srtp_v3/vendor/github.com/pion/srtp/v3 \
		pion:stun:v3.0.0:pion_stun_v3/vendor/github.com/pion/stun/v3 \
		pion:transport:v3.0.7:pion_transport_v3/vendor/github.com/pion/transport/v3 \
		pion:turn:v4.0.2:pion_turn_v4/vendor/github.com/pion/turn/v4 \
		pion:webrtc:v4.1.3:pion_webrtc_v4/vendor/github.com/pion/webrtc/v4 \
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
