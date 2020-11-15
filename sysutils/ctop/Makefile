# $FreeBSD$

PORTNAME=	ctop
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.5
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
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Microsoft:go-winio:3fe6c5262873:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Microsoft:hcsshim:v0.8.9:microsoft_hcsshim/vendor/github.com/Microsoft/hcsshim \
		Nvveen:Gotty:cd527374f1e5:Nvveen_Gotty/vendor/github.com/Nvveen/Gotty \
		bcicen:termui:4eb80249d3f5:bcicen_termui/vendor/github.com/gizak/termui \
		c9s:goprocinfo:b34328d6e0cd:c9s_goprocinfo/vendor/github.com/c9s/goprocinfo \
		checkpoint-restore:go-criu:v4.1.0:checkpoint_restore_go_criu_v4/vendor/github.com/checkpoint-restore/go-criu/v4 \
		cilium:ebpf:1c8d4c9ef775:cilium_ebpf/vendor/github.com/cilium/ebpf \
		containerd:console:v1.0.0:containerd_console/vendor/github.com/containerd/console \
		containerd:containerd:v1.3.4:containerd_containerd/vendor/github.com/containerd/containerd \
		containerd:continuity:d3ef23f19fbb:containerd_continuity/vendor/github.com/containerd/continuity \
		coreos:go-systemd:v22.1.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		cyphar:filepath-securejoin:v0.2.2:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		docker:distribution:v2.7.1:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		fsouza:go-dockerclient:v1.6.6:fsouza_go_dockerclient/vendor/github.com/fsouza/go-dockerclient \
		godbus:dbus:v5.0.3:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:net:8eef5233e2a1:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:3e129f6d46b1:golang_sys/vendor/golang.org/x/sys \
		google:go-genproto:24fa4b261c55:google_go_genproto/vendor/google.golang.org/genproto \
		grpc:grpc-go:v1.29.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		jgautheron:codename-generator:16d037c7cc3c:jgautheron_codename_generator/vendor/github.com/jgautheron/codename-generator \
		konsorten:go-windows-terminal-sequences:v1.0.3:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		mattn:go-runewidth:14207d285c6c:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-wordwrap:ad45545899c7:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		moby:moby:v17.12.0-ce:moby_moby/vendor/github.com/docker/docker \
		moby:sys:mount/v0.1.0:moby_sys_mount/vendor/github.com/moby/sys \
		moby:sys:mountinfo/v0.1.3:moby_sys_mountinfo \
		moby:term:129dac9f73f6:moby_term/vendor/github.com/moby/term \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		mrunalp:fileutils:abd8a0e76976:mrunalp_fileutils/vendor/github.com/mrunalp/fileutils \
		nsf:termbox-go:e2050e41c884:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		op:go-logging:b2cb9fa56473:op_go_logging/vendor/github.com/op/go-logging \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v1.0.0-rc92:opencontainers_runc/vendor/github.com/opencontainers/runc \
		opencontainers:runtime-spec:4d89ac9fbff6:opencontainers_runtime_spec/vendor/github.com/opencontainers/runtime-spec \
		opencontainers:selinux:v1.6.0:opencontainers_selinux/vendor/github.com/opencontainers/selinux \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		seccomp:libseccomp-golang:v0.9.1:seccomp_libseccomp_golang/vendor/github.com/seccomp/libseccomp-golang \
		sirupsen:logrus:v1.6.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		syndtr:gocapability:d98352740cb2:syndtr_gocapability/vendor/github.com/syndtr/gocapability \
		vishvananda:netlink:v1.1.0:vishvananda_netlink/vendor/github.com/vishvananda/netlink \
		vishvananda:netns:0a2b9b5464df:vishvananda_netns/vendor/github.com/vishvananda/netns \
		willf:bitset:d5bec3311243:willf_bitset/vendor/github.com/willf/bitset

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/sys/mountinfo
	@${RLN} ${WRKSRC_moby_sys_mountinfo}/mountinfo ${WRKSRC}/vendor/github.com/moby/sys/mountinfo

PLIST_FILES=	bin/ctop

.include <bsd.port.mk>
