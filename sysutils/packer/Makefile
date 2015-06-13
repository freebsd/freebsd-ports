# $FreeBSD$

PORTNAME=	packer
PORTVERSION=	0.7.5
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tool for creating machine images

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	mitchellh:DEFAULT,cli,iochan,mapstructure,osext,panicwrap,prefixedio,gofs,gophercloud,goamz,multistep,govnc \
		hashicorp:atlas,checkpoint,msgpack,version,yamux golang:crypto,protobuf,net,oauth2,appengine \
		vaughan0:goini going:toolkit racker:perigee \
		ActiveState:tail howeyc:fsnotify zoutaiqi:gosshold \
		google:apiclient GoogleCloudPlatform:gcloud go-tomb:tomb
GH_PROJECT=	cli:cli iochan:iochan mapstructure:mapstructure osext:osext \
		panicwrap:panicwrap prefixedio:prefixedio atlas-go:atlas \
		go-checkpoint:checkpoint go-msgpack:msgpack go-version:version \
		yamux:yamux crypto:crypto go-ini:goini protobuf:protobuf \
		toolkit:toolkit perigee:perigee tail:tail go-fs:gofs \
		gophercloud-fork-40444fb:gophercloud goamz:goamz \
		multistep:multistep go-vnc:govnc fsnotify:fsnotify net:net \
		oauth2:oauth2 gosshold:gosshold google-api-go-client:apiclient \
		appengine:appengine gcloud-golang:gcloud tomb:tomb
GH_TAGNAME=	e3c2e3d:cli b584a32:iochan 740c764:mapstructure 0dd3f91:osext \
		45cbfd3:panicwrap 89d9b53:prefixedio \
		0008374:atlas efefdc6:checkpoint 71c2886:msgpack \
		bb92ddd:version 9feabe6:yamux 1fbbd62:crypto a98ad7e:goini \
		abd3b41:protobuf 6185c18:toolkit d281986:perigee \
		068b729:tail 590e633:gofs 40444fb:gophercloud 52a0104:goamz \
		162146f:multistep 6fca135:govnc 6b1ef89:fsnotify \
		8aa6e20:net b3f9a68:oauth2 967f522:gosshold fa1ebc5:apiclient \
		c98f627:appengine eaf111a:gcloud dd63297:tomb

STRIP=		# stripping can break go binaries

PLUGINS=	builder-amazon-chroot builder-amazon-ebs builder-amazon-instance \
	builder-digitalocean builder-docker builder-googlecompute builder-null \
	builder-openstack builder-parallels-iso builder-parallels-pvm \
	builder-qemu builder-virtualbox-iso builder-virtualbox-ovf builder-vmware-iso \
	builder-vmware-vmx post-processor-atlas post-processor-compress \
	post-processor-docker-import post-processor-docker-push post-processor-docker-save \
	post-processor-docker-tag post-processor-vagrant post-processor-vagrant-cloud \
	post-processor-vsphere provisioner-ansible-local provisioner-chef-client \
	provisioner-chef-solo provisioner-file provisioner-puppet-masterless \
	provisioner-puppet-server provisioner-salt-masterless provisioner-shell

post-extract:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in .gitignore .travis.yml CHANGELOG.md CONTRIBUTING.md LICENSE \
	Makefile README.md Vagrantfile builder checkpoint.go command \
	commands.go common communicator config.go config_unix.go \
	config_windows.go fix log.go main.go main_test.go packer panic.go \
	plugin post-processor provisioner scripts signal.go stdin.go test \
	version.go website
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/mitchellh/${PORTNAME}
.endfor
	@${MKDIR} ${WRKSRC}/src/github.com/ActiveState
	@${MKDIR} ${WRKSRC}/src/github.com/hashicorp
	@${MKDIR} ${WRKSRC}/src/github.com/golang
	@${MKDIR} ${WRKSRC}/src/github.com/going
	@${MKDIR} ${WRKSRC}/src/github.com/howeyc
	@${MKDIR} ${WRKSRC}/src/github.com/racker
	@${MKDIR} ${WRKSRC}/src/github.com/vaughan0
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/gopkg.in
	@${MKDIR} ${WRKSRC}/src/code.google.com/p
	@${MKDIR} ${WRKSRC}/src/google.golang.org
	@${MV} ${WRKSRC_tail} ${WRKSRC}/src/github.com/ActiveState/tail
	@${MV} ${WRKSRC_cli} ${WRKSRC}/src/github.com/mitchellh/cli
	@${MV} ${WRKSRC_iochan} ${WRKSRC}/src/github.com/mitchellh/iochan
	@${MV} ${WRKSRC_mapstructure} ${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKSRC_osext} ${WRKSRC}/src/github.com/mitchellh/osext
	@${MV} ${WRKSRC_panicwrap} ${WRKSRC}/src/github.com/mitchellh/panicwrap
	@${MV} ${WRKSRC_prefixedio} ${WRKSRC}/src/github.com/mitchellh/prefixedio
	@${MV} ${WRKSRC_gofs} ${WRKSRC}/src/github.com/mitchellh/go-fs
	@${MV} ${WRKSRC_gophercloud} ${WRKSRC}/src/github.com/mitchellh/gophercloud-fork-40444fb
	@${MV} ${WRKSRC_goamz} ${WRKSRC}/src/github.com/mitchellh/goamz
	@${MV} ${WRKSRC_multistep} ${WRKSRC}/src/github.com/mitchellh/multistep
	@${MV} ${WRKSRC_govnc} ${WRKSRC}/src/github.com/mitchellh/go-vnc
	@${MV} ${WRKSRC_atlas} ${WRKSRC}/src/github.com/hashicorp/atlas-go
	@${MV} ${WRKSRC_checkpoint} ${WRKSRC}/src/github.com/hashicorp/go-checkpoint
	@${MV} ${WRKSRC_msgpack} ${WRKSRC}/src/github.com/hashicorp/go-msgpack
	@${MV} ${WRKSRC_version} ${WRKSRC}/src/github.com/hashicorp/go-version
	@${MV} ${WRKSRC_yamux} ${WRKSRC}/src/github.com/hashicorp/yamux
	@${MV} ${WRKSRC_protobuf} ${WRKSRC}/src/github.com/golang/protobuf
	@${MV} ${WRKSRC_goini} ${WRKSRC}/src/github.com/vaughan0/go-ini
	@${MV} ${WRKSRC_fsnotify} ${WRKSRC}/src/github.com/howeyc/fsnotify
	@${CP} -r ${WRKSRC_net} ${WRKSRC}/src/golang.org/x/net
	@${MV} ${WRKSRC_net} ${WRKSRC}/src/github.com/golang/net
	@${CP} -r ${WRKSRC_crypto} ${WRKSRC}/src/golang.org/x/crypto
	@${MV} ${WRKSRC_oauth2} ${WRKSRC}/src/golang.org/x/oauth2
	@${MV} ${WRKSRC_gosshold} ${WRKSRC}/src/code.google.com/p/gosshold
	@${MV} ${WRKSRC_crypto} ${WRKSRC}/src/code.google.com/p/go.crypto
	@${MV} ${WRKSRC_apiclient} ${WRKSRC}/src/code.google.com/p/google-api-go-client
	@${MV} ${WRKSRC_appengine} ${WRKSRC}/src/google.golang.org/appengine
	@${MV} ${WRKSRC_gcloud} ${WRKSRC}/src/google.golang.org/cloud
	@${MV} ${WRKSRC_tomb} ${WRKSRC}/src/gopkg.in/tomb.v1
	@${MV} ${WRKSRC_perigee} ${WRKSRC}/src/github.com/racker/perigee
	@${MV} ${WRKSRC_toolkit} ${WRKSRC}/src/github.com/going/toolkit
	@${FIND} ${WRKSRC}/src/code.google.com/p/go.crypto -type f -name '*.go' -exec \
		${REINPLACE_CMD} -e 's,golang.org/x/crypto/ssh,code.google.com/p/go.crypto/ssh,g' {} +

do-build:
	cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}
.for plugin in ${PLUGINS}
	cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}-${plugin} github.com/mitchellh/packer/plugin/${plugin}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.for plugin in ${PLUGINS}
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME}-${plugin} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${plugin}
.endfor

.include <bsd.port.mk>
