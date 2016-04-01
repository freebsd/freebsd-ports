# $FreeBSD$

PORTNAME=	terraform
PORTVERSION=	0.6.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
PKGNAMEPREFIX=	hashicorp-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Provides a common configuration to launch infrastructure

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp:DEFAULT,atlasgo,consul,errwrap,gocheckpoint \
		hashicorp:gomultierror,goversion,hcl,yamux \
		mitchellh:cli,colorstring,copystructure,gohomedir \
		mitchellh:mapstructure,osext,panicwrap,prefixedio \
		mitchellh:reflectwalk,golinereader,packer \
		google:apiclient Azure:asfg,gpkcs aws:awssdkgo armon:circbuf \
		pearkes:cloudflare,digitalocean,dnsimple,mailgun \
		xanzy:cloudstack golang:crypto,oauth2,net soniah:dnsmadeeasy \
		GoogleCloudPlatform:gcloud fsouza:godocker vaughan0:goini \
		rackspace:gophercloud nu7hatch:gouuid cyberdelia:heroku \
		imdario:mergo satori:suuid pborman:uuid \
		masterzen:winrm,simplexml,xmlpath packer-community:winrmcp \
		dylanmei:winrmtest,iso8601
GH_PROJECT=	atlas-go:atlasgo consul:consul errwrap:errwrap \
		go-checkpoint:gocheckpoint go-multierror:gomultierror \
		go-version:goversion hcl:hcl yamux:yamux cli:cli \
		colorstring:colorstring copystructure:copystructure \
		go-homedir:gohomedir mapstructure:mapstructure osext:osext \
		panicwrap:panicwrap prefixedio:prefixedio \
		reflectwalk:reflectwalk go-linereader:golinereader \
		packer:packer google-api-go-client:apiclient \
		azure-sdk-for-go:asfg go-pkcs12:gpkcs aws-sdk-go:awssdkgo \
		circbuf:circbuf cloudflare:cloudflare digitalocean:digitalocean \
		dnsimple:dnsimple mailgun:mailgun go-cloudstack:cloudstack \
		crypto:crypto oauth2:oauth2 net:net dnsmadeeasy:dnsmadeeasy \
		gcloud-golang:gcloud go-dockerclient:godocker go-ini:goini \
		gophercloud:gophercloud gouuid:gouuid heroku-go:heroku \
		mergo:mergo go.uuid:suuid uuid:uuid winrm:winrm \
		simplexml:simplexml xmlpath:xmlpath winrmcp:winrmcp \
		winrmtest:winrmtest iso8601:iso8601
GH_TAGNAME=	d1d08e8:atlasgo 00e35cd:consul 7554cd9:errwrap \
		88326f6:gocheckpoint 56912fb:gomultierror 999359b:goversion \
		5486421:hcl 8e00b30:yamux 8102d0e:cli 61164e4:colorstring \
		6fc6626:copystructure 1f6da4a:gohomedir 281073e:mapstructure \
		0dd3f91:osext 45cbfd3:panicwrap 89d9b53:prefixedio \
		eecf4c7:reflectwalk 07bab5f:golinereader 60bbe85:packer \
		0a735f7:apiclient 99b5c36:asfg a635c06:gpkcs ccb4ffd:awssdkgo \
		f092b4f:circbuf 19e280b:cloudflare e966f00:digitalocean \
		2a807d1:dnsimple 5b02e7e:mailgun 0031956:cloudstack \
		83f1503:crypto 8914e50:oauth2 4a71d18:net 5578a8c:dnsmadeeasy \
		e34a32f:gcloud 5c1d07d:godocker a98ad7e:goini \
		efb1971:gophercloud 179d4d0:gouuid 594d483:heroku 61a5285:mergo \
		6b8e5b5:suuid ed3ca8a:uuid 23128e7:winrm 95ba304:simplexml \
		13f4951:xmlpath 743b1af:winrmcp 3e9661c:winrmtest \
		2075bf1:iso8601

STRIP=		# stripping can break go binaries

PLUGINS=	provider-atlas provider-aws provider-azure provider-cloudflare \
		provider-cloudstack provider-consul provider-digitalocean \
		provider-dme provider-dnsimple provider-docker provider-google \
		provider-heroku provider-mailgun provider-null \
		provider-openstack provider-template provider-terraform \
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
	@${MKDIR} ${WRKSRC}/src/code.google.com/p/go-uuid
	@${MKDIR} ${WRKSRC}/src/github.com/Azure
	@${MKDIR} ${WRKSRC}/src/github.com/armon
	@${MKDIR} ${WRKSRC}/src/github.com/aws
	@${MKDIR} ${WRKSRC}/src/github.com/awslabs
	@${MKDIR} ${WRKSRC}/src/github.com/cyberdelia
	@${MKDIR} ${WRKSRC}/src/github.com/dylanmei
	@${MKDIR} ${WRKSRC}/src/github.com/fsouza
	@${MKDIR} ${WRKSRC}/src/github.com/golang
	@${MKDIR} ${WRKSRC}/src/github.com/imdario
	@${MKDIR} ${WRKSRC}/src/github.com/masterzen
	@${MKDIR} ${WRKSRC}/src/github.com/mitchellh
	@${MKDIR} ${WRKSRC}/src/github.com/nu7hatch
	@${MKDIR} ${WRKSRC}/src/github.com/packer-community
	@${MKDIR} ${WRKSRC}/src/github.com/pearkes
	@${MKDIR} ${WRKSRC}/src/github.com/rackspace
	@${MKDIR} ${WRKSRC}/src/github.com/satori
	@${MKDIR} ${WRKSRC}/src/github.com/soniah
	@${MKDIR} ${WRKSRC}/src/github.com/vaughan0
	@${MKDIR} ${WRKSRC}/src/github.com/xanzy
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/google.golang.org
	@${MV} ${WRKSRC_apiclient} ${WRKSRC}/src/google.golang.org/api
	@${MV} ${WRKSRC_asfg} ${WRKSRC}/src/github.com/Azure/azure-sdk-for-go
	@${MV} ${WRKSRC_atlasgo} ${WRKSRC}/src/github.com/hashicorp/atlas-go
	@${CP} -r ${WRKSRC_awssdkgo} ${WRKSRC}/src/github.com/awslabs/aws-sdk-go
	@${MV} ${WRKSRC_awssdkgo} ${WRKSRC}/src/github.com/aws/aws-sdk-go
	@${MV} ${WRKSRC_circbuf} ${WRKSRC}/src/github.com/armon/circbuf
	@${MV} ${WRKSRC_cli} ${WRKSRC}/src/github.com/mitchellh/cli
	@${MV} ${WRKSRC_cloudflare} ${WRKSRC}/src/github.com/pearkes/cloudflare
	@${MV} ${WRKSRC_cloudstack} ${WRKSRC}/src/github.com/xanzy/go-cloudstack
	@${MV} ${WRKSRC_colorstring} ${WRKSRC}/src/github.com/mitchellh/colorstring
	@${MV} ${WRKSRC_consul} ${WRKSRC}/src/github.com/hashicorp/consul
	@${MV} ${WRKSRC_copystructure} ${WRKSRC}/src/github.com/mitchellh/copystructure
	@${MV} ${WRKSRC_crypto} ${WRKSRC}/src/golang.org/x/crypto
	@${MV} ${WRKSRC_digitalocean} ${WRKSRC}/src/github.com/pearkes/digitalocean
	@${MV} ${WRKSRC_dnsimple} ${WRKSRC}/src/github.com/pearkes/dnsimple
	@${MV} ${WRKSRC_dnsmadeeasy} ${WRKSRC}/src/github.com/soniah/dnsmadeeasy
	@${MV} ${WRKSRC_errwrap} ${WRKSRC}/src/github.com/hashicorp/errwrap
	@${MV} ${WRKSRC_gcloud} ${WRKSRC}/src/google.golang.org/cloud
	@${MV} ${WRKSRC_gocheckpoint} ${WRKSRC}/src/github.com/hashicorp/go-checkpoint
	@${MV} ${WRKSRC_godocker} ${WRKSRC}/src/github.com/fsouza/go-dockerclient
	@${MV} ${WRKSRC_gohomedir} ${WRKSRC}/src/github.com/mitchellh/go-homedir
	@${MV} ${WRKSRC_goini} ${WRKSRC}/src/github.com/vaughan0/go-ini
	@${MV} ${WRKSRC_golinereader} ${WRKSRC}/src/github.com/mitchellh/go-linereader
	@${MV} ${WRKSRC_gomultierror} ${WRKSRC}/src/github.com/hashicorp/go-multierror
	@${MV} ${WRKSRC_gophercloud} ${WRKSRC}/src/github.com/rackspace/gophercloud
	@${MV} ${WRKSRC_gouuid} ${WRKSRC}/src/github.com/nu7hatch/gouuid
	@${MV} ${WRKSRC_goversion} ${WRKSRC}/src/github.com/hashicorp/go-version
	@${MV} ${WRKSRC_gpkcs} ${WRKSRC}/src/github.com/Azure/go-pkcs12
	@${MV} ${WRKSRC_hcl} ${WRKSRC}/src/github.com/hashicorp/hcl
	@${MV} ${WRKSRC_heroku} ${WRKSRC}/src/github.com/cyberdelia/heroku-go
	@${MV} ${WRKSRC_iso8601} ${WRKSRC}/src/github.com/dylanmei/iso8601
	@${MV} ${WRKSRC_mailgun} ${WRKSRC}/src/github.com/pearkes/mailgun
	@${MV} ${WRKSRC_mapstructure} ${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKSRC_mergo} ${WRKSRC}/src/github.com/imdario/mergo
	@${CP} -r ${WRKSRC_net} ${WRKSRC}/src/golang.org/x/net
	@${MV} ${WRKSRC_net} ${WRKSRC}/src/github.com/golang/net
	@${MV} ${WRKSRC_oauth2} ${WRKSRC}/src/golang.org/x/oauth2
	@${MV} ${WRKSRC_osext} ${WRKSRC}/src/github.com/mitchellh/osext
	@${MV} ${WRKSRC_packer} ${WRKSRC}/src/github.com/mitchellh/packer
	@${MV} ${WRKSRC_panicwrap} ${WRKSRC}/src/github.com/mitchellh/panicwrap
	@${MV} ${WRKSRC_prefixedio} ${WRKSRC}/src/github.com/mitchellh/prefixedio
	@${MV} ${WRKSRC_reflectwalk} ${WRKSRC}/src/github.com/mitchellh/reflectwalk
	@${MV} ${WRKSRC_simplexml} ${WRKSRC}/src/github.com/masterzen/simplexml
	@${MV} ${WRKSRC_suuid} ${WRKSRC}/src/github.com/satori/go.uuid
	@${MV} ${WRKSRC_uuid}/uuid ${WRKSRC}/src/code.google.com/p/go-uuid/uuid
	@${MV} ${WRKSRC_winrmcp} ${WRKSRC}/src/github.com/packer-community/winrmcp
	@${MV} ${WRKSRC_winrmtest} ${WRKSRC}/src/github.com/dylanmei/winrmtest
	@${MV} ${WRKSRC_winrm} ${WRKSRC}/src/github.com/masterzen/winrm
	@${MV} ${WRKSRC_xmlpath} ${WRKSRC}/src/github.com/masterzen/xmlpath
	@${MV} ${WRKSRC_yamux} ${WRKSRC}/src/github.com/hashicorp/yamux

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
