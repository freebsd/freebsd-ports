# $FreeBSD$

PORTNAME=	packer
PORTVERSION=	0.8.5
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tool for creating machine images

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	mitchellh:DEFAULT,cli,gofs,govnc,iochan,mapstructure \
		mitchellh:multistep,osext,panicwrap,prefixedio,reflectwalk \
		hashicorp:atlas,checkpoint,gomultierror,msgpack,version,yamux \
		google:apiclient,goquerystr aws:awssdkgo \
		golang:crypto,net,oauth2,tools go-fsnotify:fsnotify \
		GoogleCloudPlatform:gcloud digitalocean:godo vaughan0:goini \
		rackspace:gophercloud zoutaiqi:gosshold nu7hatch:gouuid \
		tent:hlink pierrec:lz4,xxhash klauspost:compress,cpuid,crc32,pgzip \
		satori:suuid ActiveState:tail go-tomb:tomb going:toolkit \
		masterzen:winrm,simplexml,xmlpath packer-community:winrmcp \
		dylanmei:iso8601,winrmtest
GH_PROJECT=	cli:cli go-fs:gofs go-vnc:govnc iochan:iochan \
		mapstructure:mapstructure multistep:multistep osext:osext \
		panicwrap:panicwrap prefixedio:prefixedio \
		reflectwalk:reflectwalk atlas-go:atlas go-checkpoint:checkpoint \
		go-multierror:gomultierror go-msgpack:msgpack \
		go-version:version yamux:yamux google-api-go-client:apiclient \
		go-querystring:goquerystr aws-sdk-go:awssdkgo crypto:crypto \
		net:net oauth2:oauth2 fsnotify:fsnotify gcloud-golang:gcloud \
		godo:godo go-ini:goini gophercloud:gophercloud \
		gosshold:gosshold gouuid:gouuid http-link-go:hlink lz4:lz4 \
		xxHash:xxhash pgzip:pgzip go.uuid:suuid tail:tail tomb:tomb \
		toolkit:toolkit winrm:winrm simplexml:simplexml xmlpath:xmlpath \
		winrmcp:winrmcp iso8601:iso8601 winrmtest:winrmtest \
		compress:compress cpuid:cpuid crc32:crc32 tools:tools
GH_TAGNAME=	8102d0e:cli a34c1b9:gofs 723ed98:govnc 87b45ff:iochan \
		281073e:mapstructure 162146f:multistep 0dd3f91:osext \
		45cbfd3:panicwrap 89d9b53:prefixedio eecf4c7:reflectwalk \
		d1d08e8:atlas 88326f6:checkpoint 56912fb:gomultierror \
		fa3f638:msgpack 999359b:version 4036a34:yamux e5bf1aa:apiclient \
		547ef5a:goquerystr 8aa49b7:awssdkgo 173ce04:crypto b026840:net \
		397fe76:oauth2 ea925a0:fsnotify e34a32f:gcloud 0d77b00:godo \
		a98ad7e:goini 1d8b6f1:gophercloud 967f522:gosshold \
		179d4d0:gouuid ac974c6:hlink 4bdd4b0:lz4 284d0fc:xxhash \
		eef48e2:pgzip 6b8e5b5:suuid 4b368d1:tail dd63297:tomb \
		5bff591:toolkit 27e0cc8:winrm 95ba304:simplexml 13f4951:xmlpath \
		743b1af:winrmcp 2075bf1:iso8601 3e9661c:winrmtest \
		058815a:compress 3b0816b:cpuid 55bf046:crc32 4f50f44:tools

STRIP=		# stripping can break go binaries

PLUGINS=	builder-amazon-chroot builder-amazon-ebs \
	builder-amazon-instance builder-digitalocean builder-docker \
	builder-file builder-googlecompute builder-null builder-openstack \
	builder-parallels-iso builder-parallels-pvm builder-qemu \
	builder-virtualbox-iso builder-virtualbox-ovf builder-vmware-iso \
	builder-vmware-vmx post-processor-atlas post-processor-compress \
	post-processor-artifice post-processor-docker-import \
	post-processor-docker-push post-processor-docker-save \
	post-processor-docker-tag post-processor-vagrant \
	post-processor-vagrant-cloud post-processor-vsphere \
	provisioner-ansible-local provisioner-chef-client provisioner-chef-solo \
	provisioner-file provisioner-powershell provisioner-puppet-masterless \
	provisioner-puppet-server provisioner-salt-masterless provisioner-shell \
	provisioner-shell-local provisioner-windows-restart \
	provisioner-windows-shell

post-extract:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in .gitignore .travis.yml CHANGELOG.md CONTRIBUTING.md LICENSE \
	Makefile README.md Vagrantfile appveyor.yml builder checkpoint.go \
	command commands.go common communicator config.go config_unix.go \
	config_windows.go contrib fix helper log.go main.go main_test.go packer \
	panic.go plugin post-processor provisioner scripts signal.go stdin.go \
	template test version.go website
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/mitchellh/${PORTNAME}
.endfor
	@${MKDIR} ${WRKSRC}/src/code.google.com/p
	@${MKDIR} ${WRKSRC}/src/github.com/ActiveState
	@${MKDIR} ${WRKSRC}/src/github.com/aws
	@${MKDIR} ${WRKSRC}/src/github.com/digitalocean
	@${MKDIR} ${WRKSRC}/src/github.com/dylanmei
	@${MKDIR} ${WRKSRC}/src/github.com/dylanmei
	@${MKDIR} ${WRKSRC}/src/github.com/going
	@${MKDIR} ${WRKSRC}/src/github.com/golang
	@${MKDIR} ${WRKSRC}/src/github.com/google
	@${MKDIR} ${WRKSRC}/src/github.com/hashicorp
	@${MKDIR} ${WRKSRC}/src/github.com/howeyc
	@${MKDIR} ${WRKSRC}/src/github.com/klauspost
	@${MKDIR} ${WRKSRC}/src/github.com/masterzen
	@${MKDIR} ${WRKSRC}/src/github.com/nu7hatch
	@${MKDIR} ${WRKSRC}/src/github.com/packer-community
	@${MKDIR} ${WRKSRC}/src/github.com/pierrec
	@${MKDIR} ${WRKSRC}/src/github.com/racker
	@${MKDIR} ${WRKSRC}/src/github.com/rackspace
	@${MKDIR} ${WRKSRC}/src/github.com/satori
	@${MKDIR} ${WRKSRC}/src/github.com/tent
	@${MKDIR} ${WRKSRC}/src/github.com/vaughan0
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/google.golang.org
	@${MKDIR} ${WRKSRC}/src/gopkg.in
	@${MV} ${WRKSRC_apiclient} ${WRKSRC}/src/google.golang.org/api
	@${MV} ${WRKSRC_atlas} ${WRKSRC}/src/github.com/hashicorp/atlas-go
	@${MV} ${WRKSRC_awssdkgo} ${WRKSRC}/src/github.com/aws/aws-sdk-go
	@${MV} ${WRKSRC_checkpoint} ${WRKSRC}/src/github.com/hashicorp/go-checkpoint
	@${MV} ${WRKSRC_cli} ${WRKSRC}/src/github.com/mitchellh/cli
	@${MV} ${WRKSRC_fsnotify} ${WRKSRC}/src/gopkg.in/fsnotify.v0
	@${MV} ${WRKSRC_gcloud} ${WRKSRC}/src/google.golang.org/cloud
	@${MV} ${WRKSRC_godo} ${WRKSRC}/src/github.com/digitalocean/godo
	@${MV} ${WRKSRC_gofs} ${WRKSRC}/src/github.com/mitchellh/go-fs
	@${MV} ${WRKSRC_goini} ${WRKSRC}/src/github.com/vaughan0/go-ini
	@${MV} ${WRKSRC_gomultierror} ${WRKSRC}/src/github.com/hashicorp/go-multierror
	@${MV} ${WRKSRC_gophercloud} ${WRKSRC}/src/github.com/rackspace/gophercloud
	@${MV} ${WRKSRC_goquerystr} ${WRKSRC}/src/github.com/google/go-querystring
	@${MV} ${WRKSRC_gosshold} ${WRKSRC}/src/code.google.com/p/gosshold
	@${MV} ${WRKSRC_gouuid} ${WRKSRC}/src/github.com/nu7hatch/gouuid
	@${MV} ${WRKSRC_govnc} ${WRKSRC}/src/github.com/mitchellh/go-vnc
	@${MV} ${WRKSRC_hlink} ${WRKSRC}/src/github.com/tent/http-link-go
	@${MV} ${WRKSRC_iochan} ${WRKSRC}/src/github.com/mitchellh/iochan
	@${MV} ${WRKSRC_iso8601} ${WRKSRC}/src/github.com/dylanmei/iso8601
	@${MV} ${WRKSRC_lz4} ${WRKSRC}/src/github.com/pierrec/lz4
	@${MV} ${WRKSRC_mapstructure} ${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKSRC_msgpack} ${WRKSRC}/src/github.com/hashicorp/go-msgpack
	@${MV} ${WRKSRC_multistep} ${WRKSRC}/src/github.com/mitchellh/multistep
	@${MV} ${WRKSRC_oauth2} ${WRKSRC}/src/golang.org/x/oauth2
	@${MV} ${WRKSRC_osext} ${WRKSRC}/src/github.com/mitchellh/osext
	@${MV} ${WRKSRC_panicwrap} ${WRKSRC}/src/github.com/mitchellh/panicwrap
	@${MV} ${WRKSRC_pgzip} ${WRKSRC}/src/github.com/klauspost/pgzip
	@${MV} ${WRKSRC_compress} ${WRKSRC}/src/github.com/klauspost/compress
	@${MV} ${WRKSRC_cpuid} ${WRKSRC}/src/github.com/klauspost/cpuid
	@${MV} ${WRKSRC_crc32} ${WRKSRC}/src/github.com/klauspost/crc32
	@${MV} ${WRKSRC_prefixedio} ${WRKSRC}/src/github.com/mitchellh/prefixedio
	@${MV} ${WRKSRC_reflectwalk} ${WRKSRC}/src/github.com/mitchellh/reflectwalk
	@${MV} ${WRKSRC_simplexml} ${WRKSRC}/src/github.com/masterzen/simplexml
	@${MV} ${WRKSRC_suuid} ${WRKSRC}/src/github.com/satori/go.uuid
	@${MV} ${WRKSRC_tail} ${WRKSRC}/src/github.com/ActiveState/tail
	@${MV} ${WRKSRC_tomb} ${WRKSRC}/src/gopkg.in/tomb.v1
	@${MV} ${WRKSRC_toolkit} ${WRKSRC}/src/github.com/going/toolkit
	@${MV} ${WRKSRC_version} ${WRKSRC}/src/github.com/hashicorp/go-version
	@${MV} ${WRKSRC_winrmcp} ${WRKSRC}/src/github.com/packer-community/winrmcp
	@${MV} ${WRKSRC_winrmtest} ${WRKSRC}/src/github.com/dylanmei/winrmtest
	@${MV} ${WRKSRC_winrm} ${WRKSRC}/src/github.com/masterzen/winrm
	@${MV} ${WRKSRC_xmlpath} ${WRKSRC}/src/github.com/masterzen/xmlpath
	@${MV} ${WRKSRC_xxhash} ${WRKSRC}/src/github.com/pierrec/xxHash
	@${MV} ${WRKSRC_yamux} ${WRKSRC}/src/github.com/hashicorp/yamux
	@${CP} -r ${WRKSRC_net} ${WRKSRC}/src/golang.org/x/net
	@${MV} ${WRKSRC_net} ${WRKSRC}/src/github.com/golang/net
	@${CP} -r ${WRKSRC_crypto} ${WRKSRC}/src/golang.org/x/crypto
	@${MV} ${WRKSRC_crypto} ${WRKSRC}/src/code.google.com/p/go.crypto
	@${FIND} ${WRKSRC}/src/code.google.com/p/go.crypto -type f -name '*.go' -exec \
		${REINPLACE_CMD} -e 's,golang.org/x/crypto/ssh,code.google.com/p/go.crypto/ssh,g' {} +

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}
.for plugin in ${PLUGINS}
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}-${plugin} github.com/mitchellh/packer/plugin/${plugin}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.for plugin in ${PLUGINS}
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME}-${plugin} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${plugin}
.endfor

.include <bsd.port.mk>
