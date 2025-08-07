PORTNAME=	honeytrap
DISTVERSION=	g20210510
PORTREVISION=	29
CATEGORIES=	security

MAINTAINER=	ezri.mudde@dutchsec.com
COMMENT=	Framework for running, monitoring and managing honeypots
WWW=		https://docs.honeytrap.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_BUILDFLAGS=	-ldflags \
		'-X github.com/honeytrap/honeytrap/cmd.Version=2021-05-10T00:00:00 \
		-X github.com/honeytrap/honeytrap/cmd.ReleaseTag=DEVELOPMENT.2021-05-10T00-00-00Z \
		-X github.com/honeytrap/honeytrap/cmd.CommitID=110030494f54421d01edfb57343aee3a102dc37d \
		-X github.com/honeytrap/honeytrap/cmd.ShortCommitID=110030494f54 \
		-extldflags "-static"'
USE_GITHUB=	yes
GH_TAGNAME=	1100304
GH_TUPLE=	\
		AndreasBriese:bbloom:28f7e881ca57:andreasbriese_bbloom/vendor/github.com/AndreasBriese/bbloom \
		BurntSushi:toml:v0.3.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Logicalis:asn1:c9c836c1a3cd:logicalis_asn1/vendor/github.com/Logicalis/asn1 \
		Shopify:sarama:v1.16.0:shopify_sarama/vendor/github.com/Shopify/sarama \
		boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		cenkalti:backoff:v4.0.0:cenkalti_backoff_v4/vendor/github.com/cenkalti/backoff/v4 \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgraph-io:badger:94594b20babf:dgraph_io_badger/vendor/github.com/dgraph-io/badger \
		dgryski:go-farm:2de33835d102:dgryski_go_farm/vendor/github.com/dgryski/go-farm \
		dutchcoders:gobus:ece5a7810d96:dutchcoders_gobus/vendor/github.com/dutchcoders/gobus \
		eapache:go-resiliency:v1.0.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:bb955e01b934:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		elastic:go-lumber:v0.1.0:elastic_go_lumber/vendor/github.com/elastic/go-lumber \
		elazarl:go-bindata-assetfs:38087fe4dafb:elazarl_go_bindata_assetfs/vendor/github.com/elazarl/go-bindata-assetfs \
		fatih:color:v1.6.0:fatih_color/vendor/github.com/fatih/color \
		fuyufjh:splunk-hec-go:v0.3.3:fuyufjh_splunk_hec_go/vendor/github.com/fuyufjh/splunk-hec-go \
		glycerine:rbuf:54320fe9f6f3:glycerine_rbuf/vendor/github.com/glycerine/rbuf \
		go-asn1-ber:asn1-ber:379148ca0225:go_asn1_ber_asn1_ber/vendor/github.com/go-asn1-ber/asn1-ber \
		golang:crypto:089bfa567519:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.8.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:553a64147049:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.6.0:golang_term/vendor/golang.org/x/term \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		google:gopacket:v1.1.14:google_gopacket/vendor/github.com/google/gopacket \
		gorilla:websocket:v1.2.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		honeytrap:honeytrap-web:02944754979e:honeytrap_honeytrap_web/vendor/github.com/honeytrap/honeytrap-web \
		honeytrap:protocol:219b95413db0:honeytrap_protocol/vendor/github.com/honeytrap/protocol \
		klauspost:compress:v1.9.8:klauspost_compress/vendor/github.com/klauspost/compress \
		lxc:go-lxc:2f350e4a2980:lxc_go_lxc/vendor/gopkg.in/lxc/go-lxc.v2 \
		mailru:easyjson:32fa128f234d:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-colorable:v0.0.9:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.3:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		miekg:dns:v1.0.4:miekg_dns/vendor/github.com/miekg/dns \
		mimoo:StrobeGo:43f0c284a7f9:mimoo_strobego/vendor/github.com/mimoo/StrobeGo \
		mimoo:disco:15dd4b8476c9:mimoo_disco/vendor/github.com/mimoo/disco \
		olivere:elastic:v5.0.65:olivere_elastic/vendor/gopkg.in/olivere/elastic.v5 \
		op:go-logging:b2cb9fa56473:op_go_logging/vendor/github.com/op/go-logging \
		oschwald:maxminddb-golang:v1.3.0:oschwald_maxminddb_golang/vendor/github.com/oschwald/maxminddb-golang \
		pierrec:lz4:2fcda4cb7018:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pierrec:xxHash:v0.1.1:pierrec_xxhash/vendor/github.com/pierrec/xxHash \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		pkg:profile:v1.2.1:pkg_profile/vendor/github.com/pkg/profile \
		rcrowley:go-metrics:8732c616f529:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		rs:xid:02dd45c33376:rs_xid/vendor/github.com/rs/xid \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		songgao:packets:549a10cd4091:songgao_packets/vendor/github.com/songgao/packets \
		songgao:water:75f112d19d5a:songgao_water/vendor/github.com/songgao/water \
		streadway:amqp:8e4aba63da9f:streadway_amqp/vendor/github.com/streadway/amqp \
		urfave:cli:v1.20.0:urfave_cli/vendor/gopkg.in/urfave/cli.v1 \
		yuin:gopher-lua:8bfc7677f583:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua

HONEYTRAP_USER?=	honeytrap
HONEYTRAP_GROUP?=	honeytrap
HONEYTRAP_DBDIR?=	/var/db/${PORTNAME}
HONEYTRAP_LOGDIR?=	/var/log/${PORTNAME}

USERS=		${HONEYTRAP_USER}
GROUPS=		${HONEYTRAP_GROUP}
USE_RC_SUBR=	honeytrap
PLIST_FILES=	"@sample(honeytrap,honeytrap,0600) ${ETCDIR}/honeytrap.toml.sample" \
		"@dir(honeytrap,honeytrap,0700) ${HONEYTRAP_LOGDIR}" \
		bin/honeytrap

SUB_LIST=	GROUP=${HONEYTRAP_GROUP} \
		HONEYTRAP_DBDIR=${HONEYTRAP_DBDIR} \
		USER=${HONEYTRAP_USER}

post-patch:
	${REINPLACE_CMD} 's#/etc#${ETCDIR}#' \
		${WRKSRC}/cmd/honeytrap/main.go
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin \
		${STAGEDIR}${HONEYTRAP_LOGDIR}
	${INSTALL_PROGRAM} ${WRKDIR}/bin/honeytrap ${STAGEDIR}${PREFIX}/bin/honeytrap
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rc.d ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/honeytrap.toml ${STAGEDIR}${ETCDIR}/honeytrap.toml.sample

.include <bsd.port.mk>
