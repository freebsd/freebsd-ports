# $FreeBSD$

PORTNAME=	ctop
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.3
CATEGORIES=	sysutils

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Top-like interface for Docker container metrics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	bcicen
GH_TUPLE=	\
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		BurntSushi:toml:v0.3.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Microsoft:go-winio:v0.4.12:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		bcicen:termui:4eb80249d3f5:bcicen_termui/vendor/github.com/gizak/termui \
		c9s:goprocinfo:b34328d6e0cd:c9s_goprocinfo/vendor/github.com/c9s/goprocinfo \
		checkpoint-restore:go-criu:bdb7599cd87b:checkpoint_restore_go_criu/vendor/github.com/checkpoint-restore/go-criu \
		containerd:console:0650fd9eeb50:containerd_console/vendor/github.com/containerd/console \
		containerd:continuity:004b46473808:containerd_continuity/vendor/github.com/containerd/continuity \
		coreos:go-systemd:b4a58d95188d:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		cyphar:filepath-securejoin:v0.2.2:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		moby:moby:33c3200e0d16:docker_docker/vendor/github.com/docker/docker \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		fsouza:go-dockerclient:v1.4.1:fsouza_go_dockerclient/vendor/github.com/fsouza/go-dockerclient \
		godbus:dbus:c7fdd8b5cd55:godbus_dbus/vendor/github.com/godbus/dbus \
		gogo:protobuf:v1.2.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:crypto:c2843e01d9a2:golang_crypto/vendor/golang.org/x/crypto \
		golang:protobuf:v1.3.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:10058d7d4faa:golang_sys/vendor/golang.org/x/sys \
		ijc:Gotty:a8b993ba6abd:ijc_gotty/vendor/github.com/ijc/Gotty \
		jgautheron:codename-generator:16d037c7cc3c:jgautheron_codename_generator/vendor/github.com/jgautheron/codename-generator \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		mattn:go-runewidth:14207d285c6c:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-wordwrap:ad45545899c7:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mrunalp:fileutils:7d4729fb3618:mrunalp_fileutils/vendor/github.com/mrunalp/fileutils \
		nsf:termbox-go:e2050e41c884:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		op:go-logging:b2cb9fa56473:op_go_logging/vendor/github.com/op/go-logging \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v1.0.0-rc8:opencontainers_runc/vendor/github.com/opencontainers/runc \
		opencontainers:runtime-spec:v1.0.1:opencontainers_runtime_spec/vendor/github.com/opencontainers/runtime-spec \
		opencontainers:selinux:v1.2.2:opencontainers_selinux/vendor/github.com/opencontainers/selinux \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		seccomp:libseccomp-golang:1b506fc7c24e:seccomp_libseccomp_golang/vendor/github.com/seccomp/libseccomp-golang \
		sirupsen:logrus:v1.3.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		syndtr:gocapability:d98352740cb2:syndtr_gocapability/vendor/github.com/syndtr/gocapability \
		vishvananda:netlink:1e2e08e8a2dc:vishvananda_netlink/vendor/github.com/vishvananda/netlink

PLIST_FILES=	bin/ctop

.include <bsd.port.mk>
