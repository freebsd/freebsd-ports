# $FreeBSD$

PORTNAME=	goreplay
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tool for capturing and replaying live HTTP traffic

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	buger
GH_TUPLE=	buger:${PORTNAME}:${DISTVERSIONPREFIX}${PORTVERSION}:DEFAULT \
		Shopify:sarama:v1.26.4:shopify_sarama/vendor/github.com/Shopify/sarama \
		araddon:gou:c797efecbb61:araddon_gou/vendor/github.com/araddon/gou \
		aws:aws-sdk-go:v1.32.7:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		bitly:go-hostpool:v0.1.0:bitly_go_hostpool/vendor/github.com/bitly/go-hostpool \
		bmizerany:assert:b7ed37b82869:bmizerany_assert/vendor/github.com/bmizerany/assert \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		eapache:go-resiliency:v1.2.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:627f9648deb9:golang_net/vendor/golang.org/x/net \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		google:gopacket:v1.1.17:google_gopacket/vendor/github.com/google/gopacket \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		jcmturner:aescts:v1.0.1:jcmturner_aescts/vendor/gopkg.in/jcmturner/aescts.v1 \
		jcmturner:dnsutils:v1.0.1:jcmturner_dnsutils/vendor/gopkg.in/jcmturner/dnsutils.v1 \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:gokrb5:v7.5.0:jcmturner_gokrb5/vendor/gopkg.in/jcmturner/gokrb5.v7 \
		jcmturner:rpc:v1.1.0:jcmturner_rpc/vendor/gopkg.in/jcmturner/rpc.v1 \
		jmespath:go-jmespath:v0.3.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		klauspost:compress:v1.10.10:klauspost_compress/vendor/github.com/klauspost/compress \
		mattbaird:elastigo:2fe47fd29e4b:mattbaird_elastigo/vendor/github.com/mattbaird/elastigo \
		pierrec:lz4:v2.5.2:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		rcrowley:go-metrics:10cdbea86bc0:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		smartystreets:goconvey:v1.6.4:smartystreets_goconvey/vendor/github.com/smartystreets/goconvey

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
