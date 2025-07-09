PORTNAME=		ooni-mini
DISTVERSIONPREFIX=	v
DISTVERSION=		0.23.0
PORTREVISION=	27
CATEGORIES=		net www benchmarks

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Small command line client that tests OONI's functionality
WWW=		https://ooni.org/about/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		go:modules
USE_GITHUB=	yes
USE_GITLAB=	nodefault

# # github.com/ooni/probe-engine/blob/master/readme_compiletimecheck.go#L6
GO_BUILDFLAGS=	-tags=ooni,nomk,DISABLE_QUIC -ldflags '-s -w -extldflags "-static"'
GO_TARGET=	./cmd/miniooni
GH_ACCOUNT=	ooni
GH_PROJECT=	probe-engine
GH_TUPLE=	apex:log:v1.9.0:apex_log/vendor/github.com/apex/log \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		creack:goselect:v0.1.1:creack_goselect/vendor/github.com/creack/goselect \
		cretz:bine:v0.1.0:cretz_bine/vendor/github.com/cretz/bine \
		dchest:siphash:v1.2.2:dchest_siphash/vendor/github.com/dchest/siphash \
		dsnet:compress:v0.0.1:dsnet_compress/vendor/github.com/dsnet/compress \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		golang:crypto:eec23a3978ad:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:5f4716e94777:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:22da62e12c0c:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.5:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.5.2:google_go_cmp/vendor/github.com/google/go-cmp \
		google:martian:v3.1.0:google_martian_v3/vendor/github.com/google/martian/v3 \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		iancoleman:strcase:v0.1.3:iancoleman_strcase/vendor/github.com/iancoleman/strcase \
		lucas-clemente:quic-go:v0.19.3:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		marten-seemann:qpack:v0.2.1:marten_seemann_qpack/vendor/github.com/marten-seemann/qpack \
		marten-seemann:qtls-go1-15:v0.1.1:marten_seemann_qtls_go1_15/vendor/github.com/marten-seemann/qtls-go1-15 \
		marten-seemann:qtls:v0.10.0:marten_seemann_qtls/vendor/github.com/marten-seemann/qtls \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		miekg:dns:v1.1.35:miekg_dns/vendor/github.com/miekg/dns \
		montanaflynn:stats:v0.6.4:montanaflynn_stats/vendor/github.com/montanaflynn/stats \
		ooni:psiphon:v0.4.0:ooni_psiphon/vendor/github.com/ooni/psiphon \
		oschwald:geoip2-golang:v1.4.0:oschwald_geoip2_golang/vendor/github.com/oschwald/geoip2-golang \
		oschwald:maxminddb-golang:v1.8.0:oschwald_maxminddb_golang/vendor/github.com/oschwald/maxminddb-golang \
		pborman:getopt:v2.1.0:pborman_getopt_v2/vendor/github.com/pborman/getopt \
		pion:stun:v0.3.5:pion_stun/vendor/github.com/pion/stun \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rogpeppe:go-internal:v1.7.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal

GH_TUPLE+=	marten-seemann:qtls-go1-16:v0.1.3:marten_seemann_qtls_go1_16/vendor/github.com/marten-seemann/qtls-go1-16 \
		torbsd:goptlib:v1.1.0:torbsd_goptlib/vendor/git.torproject.org/pluggable-transports/goptlib.git

GL_TUPLE=	yawning:bsaes:26d1add596b6d800bdeeb3bc3b2c7b316c056b6d:yawning_bsaes/vendor/git.schwanenlied.me/yawning/bsaes.git \
		yawning:obfs4:f638c33f6c6f697498150d5f0dfbf26453759262:yawning_obfs4/vendor/gitlab.com/yawning/obfs4.git \
		yawning:utls:ad258eb64575fd468dbd2f93ef229df5f7fe72b4:yawning_utls/vendor/gitlab.com/yawning/utls.git

PLIST_FILES=	bin/miniooni

.include <bsd.port.mk>
