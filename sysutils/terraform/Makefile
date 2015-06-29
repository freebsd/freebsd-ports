# $FreeBSD$

PORTNAME=	terraform
PORTVERSION=	0.5.3
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
PKGNAMEPREFIX=	hashicorp-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Provides a common configuration to launch infrastructure

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp:DEFAULT,atlasgo,consul,errwrap,gocheckpoint,gomultierror,goversion,hcl,yamux \
		mitchellh:cli,colorstring,copystructure,gohomedir,mapstructure,osext,panicwrap,prefixedio,reflectwalk,golinereader,packer \
		awslabs:awssdkgo vaughan0:goini golang:crypto,oauth2,net \
		pearkes:cloudflare,digitalocean,dnsimple,mailgun xanzy:cloudstack \
		soniah:dnsmadeeasy imdario:mergo fsouza:godocker google:apiclient GoogleCloudPlatform:gcloud \
		cyberdelia:heroku pborman:uuid rackspace:gophercloud dylanmei:winrmtest,iso8601 masterzen:winrm,simplexml,xmlpath \
		packer-community:winrmcp nu7hatch:gouuid satori:suuid armon:circbuf
GH_PROJECT=	atlas-go:atlasgo consul:consul errwrap:errwrap \
		go-checkpoint:gocheckpoint go-multierror:gomultierror go-version:goversion \
		hcl:hcl yamux:yamux cli:cli colorstring:colorstring copystructure:copystructure \
		go-homedir:gohomedir mapstructure:mapstructure osext:osext panicwrap:panicwrap \
		prefixedio:prefixedio reflectwalk:reflectwalk go-ini:goini aws-sdk-go:awssdkgo \
		crypto:crypto cloudflare:cloudflare go-cloudstack:cloudstack digitalocean:digitalocean \
		dnsmadeeasy:dnsmadeeasy mergo:mergo dnsimple:dnsimple go-dockerclient:godocker oauth2:oauth2 \
		net:net google-api-go-client:apiclient gcloud-golang:gcloud heroku-go:heroku \
		uuid:uuid mailgun:mailgun gophercloud:gophercloud winrmtest:winrmtest \
		winrm:winrm winrmcp:winrmcp go-linereader:golinereader iso8601:iso8601 \
		simplexml:simplexml packer:packer gouuid:gouuid go.uuid:suuid xmlpath:xmlpath circbuf:circbuf
GH_TAGNAME=	6a87d5f:atlasgo 9417fd3:consul 7554cd9:errwrap 88326f6:gocheckpoint fcdddc3:gomultierror \
		999359b:goversion 513e04c:hcl b2e5585:yamux 6cc8bc5:cli 61164e4:colorstring 6fc6626:copystructure \
		1f6da4a:gohomedir 442e588:mapstructure 0dd3f91:osext 45cbfd3:panicwrap 89d9b53:prefixedio 242be0c:reflectwalk \
		43d7c58:awssdkgo a98ad7e:goini c10c31b:crypto 19e280b:cloudflare f73f6ff:cloudstack e966f00:digitalocean \
		5578a8c:dnsmadeeasy 2fcac99:mergo 1e0c2b0:dnsimple f95d189:godocker b5adcc2:oauth2 589db58:net \
		d56f328:apiclient faa320c:gcloud 594d483:heroku ca53cad:uuid 5b02e7e:mailgun 9ad4137:gophercloud \
		3e9661c:winrmtest 1323390:winrm 650a91d:winrmcp 07bab5f:golinereader 2075bf1:iso8601 \
		95ba304:simplexml 350a5f8:packer 179d4d0:gouuid 7c7f202:suuid 13f4951:xmlpath f092b4f:circbuf

STRIP=		# stripping can break go binaries

PLUGINS=	provider-atlas provider-aws provider-cloudflare provider-cloudstack \
		provider-consul provider-digitalocean provider-dme provider-dnsimple \
		provider-docker provider-google provider-heroku provider-mailgun \
		provider-null provider-openstack provider-template provider-terraform \
		provisioner-chef provisioner-file provisioner-local-exec \
		provisioner-remote-exec

post-extract:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in .gitignore .travis.yml CHANGELOG.md CONTRIBUTING.md LICENSE \
	Makefile README.md RELEASING.md Vagrantfile builtin checkpoint.go \
	command commands.go communicator config config.go config_test.go \
	config_unix.go config_windows.go contrib dag depgraph deps digraph dot \
	examples flatmap helper log.go main.go make.bat panic.go plugin rpc \
	scripts state terraform test-fixtures version.go website
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/hashicorp/${PORTNAME}
.endfor
	@${MKDIR} ${WRKSRC}/src/github.com/mitchellh
	@${MKDIR} ${WRKSRC}/src/github.com/awslabs
	@${MKDIR} ${WRKSRC}/src/github.com/vaughan0
	@${MKDIR} ${WRKSRC}/src/github.com/pearkes
	@${MKDIR} ${WRKSRC}/src/github.com/xanzy
	@${MKDIR} ${WRKSRC}/src/github.com/soniah
	@${MKDIR} ${WRKSRC}/src/github.com/imdario
	@${MKDIR} ${WRKSRC}/src/github.com/fsouza
	@${MKDIR} ${WRKSRC}/src/github.com/golang
	@${MKDIR} ${WRKSRC}/src/github.com/cyberdelia
	@${MKDIR} ${WRKSRC}/src/github.com/rackspace
	@${MKDIR} ${WRKSRC}/src/github.com/dylanmei
	@${MKDIR} ${WRKSRC}/src/github.com/masterzen
	@${MKDIR} ${WRKSRC}/src/github.com/packer-community
	@${MKDIR} ${WRKSRC}/src/github.com/nu7hatch
	@${MKDIR} ${WRKSRC}/src/github.com/satori
	@${MKDIR} ${WRKSRC}/src/github.com/armon
	@${MKDIR} ${WRKSRC}/src/google.golang.org
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/code.google.com/p/go-uuid
	@${MV} ${WRKSRC_atlasgo} ${WRKSRC}/src/github.com/hashicorp/atlas-go
	@${MV} ${WRKSRC_osext} ${WRKSRC}/src/github.com/mitchellh/osext
	@${MV} ${WRKSRC_panicwrap} ${WRKSRC}/src/github.com/mitchellh/panicwrap
	@${MV} ${WRKSRC_prefixedio} ${WRKSRC}/src/github.com/mitchellh/prefixedio
	@${MV} ${WRKSRC_reflectwalk} ${WRKSRC}/src/github.com/mitchellh/reflectwalk
	@${MV} ${WRKSRC_mapstructure} ${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKSRC_gohomedir} ${WRKSRC}/src/github.com/mitchellh/go-homedir
	@${MV} ${WRKSRC_copystructure} ${WRKSRC}/src/github.com/mitchellh/copystructure
	@${MV} ${WRKSRC_colorstring} ${WRKSRC}/src/github.com/mitchellh/colorstring
	@${MV} ${WRKSRC_cli} ${WRKSRC}/src/github.com/mitchellh/cli
	@${MV} ${WRKSRC_hcl} ${WRKSRC}/src/github.com/hashicorp/hcl
	@${MV} ${WRKSRC_goversion} ${WRKSRC}/src/github.com/hashicorp/go-version
	@${MV} ${WRKSRC_gomultierror} ${WRKSRC}/src/github.com/hashicorp/go-multierror
	@${MV} ${WRKSRC_gocheckpoint} ${WRKSRC}/src/github.com/hashicorp/go-checkpoint
	@${MV} ${WRKSRC_errwrap} ${WRKSRC}/src/github.com/hashicorp/errwrap
	@${MV} ${WRKSRC_consul} ${WRKSRC}/src/github.com/hashicorp/consul
	@${MV} ${WRKSRC_yamux} ${WRKSRC}/src/github.com/hashicorp/yamux
	@${MV} ${WRKSRC_awssdkgo} ${WRKSRC}/src/github.com/awslabs/aws-sdk-go
	@${MV} ${WRKSRC_goini} ${WRKSRC}/src/github.com/vaughan0/go-ini
	@${MV} ${WRKSRC_crypto} ${WRKSRC}/src/golang.org/x/crypto
	@${MV} ${WRKSRC_cloudflare} ${WRKSRC}/src/github.com/pearkes/cloudflare
	@${MV} ${WRKSRC_cloudstack} ${WRKSRC}/src/github.com/xanzy/go-cloudstack
	@${MV} ${WRKSRC_digitalocean} ${WRKSRC}/src/github.com/pearkes/digitalocean
	@${MV} ${WRKSRC_dnsmadeeasy} ${WRKSRC}/src/github.com/soniah/dnsmadeeasy
	@${MV} ${WRKSRC_mergo} ${WRKSRC}/src/github.com/imdario/mergo
	@${MV} ${WRKSRC_dnsimple} ${WRKSRC}/src/github.com/pearkes/dnsimple
	@${MV} ${WRKSRC_godocker} ${WRKSRC}/src/github.com/fsouza/go-dockerclient
	@${MV} ${WRKSRC_oauth2} ${WRKSRC}/src/golang.org/x/oauth2
	@${CP} -r ${WRKSRC_net} ${WRKSRC}/src/golang.org/x/net
	@${MV} ${WRKSRC_net} ${WRKSRC}/src/github.com/golang/net
	@${MV} ${WRKSRC_apiclient} ${WRKSRC}/src/google.golang.org/api
	@${MV} ${WRKSRC_gcloud} ${WRKSRC}/src/google.golang.org/cloud
	@${MV} ${WRKSRC_heroku} ${WRKSRC}/src/github.com/cyberdelia/heroku-go
	@${MV} ${WRKSRC_uuid} ${WRKSRC}/src/code.google.com/p/go-uuid/uuid
	@${MV} ${WRKSRC_mailgun} ${WRKSRC}/src/github.com/pearkes/mailgun
	@${MV} ${WRKSRC_gophercloud} ${WRKSRC}/src/github.com/rackspace/gophercloud
	@${MV} ${WRKSRC_winrmtest} ${WRKSRC}/src/github.com/dylanmei/winrmtest
	@${MV} ${WRKSRC_winrm} ${WRKSRC}/src/github.com/masterzen/winrm
	@${MV} ${WRKSRC_winrmcp} ${WRKSRC}/src/github.com/packer-community/winrmcp
	@${MV} ${WRKSRC_golinereader} ${WRKSRC}/src/github.com/mitchellh/go-linereader
	@${MV} ${WRKSRC_iso8601} ${WRKSRC}/src/github.com/dylanmei/iso8601
	@${MV} ${WRKSRC_simplexml} ${WRKSRC}/src/github.com/masterzen/simplexml
	@${MV} ${WRKSRC_packer} ${WRKSRC}/src/github.com/mitchellh/packer
	@${MV} ${WRKSRC_gouuid} ${WRKSRC}/src/github.com/nu7hatch/gouuid
	@${MV} ${WRKSRC_suuid} ${WRKSRC}/src/github.com/satori/go.uuid
	@${MV} ${WRKSRC_xmlpath} ${WRKSRC}/src/github.com/masterzen/xmlpath
	@${MV} ${WRKSRC_circbuf} ${WRKSRC}/src/github.com/armon/circbuf

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}
.for plugin in ${PLUGINS}
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}-${plugin} github.com/hashicorp/terraform/builtin/bins/${plugin}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.for plugin in ${PLUGINS}
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME}-${plugin} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${plugin}
.endfor

.include <bsd.port.mk>
