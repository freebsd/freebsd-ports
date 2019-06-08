# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minikube
PORTVERSION=	1.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Run Kubernetes locally

LICENSE=	APACHE20

BUILD_DEPENDS=	go-bindata:devel/go-bindata
RUN_DEPENDS=	kubectl:sysutils/kubectl

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes
GH_TUPLE=	\
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Parallels:docker-machine-parallels:v1.3.0:parallels_docker_machine_parallels/vendor/github.com/Parallels/docker-machine-parallels \
		Sirupsen:logrus:89742aefa4b2:sirupsen_logrus/vendor/github.com/Sirupsen/logrus \
		blang:semver:v3.5.0:blang_semver/vendor/github.com/blang/semver \
		c4milo:gotoolkit:bcc06269efa9:c4milo_gotoolkit/vendor/github.com/c4milo/gotoolkit \
		cheggaaa:pb:v1.0.6:cheggaaa_pb/vendor/gopkg.in/cheggaaa/pb.v1 \
		cloudfoundry-attic:jibber_jabber:bcc4c8345a21:cloudfoundry_attic_jibber_jabber/vendor/github.com/cloudfoundry-attic/jibber_jabber \
		cpuguy83:go-md2man:v1.0.4:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		moby:moby:v1.13.1:moby_moby/vendor/github.com/docker/docker \
		docker:go-units:9e638d38cf69:docker_go_units/vendor/github.com/docker/go-units \
		docker:machine:v0.16.1:docker_machine/vendor/github.com/docker/machine \
		elazarl:goproxy:9d40249d3c2f:elazarl_goproxy/vendor/github.com/elazarl/goproxy \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		ghodss:yaml:73d445a93680:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-inf:inf:v0.9.0:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-yaml:yaml:v2.2.1:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:c0656edd0d9e:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.4.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:c2843e01d9a2:golang_crypto/vendor/golang.org/x/crypto \
		golang:glog:44145f04b68c:golang_glog/vendor/github.com/golang/glog \
		golang:groupcache:02826c3e7903:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:d8887717615a:golang_net/vendor/golang.org/x/net \
		golang:oauth2:5dab4167f31c:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.2.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:e225da77a7e6:golang_sync/vendor/golang.org/x/sync \
		golang:sys:a9d3bda3a223:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:f51c12702a4d:golang_time/vendor/golang.org/x/time \
		google:btree:v1.0.0:google_btree/vendor/github.com/google/btree \
		google:go-cmp:v0.2.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-containerregistry:019cdfc6adf9:google_go_containerregistry/vendor/github.com/google/go-containerregistry \
		google:go-github:v25.0.2:google_go_github/vendor/github.com/google/go-github/v25 \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:gofuzz:44d81051d367:google_gofuzz/vendor/github.com/google/gofuzz \
		googleapis:gnostic:0c5108395e2d:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		gregjones:httpcache:9cad4c3443a7:gregjones_httpcache/vendor/github.com/gregjones/httpcache \
		hashicorp:errwrap:7554cd9344ce:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:8c5f0ad93604:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-version:v1.1.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:a0d98a5f2880:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:d8c773c4cba1:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hooklift:iso9660:1cf07e5970d8:hooklift_iso9660/vendor/github.com/hooklift/iso9660 \
		imdario:mergo:6633656539c1:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		intel-go:cpuid:1a4a6f06a1c6:intel_go_cpuid/vendor/github.com/intel-go/cpuid \
		jimmidyson:go-download:7f9a90c8c95b:jimmidyson_go_download/vendor/github.com/jimmidyson/go-download \
		johanneswuerbach:nfsexports:1aa528dcb345:johanneswuerbach_nfsexports/vendor/github.com/johanneswuerbach/nfsexports \
		json-iterator:go:v1.1.5:json_iterator_go/vendor/github.com/json-iterator/go \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kr:fs:2788f0dbd169:kr_fs/vendor/github.com/kr/fs \
		libvirt:libvirt-go:v3.4.0:libvirt_libvirt_go/vendor/github.com/libvirt/libvirt-go \
		machine-drivers:docker-machine-driver-vmware:v0.1.1:machine_drivers_docker_machine_driver_vmware/vendor/github.com/machine-drivers/docker-machine-driver-vmware \
		magiconair:properties:61b492c03cf4:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-isatty:v0.0.5:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:737072b4e32b:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-ps:4fdf99ab2936:mitchellh_go_ps/vendor/github.com/mitchellh/go-ps \
		mitchellh:mapstructure:53818660ed49:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		moby:hyperkit:a12cd7250bcd:moby_hyperkit/vendor/github.com/moby/hyperkit \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:4b7aa43c6742:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		olekukonko:tablewriter:bdcc175572fd:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pborman:uuid:ca53cad383ca:pborman_uuid/vendor/github.com/pborman/uuid \
		pelletier:go-buffruneio:v0.1.0:pelletier_go_buffruneio/vendor/github.com/pelletier/go-buffruneio \
		pelletier:go-toml:0049ab3dc4c4:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		peterbourgon:diskv:v2.0.1:peterbourgon_diskv/vendor/github.com/peterbourgon/diskv \
		phayes:freeport:95f893ade6f2:phayes_freeport/vendor/github.com/phayes/freeport \
		pkg:browser:9302be274faa:pkg_browser/vendor/github.com/pkg/browser \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		pkg:profile:3a8809bd8a80:pkg_profile/vendor/github.com/pkg/profile \
		pkg:sftp:4d0e916071f6:pkg_sftp/vendor/github.com/pkg/sftp \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		r2d4:external-storage:8c0e8605dc7b:r2d4_external_storage/vendor/github.com/r2d4/external-storage \
		russross:blackfriday:300106c228d5:russross_blackfriday/vendor/github.com/russross/blackfriday \
		samalba:dockerclient:91d7393ff859:samalba_dockerclient/vendor/github.com/samalba/dockerclient \
		shurcooL:sanitized_anchor_name:10ef21a441db:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.4.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:b28a7effac97:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:e31f36ffc91a:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:6644d46b81fa:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:33c24e77fb80:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.1:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.0.0:spf13_viper/vendor/github.com/spf13/viper \
		xeipuuv:gojsonpointer:e0fe6f683076:xeipuuv_gojsonpointer/vendor/github.com/xeipuuv/gojsonpointer \
		xeipuuv:gojsonreference:e02fc20de94c:xeipuuv_gojsonreference/vendor/github.com/xeipuuv/gojsonreference \
		xeipuuv:gojsonschema:c539bca196be:xeipuuv_gojsonschema/vendor/github.com/xeipuuv/gojsonschema \
		zchee:go-vmnet:97ebf9174097:zchee_go_vmnet/vendor/github.com/zchee/go-vmnet \
		kubernetes:api:2d6f90ab1293:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:103fd098999d:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:apiserver:67c892841170:kubernetes_apiserver/vendor/k8s.io/apiserver \
		kubernetes:client-go:1f13a808da65:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:kube-openapi:50ae88d24ede:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:kubernetes:v1.11.3:kubernetes_kubernetes/vendor/k8s.io/kubernetes

GO_PKGNAME=	k8s.io/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X k8s.io/minikube/pkg/version.version=v${PORTVERSION} \
		-X k8s.io/minikube/pkg/version.isoVersion=v1.1.1 \
		-X k8s.io/minikube/pkg/version.isoPath=minikube/iso"

PLIST_FILES=	bin/${PORTNAME}

SUB_FILES=	pkg-message

post-patch:
	cd ${WRKSRC}/pkg/minikube/tunnel && \
		${LN} -s route_darwin.go route_freebsd.go
	cd ${WRKSRC}/pkg/minikube/cluster && \
		${LN} -s cluster_linux.go cluster_freebsd.go
	cd ${WRKSRC}/third_party/go9p && \
		${LN} -s srv_pipe_linux.go srv_pipe_freebsd.go
	${FIND} ${WRKSRC}/vendor/ -type d -name vendor -exec ${RM} -r {} +

pre-build:
	cd ${WRKSRC} && \
		${LOCALBASE}/bin/go-bindata -nomemcopy \
		-o pkg/minikube/assets/assets.go -pkg assets deploy/addons/...

.include <bsd.port.mk>
