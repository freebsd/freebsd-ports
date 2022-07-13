PORTNAME=		snowflake
DISTVERSIONPREFIX=	v
DISTVERSION=		2.1.0
PORTREVISION=	3
CATEGORIES=		security net
PKGNAMESUFFIX=		-tor

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Pluggable Transport using WebRTC inspired by Flashproxy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-${TPO_SNOWFLAKE}/LICENSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		cpe go
USE_RC_SUBR=	${PORTNAME}
USE_GITHUB=	nodefault
USE_GITLAB=	nodefault
CPE_VENDOR=	torproject
TPO_GEOIP=	7ce4b3d98d01ff33bad8007db3f488d5b172382a
TPO_SNOWFLAKE=	e6e5e20ae8b5883b37f5dea656540825e237d820

GO_PKGNAME=	git.torproject.org/pluggable-transports/snowflake.git/v2
GO_TARGET=	./client ./proxy ./server

GL_SITE=	https://gitlab.torproject.org/tpo
GL_TUPLE=	anti-censorship:pluggable-transports/${PORTNAME}:${TPO_SNOWFLAKE}:tpo_acs_snowflake/vendor/git.torproject.org/pluggable-transports/snowflake.git/v2 \
		anti-censorship:geoip:${TPO_GEOIP}:tpo_acs_geoip/vendor/gitlab.torproject.org/tpo/anti-censorship/geoip

GH_TUPLE=	torbsd:goptlib:v1.2.0:torbsd_goptlib/vendor/git.torproject.org/pluggable-transports/goptlib.git \
	beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
	cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
	golang:crypto:513c2a44f670:golang_crypto/vendor/golang.org/x/crypto \
	golang:mod:v0.3.0:golang_mod/vendor/golang.org/x/mod \
	golang:net:d523dce5a7f4:golang_net/vendor/golang.org/x/net \
	golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
	golang:sys:c4fcb01b228e:golang_sys/vendor/golang.org/x/sys \
	golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
	golang:tools:5bf02b21f123:golang_tools/vendor/golang.org/x/tools \
	golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
	google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
	gopherjs:gopherjs:0766667cb4d1:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
	gorilla:websocket:v1.4.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
	jtolds:gls:v4.20.0:jtolds_gls/vendor/github.com/jtolds/gls \
	klauspost:cpuid:v1.3.1:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
	klauspost:reedsolomon:v1.9.9:klauspost_reedsolomon/vendor/github.com/klauspost/reedsolomon \
	matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
	mmcloughlin:avo:443f81d77104:mmcloughlin_avo/vendor/github.com/mmcloughlin/avo \
	pion:datachannel:v1.4.21:pion_datachannel/vendor/github.com/pion/datachannel \
	pion:dtls:v2.0.12:pion_dtls_v2/vendor/github.com/pion/dtls/v2 \
	pion:ice:v2.0.15:pion_ice_v2/vendor/github.com/pion/ice/v2 \
	pion:interceptor:v0.0.10:pion_interceptor/vendor/github.com/pion/interceptor \
	pion:logging:v0.2.2:pion_logging/vendor/github.com/pion/logging \
	pion:mdns:v0.0.4:pion_mdns/vendor/github.com/pion/mdns \
	pion:randutil:v0.1.0:pion_randutil/vendor/github.com/pion/randutil \
	pion:rtcp:v1.2.6:pion_rtcp/vendor/github.com/pion/rtcp \
	pion:rtp:v1.6.2:pion_rtp/vendor/github.com/pion/rtp \
	pion:sctp:v1.7.11:pion_sctp/vendor/github.com/pion/sctp \
	pion:sdp:v3.0.4:pion_sdp_v3/vendor/github.com/pion/sdp/v3 \
	pion:srtp:v2.0.2:pion_srtp_v2/vendor/github.com/pion/srtp/v2 \
	pion:stun:v0.3.5:pion_stun/vendor/github.com/pion/stun \
	pion:transport:v0.12.3:pion_transport/vendor/github.com/pion/transport \
	pion:turn:v2.0.5:pion_turn_v2/vendor/github.com/pion/turn/v2 \
	pion:udp:v0.1.0:pion_udp/vendor/github.com/pion/udp \
	pion:webrtc:v3.0.15:pion_webrtc_v3/vendor/github.com/pion/webrtc/v3 \
	pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
	prometheus:client_golang:v1.10.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
	prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
	prometheus:common:v0.18.0:prometheus_common/vendor/github.com/prometheus/common \
	prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
	protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
	smartystreets:assertions:b2de0cb4f26d:smartystreets_assertions/vendor/github.com/smartystreets/assertions \
	smartystreets:goconvey:v1.6.4:smartystreets_goconvey/vendor/github.com/smartystreets/goconvey \
	stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
	templexxx:cpu:v0.0.7:templexxx_cpu/vendor/github.com/templexxx/cpu \
	templexxx:xorsimd:v0.4.1:templexxx_xorsimd/vendor/github.com/templexxx/xorsimd \
	tjfoc:gmsm:v1.3.2:tjfoc_gmsm/vendor/github.com/tjfoc/gmsm \
	xtaci:kcp-go:v5.6.1:xtaci_kcp_go_v5/vendor/github.com/xtaci/kcp-go/v5 \
	xtaci:smux:v1.5.15:xtaci_smux/vendor/github.com/xtaci/smux

PLIST_SUB=	MANPAGES=${MANPAGES}
SUB_FILES=	pkg-message

pre-extract:
	${MKDIR} ${WRKDIR}/pluggable-transports ${WRKDIR}/${PORTNAME}-${TPO_SNOWFLAKE} && \
	${RLN} ${WRKDIR}/${PORTNAME}-${TPO_SNOWFLAKE} ${WRKDIR}/pluggable-transports/. && \
	${LN} -sf ${WRKDIR}/${PORTNAME}-${TPO_SNOWFLAKE} ${WRKSRC} && \
	${LN} -sf ${WRKSRC}/vendor ${WRKSRC}/src

post-install:
	${MKDIR} ${STAGEDIR}/${MANPREFIX}/man/man1
.	for b in client proxy
	  ${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}-$b.1 ${STAGEDIR}/${MANPREFIX}/man/man1
	  ${MV} ${STAGEDIR}/${PREFIX}/bin/$b ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}-$b
.	endfor
	${MV} ${STAGEDIR}/${PREFIX}/bin/server ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
