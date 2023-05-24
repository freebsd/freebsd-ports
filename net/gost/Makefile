PORTNAME=	gost
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.5
CATEGORIES=	net

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Simple security tunnel written in Golang
WWW=		https://v2.gost.run/en

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.19,modules

USE_GITHUB=	yes
GH_ACCOUNT=	ginuerzh

GH_TUPLE=	FiloSottile:edwards25519:390f27c3be20:filosottile_edwards25519/vendor/filippo.io/edwards25519 \
		LiamHaworth:go-tproxy:ef7efd7f24ed:liamhaworth_go_tproxy/vendor/github.com/LiamHaworth/go-tproxy \
		aead:chacha20:8b13a72661da:aead_chacha20/vendor/github.com/aead/chacha20 \
		asaskevich:govalidator:f21760c49a8d:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		coreos:go-iptables:v0.6.0:coreos_go_iptables/vendor/github.com/coreos/go-iptables \
		dchest:siphash:v1.2.2:dchest_siphash/vendor/github.com/dchest/siphash \
		fsnotify:fsnotify:v1.5.4:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-gost:gosocks4:v0.0.1:go_gost_gosocks4/vendor/github.com/go-gost/gosocks4 \
		go-gost:gosocks5:v0.3.0:go_gost_gosocks5/vendor/github.com/go-gost/gosocks5 \
		go-gost:relay:8ef7fd81ffd7:go_gost_relay/vendor/github.com/go-gost/relay \
		go-gost:tls-dissector:aac992c27451:go_gost_tls_dissector/vendor/github.com/go-gost/tls-dissector \
		go-log:log:v0.2.0:go_log_log/vendor/github.com/go-log/log \
		go-task:slim-sprig:348f09dbbbc0:go_task_slim_sprig/vendor/github.com/go-task/slim-sprig \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		golang:crypto:bc19a97f63c8:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:86c51ed26bb4:golang_mod/vendor/golang.org/x/mod \
		golang:net:3211cb980234:golang_net/vendor/golang.org/x/net \
		golang:sys:5a390386f1f2:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.12:golang_tools/vendor/golang.org/x/tools \
		google:gopacket:v1.1.19:google_gopacket/vendor/github.com/google/gopacket \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		klauspost:compress:v1.13.6:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v2.0.9:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		klauspost:reedsolomon:v1.9.15:klauspost_reedsolomon/vendor/github.com/klauspost/reedsolomon \
		lucas-clemente:quic-go:v0.28.1:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		marten-seemann:qtls-go1-16:v0.1.5:marten_seemann_qtls_go1_16/vendor/github.com/marten-seemann/qtls-go1-16 \
		marten-seemann:qtls-go1-17:v0.1.2:marten_seemann_qtls_go1_17/vendor/github.com/marten-seemann/qtls-go1-17 \
		marten-seemann:qtls-go1-18:v0.1.2:marten_seemann_qtls_go1_18/vendor/github.com/marten-seemann/qtls-go1-18 \
		marten-seemann:qtls-go1-19:v0.1.0:marten_seemann_qtls_go1_19/vendor/github.com/marten-seemann/qtls-go1-19 \
		miekg:dns:v1.1.47:miekg_dns/vendor/github.com/miekg/dns \
		nxadm:tail:v1.4.8:nxadm_tail/vendor/github.com/nxadm/tail \
		onsi:ginkgo:v1.16.5:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		riobard:go-bloom:cdc8013cb5b3:riobard_go_bloom/vendor/github.com/riobard/go-bloom \
		ryanuber:go-glob:v1.0.0:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		shadowsocks:go-shadowsocks2:v0.1.5:shadowsocks_go_shadowsocks2/vendor/github.com/shadowsocks/go-shadowsocks2 \
		shadowsocks:shadowsocks-go:3e585ff90601:shadowsocks_shadowsocks_go/vendor/github.com/shadowsocks/shadowsocks-go \
		songgao:water:2b4b6d7c09d8:songgao_water/vendor/github.com/songgao/water \
		templexxx:cpu:98168dcec14a:templexxx_cpu/vendor/github.com/templexxx/cpu \
		templexxx:xorsimd:v0.4.1:templexxx_xorsimd/vendor/github.com/templexxx/xorsimd \
		tjfoc:gmsm:v1.4.1:tjfoc_gmsm/vendor/github.com/tjfoc/gmsm \
		xtaci:kcp-go:v5.6.1:xtaci_kcp_go_v5/vendor/github.com/xtaci/kcp-go/v5 \
		xtaci:lossyconn:adba10fffc37:xtaci_lossyconn/vendor/github.com/xtaci/lossyconn \
		xtaci:smux:v1.5.16:xtaci_smux/vendor/github.com/xtaci/smux \
		xtaci:tcpraw:v1.2.25:xtaci_tcpraw/vendor/github.com/xtaci/tcpraw

USE_GITLAB=	nodefault
GL_TUPLE=	yawning:edwards25519-extra:2f91fcc9fbdb888f3c795849b6777940135559b7:yawning_edwards25519_extra/vendor/gitlab.com/yawning/edwards25519-extra.git \
		yawning:obfs4:77af0cba934d73c4baeb709560bcfc9a9fbc661c:yawning_obfs4/vendor/gitlab.com/yawning/obfs4.git \
		https://gitlab.torproject.org/tpo/anti-censorship:pluggable-transports:goptlib:13b7b3552e1eef32e4d8a2a7813f22488f91dc09:goptlib/vendor/git.torproject.org/pluggable-transports/goptlib.git

GO_PKGNAME=	github.com/ginuerzh/gost
GO_TARGET=	./cmd/${PORTNAME}

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README_en.md ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/.config && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.post.mk>
