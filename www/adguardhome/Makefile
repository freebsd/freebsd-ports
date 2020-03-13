# $FreeBSD$

PORTNAME=	adguardhome
DISTVERSIONPREFIX=	v
DISTVERSION=	0.101.0
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
		AdguardTeam:dnsproxy:v0.23.7:adguardteam_dnsproxy/vendor/github.com/AdguardTeam/dnsproxy \
		AdguardTeam:golibs:v0.3.0:adguardteam_golibs/vendor/github.com/AdguardTeam/golibs \
		AdguardTeam:urlfilter:v0.9.1:adguardteam_urlfilter/vendor/github.com/AdguardTeam/urlfilter \
		NYTimes:gziphandler:v1.1.1:nytimes_gziphandler/vendor/github.com/NYTimes/gziphandler \
		aead:chacha20:8b13a72661da:aead_chacha20/vendor/github.com/aead/chacha20 \
		aead:poly1305:3fee0db0b635:aead_poly1305/vendor/github.com/aead/poly1305 \
		ameshkov:dnscrypt:v1.0.7:ameshkov_dnscrypt/vendor/github.com/ameshkov/dnscrypt \
		ameshkov:dnsstamps:v1.0.1:ameshkov_dnsstamps/vendor/github.com/ameshkov/dnsstamps \
		asaskevich:govalidator:f61b66f89f4a:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		beefsack:go-rate:efa7637bb9b6:beefsack_go_rate/vendor/github.com/beefsack/go-rate \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		etcd-io:bbolt:v1.3.3:etcd_io_bbolt/vendor/github.com/etcd-io/bbolt \
		go-yaml:yaml:v2.2.3:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobuffalo:envy:v1.6.7:gobuffalo_envy/vendor/github.com/gobuffalo/envy \
		gobuffalo:packd:c82734870264:gobuffalo_packd/vendor/github.com/gobuffalo/packd \
		gobuffalo:packr:v1.19.0:gobuffalo_packr/vendor/github.com/gobuffalo/packr \
		golang:crypto:53104e6ec876:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:c0dbc17a3553:golang_net/vendor/golang.org/x/net \
		golang:sys:04cbcbbfeed8:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		joho:godotenv:v1.3.0:joho_godotenv/vendor/github.com/joho/godotenv \
		joomcode:errorx:v1.0.0:joomcode_errorx/vendor/github.com/joomcode/errorx \
		kardianos:osext:ae77be60afb1:kardianos_osext/vendor/github.com/kardianos/osext \
		kardianos:service:4c239ee84e7b:kardianos_service/vendor/github.com/kardianos/service \
		krolaw:dhcp4:7cead472c414:krolaw_dhcp4/vendor/github.com/krolaw/dhcp4 \
		markbates:oncer:05fccaae8fc4:markbates_oncer/vendor/github.com/markbates/oncer \
		miekg:dns:v1.1.26:miekg_dns/vendor/github.com/miekg/dns \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		sparrc:go-ping:ef3ab45e41b0:sparrc_go_ping/vendor/github.com/sparrc/go-ping \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
