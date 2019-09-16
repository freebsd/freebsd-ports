# $FreeBSD$

PORTNAME=	ctop
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.2
CATEGORIES=	sysutils

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Top-like interface for Docker container metrics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	bcicen
GH_TUPLE=	\
		BurntSushi:toml:v0.3.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Nvveen:Gotty:cd52737:nvveen_gotty/vendor/github.com/Nvveen/Gotty \
		Sirupsen:logrus:26709e2:sirupsen_logrus/vendor/github.com/Sirupsen/logrus \
		bcicen:termui:4eb8024:bcicen_termui/vendor/github.com/gizak/termui \
		c9s:goprocinfo:b34328d:c9s_goprocinfo/vendor/github.com/c9s/goprocinfo \
		coreos:go-systemd:b4a58d9:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		docker:go-connections:a2afab9:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.3.2:docker_go_units/vendor/github.com/docker/go-units \
		fsouza:go-dockerclient:318513e:fsouza_go_dockerclient/vendor/github.com/fsouza/go-dockerclient \
		godbus:dbus:c7fdd8b:godbus_dbus/vendor/github.com/godbus/dbus \
		golang:net:a6577fa:golang_net/vendor/golang.org/x/net \
		golang:protobuf:0a4f71a:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:99f16d8:golang_sys/vendor/golang.org/x/sys \
		hashicorp:go-cleanhttp:3573b8b:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		jgautheron:codename-generator:16d037c:jgautheron_codename_generator/vendor/github.com/jgautheron/codename-generator \
		mattn:go-runewidth:14207d2:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-wordwrap:ad45545:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		moby:moby:90d35ab:moby_moby/vendor/github.com/docker/docker \
		nsf:termbox-go:e2050e4:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		nu7hatch:gouuid:179d4d0:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		op:go-logging:b2cb9fa:op_go_logging/vendor/github.com/op/go-logging \
		opencontainers:runc:v0.1.1:opencontainers_runc/vendor/github.com/opencontainers/runc \
		seccomp:libseccomp-golang:1b506fc:seccomp_libseccomp_golang/vendor/github.com/seccomp/libseccomp-golang \
		syndtr:gocapability:2c00dae:syndtr_gocapability/vendor/github.com/syndtr/gocapability \
		vishvananda:netlink:1e2e08e:vishvananda_netlink/vendor/github.com/vishvananda/netlink

PLIST_FILES=	bin/ctop

.include <bsd.port.mk>
