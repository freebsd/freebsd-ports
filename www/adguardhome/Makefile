# $FreeBSD$

PORTNAME=	adguardhome
DISTVERSIONPREFIX=	v
DISTVERSION=	0.104.1
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Network-wide ads & trackers blocking DNS server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	AdguardTeam
GH_PROJECT=	AdGuardHome
GH_TUPLE=	\
		AdguardTeam:dnsproxy:v0.33.2:adguardteam_dnsproxy/vendor/github.com/AdguardTeam/dnsproxy \
		AdguardTeam:golibs:v0.4.2:adguardteam_golibs/vendor/github.com/AdguardTeam/golibs \
		AdguardTeam:urlfilter:v0.12.3:adguardteam_urlfilter/vendor/github.com/AdguardTeam/urlfilter \
		NYTimes:gziphandler:v1.1.1:nytimes_gziphandler/vendor/github.com/NYTimes/gziphandler \
		aead:chacha20:8b13a72661da:aead_chacha20/vendor/github.com/aead/chacha20 \
		aead:poly1305:3fee0db0b635:aead_poly1305/vendor/github.com/aead/poly1305 \
		ameshkov:dnscrypt:v2.0.0:ameshkov_dnscrypt_v2/vendor/github.com/ameshkov/dnscrypt/v2 \
		ameshkov:dnsstamps:v1.0.3:ameshkov_dnsstamps/vendor/github.com/ameshkov/dnsstamps \
		beefsack:go-rate:6cde80facd47:beefsack_go_rate/vendor/github.com/beefsack/go-rate \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		etcd-io:bbolt:v1.3.4:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-yaml:yaml:eeeca48fe776:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobuffalo:envy:v1.7.0:gobuffalo_envy/vendor/github.com/gobuffalo/envy \
		gobuffalo:logger:v1.0.0:gobuffalo_logger/vendor/github.com/gobuffalo/logger \
		gobuffalo:packd:v0.3.0:gobuffalo_packd/vendor/github.com/gobuffalo/packd \
		gobuffalo:packr:v1.30.1:gobuffalo_packr \
		gobuffalo:packr:v2.5.1:gobuffalo_packr_v2/vendor/github.com/gobuffalo/packr \
		golang:crypto:9e8e0b390897:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:69a78807bb2b:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:67f06af15bc9:golang_sync/vendor/golang.org/x/sync \
		golang:sys:215b40eba54c:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		hugelgupf:socketpair:05d35a94e714:hugelgupf_socketpair/vendor/github.com/hugelgupf/socketpair \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		insomniacslk:dhcp:d74cd86ad5b8:insomniacslk_dhcp/vendor/github.com/insomniacslk/dhcp \
		joho:godotenv:v1.3.0:joho_godotenv/vendor/github.com/joho/godotenv \
		joomcode:errorx:v1.0.3:joomcode_errorx/vendor/github.com/joomcode/errorx \
		kardianos:service:v1.1.0:kardianos_service/vendor/github.com/kardianos/service \
		karrick:godirwalk:v1.10.12:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		konsorten:go-windows-terminal-sequences:v1.0.3:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		lucas-clemente:quic-go:v0.18.1:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		marten-seemann:qtls-go1-15:v0.1.1:marten_seemann_qtls_go1_15/vendor/github.com/marten-seemann/qtls-go1-15 \
		marten-seemann:qtls:v0.10.0:marten_seemann_qtls/vendor/github.com/marten-seemann/qtls \
		mdlayher:ethernet:0394541c37b7:mdlayher_ethernet/vendor/github.com/mdlayher/ethernet \
		mdlayher:raw:50f2db8cc065:mdlayher_raw/vendor/github.com/mdlayher/raw \
		miekg:dns:v1.1.35:miekg_dns/vendor/github.com/miekg/dns \
		natefinch:lumberjack:v2.0.0:natefinch_lumberjack/vendor/gopkg.in/natefinch/lumberjack.v2 \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rogpeppe:go-internal:v1.5.2:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		sirupsen:logrus:v1.6.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		go-ping:ping:3977ed72668a0ca7a7894d39075921a6526ee58b:sparrc_go_ping/vendor/github.com/sparrc/go-ping \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		u-root:u-root:v6.0.0:u_root_u_root/vendor/github.com/u-root/u-root

USE_GITLAB=	nodefault
GL_TUPLE=	https://gitlab.howett.net:go:plist:3b63eb3a43b59c776909681ed1fcb412b47d3c9a:go_plist/vendor/howett.net/plist

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
