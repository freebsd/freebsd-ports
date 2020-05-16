# $FreeBSD$

PORTNAME=	adguardhome
DISTVERSIONPREFIX=	v
DISTVERSION=	0.102.0
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
		AdguardTeam:dnsproxy:v0.28.1:adguardteam_dnsproxy/vendor/github.com/AdguardTeam/dnsproxy \
		AdguardTeam:golibs:v0.4.2:adguardteam_golibs/vendor/github.com/AdguardTeam/golibs \
		AdguardTeam:urlfilter:v0.10.0:adguardteam_urlfilter/vendor/github.com/AdguardTeam/urlfilter \
		NYTimes:gziphandler:v1.1.1:nytimes_gziphandler/vendor/github.com/NYTimes/gziphandler \
		aead:chacha20:8b13a72661da:aead_chacha20/vendor/github.com/aead/chacha20 \
		aead:poly1305:3fee0db0b635:aead_poly1305/vendor/github.com/aead/poly1305 \
		ameshkov:dnscrypt:v1.1.0:ameshkov_dnscrypt/vendor/github.com/ameshkov/dnscrypt \
		ameshkov:dnsstamps:v1.0.1:ameshkov_dnsstamps/vendor/github.com/ameshkov/dnsstamps \
		asaskevich:govalidator:475eaeb16496:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		beefsack:go-rate:efa7637bb9b6:beefsack_go_rate/vendor/github.com/beefsack/go-rate \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		etcd-io:bbolt:v1.3.4:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobuffalo:envy:v1.7.0:gobuffalo_envy/vendor/github.com/gobuffalo/envy \
		gobuffalo:packd:v0.3.0:gobuffalo_packd/vendor/github.com/gobuffalo/packd \
		gobuffalo:packr:v1.30.1:gobuffalo_packr/vendor/github.com/gobuffalo/packr \
		golang:crypto:baeed622b8d8:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:d3edc9973b7e:golang_net/vendor/golang.org/x/net \
		golang:sys:c3d80250170d:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		joho:godotenv:v1.3.0:joho_godotenv/vendor/github.com/joho/godotenv \
		joomcode:errorx:v1.0.1:joomcode_errorx/vendor/github.com/joomcode/errorx \
		kardianos:service:v1.0.0:kardianos_service/vendor/github.com/kardianos/service \
		krolaw:dhcp4:7cead472c414:krolaw_dhcp4/vendor/github.com/krolaw/dhcp4 \
		miekg:dns:v1.1.29:miekg_dns/vendor/github.com/miekg/dns \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rogpeppe:go-internal:v1.3.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		sparrc:go-ping:4e5b6552494c:sparrc_go_ping/vendor/github.com/sparrc/go-ping \
		stretchr:testify:v1.5.1:stretchr_testify/vendor/github.com/stretchr/testify

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
