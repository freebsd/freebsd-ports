--- go.mod.orig	2023-03-26 20:47:00 UTC
+++ go.mod
@@ -1,6 +1,6 @@
 module github.com/openshift/oc
 
-go 1.16
+go 1.17
 
 require (
 	github.com/AaronO/go-git-http v0.0.0-20161214145340-1d9485b3a98f
@@ -21,10 +21,7 @@ require (
 	github.com/fsnotify/fsnotify v1.4.9
 	github.com/fsouza/go-dockerclient v1.7.1
 	github.com/ghodss/yaml v1.0.0
-	github.com/golangplus/testing v1.0.0 // indirect
 	github.com/gonum/graph v0.0.0-20170401004347-50b27dea7ebb
-	github.com/gonum/mathext v0.0.0-20181121095525-8a4bf007ea55 // indirect
-	github.com/gonum/stat v0.0.0-20181125101827-41a0da705a5b // indirect
 	github.com/google/go-cmp v0.5.5
 	github.com/joelanford/ignore v0.0.0-20210610194209-63d4919d8fb2
 	github.com/mitchellh/go-wordwrap v1.0.0
@@ -40,9 +37,8 @@ require (
 	github.com/russross/blackfriday v1.5.2
 	github.com/spf13/cobra v1.1.3
 	github.com/spf13/pflag v1.0.5
-	github.com/xeipuuv/gojsonpointer v0.0.0-20190905194746-02993c407bfb // indirect
 	golang.org/x/crypto v0.0.0-20210322153248-0c34fe9e7dc2
-	golang.org/x/sys v0.0.0-20210616094352-59db8d763f22
+	golang.org/x/sys v0.6.0
 	golang.org/x/time v0.0.0-20210220033141-f8bda1e9f3ba
 	gopkg.in/ldap.v2 v2.5.1
 	gopkg.in/yaml.v3 v3.0.0-20210107192922-496545a6307b
@@ -56,6 +52,123 @@ require (
 	k8s.io/kubectl v0.22.0-rc.0
 	k8s.io/utils v0.0.0-20210707171843-4b05e18ac7d9
 	sigs.k8s.io/yaml v1.2.0
+)
+
+require (
+	cloud.google.com/go v0.54.0 // indirect
+	github.com/Azure/go-ansiterm v0.0.0-20210617225240-d185dfc1b5a1 // indirect
+	github.com/Azure/go-autorest v14.2.0+incompatible // indirect
+	github.com/Azure/go-autorest/autorest v0.11.18 // indirect
+	github.com/Azure/go-autorest/autorest/adal v0.9.13 // indirect
+	github.com/Azure/go-autorest/autorest/date v0.3.0 // indirect
+	github.com/Azure/go-autorest/logger v0.2.1 // indirect
+	github.com/Azure/go-autorest/tracing v0.6.0 // indirect
+	github.com/Microsoft/go-winio v0.5.0 // indirect
+	github.com/Microsoft/hcsshim v0.8.20 // indirect
+	github.com/PuerkitoBio/purell v1.1.1 // indirect
+	github.com/PuerkitoBio/urlesc v0.0.0-20170810143723-de5bf2ad4578 // indirect
+	github.com/beorn7/perks v1.0.1 // indirect
+	github.com/cespare/xxhash/v2 v2.1.1 // indirect
+	github.com/chai2010/gettext-go v0.0.0-20160711120539-c6fed771bfd5 // indirect
+	github.com/containerd/cgroups v1.0.1 // indirect
+	github.com/containerd/containerd v1.5.1 // indirect
+	github.com/containerd/continuity v0.1.0 // indirect
+	github.com/containers/libtrust v0.0.0-20190913040956-14b96171aa3b // indirect
+	github.com/containers/ocicrypt v1.1.2 // indirect
+	github.com/containers/storage v1.33.0 // indirect
+	github.com/daviddengcn/go-colortext v0.0.0-20160507010035-511bcaf42ccd // indirect
+	github.com/docker/go-connections v0.4.0 // indirect
+	github.com/docker/go-metrics v0.0.1 // indirect
+	github.com/emicklei/go-restful v2.9.5+incompatible // indirect
+	github.com/evanphx/json-patch v4.11.0+incompatible // indirect
+	github.com/exponent-io/jsonpath v0.0.0-20151013193312-d6023ce2651d // indirect
+	github.com/fatih/camelcase v1.0.0 // indirect
+	github.com/form3tech-oss/jwt-go v3.2.3+incompatible // indirect
+	github.com/fvbommel/sortorder v1.0.1 // indirect
+	github.com/go-errors/errors v1.0.1 // indirect
+	github.com/go-git/gcfg v1.5.0 // indirect
+	github.com/go-git/go-billy/v5 v5.1.0 // indirect
+	github.com/go-git/go-git/v5 v5.3.0 // indirect
+	github.com/go-logr/logr v0.4.0 // indirect
+	github.com/go-openapi/jsonpointer v0.19.5 // indirect
+	github.com/go-openapi/jsonreference v0.19.5 // indirect
+	github.com/go-openapi/swag v0.19.14 // indirect
+	github.com/gogo/protobuf v1.3.2 // indirect
+	github.com/golang/groupcache v0.0.0-20210331224755-41bb18bfe9da // indirect
+	github.com/golang/protobuf v1.5.2 // indirect
+	github.com/golangplus/testing v1.0.0 // indirect
+	github.com/gonum/blas v0.0.0-20181208220705-f22b278b28ac // indirect
+	github.com/gonum/floats v0.0.0-20181209220543-c233463c7e82 // indirect
+	github.com/gonum/internal v0.0.0-20181124074243-f884aa714029 // indirect
+	github.com/gonum/lapack v0.0.0-20181123203213-e4cdc5a0bff9 // indirect
+	github.com/gonum/mathext v0.0.0-20181121095525-8a4bf007ea55 // indirect
+	github.com/gonum/matrix v0.0.0-20181209220409-c518dec07be9 // indirect
+	github.com/gonum/stat v0.0.0-20181125101827-41a0da705a5b // indirect
+	github.com/google/btree v1.0.1 // indirect
+	github.com/google/gofuzz v1.1.0 // indirect
+	github.com/google/shlex v0.0.0-20191202100458-e7afc7fbc510 // indirect
+	github.com/google/uuid v1.2.0 // indirect
+	github.com/googleapis/gnostic v0.5.5 // indirect
+	github.com/gorilla/mux v1.8.0 // indirect
+	github.com/gregjones/httpcache v0.0.0-20180305231024-9cad4c3443a7 // indirect
+	github.com/imdario/mergo v0.3.12 // indirect
+	github.com/inconshreveable/mousetrap v1.0.0 // indirect
+	github.com/jbenet/go-context v0.0.0-20150711004518-d14ea06fba99 // indirect
+	github.com/jmespath/go-jmespath v0.4.0 // indirect
+	github.com/jonboulle/clockwork v0.2.2 // indirect
+	github.com/josharian/intern v1.0.0 // indirect
+	github.com/json-iterator/go v1.1.11 // indirect
+	github.com/liggitt/tabwriter v0.0.0-20181228230101-89fcab3d43de // indirect
+	github.com/lithammer/dedent v1.1.0 // indirect
+	github.com/mailru/easyjson v0.7.6 // indirect
+	github.com/matttproud/golang_protobuf_extensions v1.0.2-0.20181231171920-c182affec369 // indirect
+	github.com/moby/spdystream v0.2.0 // indirect
+	github.com/moby/sys/mount v0.2.0 // indirect
+	github.com/moby/sys/mountinfo v0.4.1 // indirect
+	github.com/moby/term v0.0.0-20210610120745-9d4ed1856297 // indirect
+	github.com/modern-go/concurrent v0.0.0-20180306012644-bacd9c7ef1dd // indirect
+	github.com/modern-go/reflect2 v1.0.1 // indirect
+	github.com/monochromegane/go-gitignore v0.0.0-20200626010858-205db1a8cc00 // indirect
+	github.com/morikuni/aec v1.0.0 // indirect
+	github.com/mtrmac/gpgme v0.1.2 // indirect
+	github.com/mxk/go-flowrate v0.0.0-20140419014527-cca7078d478f // indirect
+	github.com/opencontainers/runc v1.0.1 // indirect
+	github.com/opencontainers/runtime-spec v1.0.3-0.20210326190908-1c3f411f0417 // indirect
+	github.com/peterbourgon/diskv v2.0.1+incompatible // indirect
+	github.com/pkg/profile v1.3.0 // indirect
+	github.com/pmezard/go-difflib v1.0.0 // indirect
+	github.com/prometheus/client_model v0.2.0 // indirect
+	github.com/prometheus/common v0.26.0 // indirect
+	github.com/prometheus/procfs v0.6.0 // indirect
+	github.com/sirupsen/logrus v1.8.1 // indirect
+	github.com/stretchr/testify v1.7.0 // indirect
+	github.com/syndtr/gocapability v0.0.0-20200815063812-42c35b437635 // indirect
+	github.com/xeipuuv/gojsonpointer v0.0.0-20190905194746-02993c407bfb // indirect
+	github.com/xlab/treeprint v0.0.0-20181112141820-a009c3971eca // indirect
+	go.opencensus.io v0.22.3 // indirect
+	go.starlark.net v0.0.0-20200306205701-8dd3e2ee1dd5 // indirect
+	golang.org/x/exp v0.0.0-20200224162631-6cc2880d07d6 // indirect
+	golang.org/x/net v0.0.0-20210520170846-37e1c6afe023 // indirect
+	golang.org/x/oauth2 v0.0.0-20200107190931-bf48bf16ab8d // indirect
+	golang.org/x/sync v0.0.0-20210220032951-036812b2e83c // indirect
+	golang.org/x/term v0.0.0-20210220032956-6a3ed077a48d // indirect
+	golang.org/x/text v0.3.6 // indirect
+	golang.org/x/tools v0.1.2 // indirect
+	google.golang.org/appengine v1.6.5 // indirect
+	google.golang.org/genproto v0.0.0-20210602131652-f16073e35f0c // indirect
+	google.golang.org/grpc v1.38.0 // indirect
+	google.golang.org/protobuf v1.26.0 // indirect
+	gopkg.in/asn1-ber.v1 v1.0.0-20181015200546-f715ec2f112d // indirect
+	gopkg.in/inf.v0 v0.9.1 // indirect
+	gopkg.in/warnings.v0 v0.1.2 // indirect
+	gopkg.in/yaml.v2 v2.4.0 // indirect
+	k8s.io/component-helpers v0.22.0-rc.0 // indirect
+	k8s.io/kube-openapi v0.0.0-20210421082810-95288971da7e // indirect
+	k8s.io/metrics v0.22.0-rc.0 // indirect
+	sigs.k8s.io/kustomize/api v0.8.11 // indirect
+	sigs.k8s.io/kustomize/kustomize/v4 v4.2.0 // indirect
+	sigs.k8s.io/kustomize/kyaml v0.11.0 // indirect
+	sigs.k8s.io/structured-merge-diff/v4 v4.1.2 // indirect
 )
 
 replace (
