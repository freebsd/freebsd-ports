PORTNAME=		ooni-probe-cli
DISTVERSIONPREFIX=	v
DISTVERSION=		3.10.1
CATEGORIES=		net www benchmarks

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Next generation OONI Probe CLI

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		go:modules
USE_GITHUB=	yes
USE_GITLAB=	nodefault

# github.com/ooni/probe-engine/blob/master/readme_compiletimecheck.go#L6
GO_BUILDFLAGS=	-tags=ooni,nomk,DISABLE_QUIC -ldflags '-s -w -extldflags "-static"'
GO_TARGET=	./cmd/ooniprobe
GH_ACCOUNT=	ooni
GH_PROJECT=	probe-cli
GH_TUPLE=	AlecAivazis:survey:v1.8.8:alecaivazis_survey/vendor/gopkg.in/AlecAivazis/survey.v1 \
		FiloSottile:age:v1.0.0-rc.1:filosottile_age/vendor/filippo.io/age \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/github.com/alecthomas/kingpin \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:ff826a37aa15:alecthomas_units/vendor/github.com/alecthomas/units \
		apex:log:v1.9.0:apex_log/vendor/github.com/apex/log \
		armon:go-socks5:e75332964ef5:armon_go_socks5/vendor/github.com/armon/go-socks5 \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		creack:goselect:v0.1.2:creack_goselect/vendor/github.com/creack/goselect \
		cretz:bine:v0.1.0:cretz_bine/vendor/github.com/cretz/bine \
		dchest:siphash:v1.2.2:dchest_siphash/vendor/github.com/dchest/siphash \
		dsnet:compress:v0.0.1:dsnet_compress/vendor/github.com/dsnet/compress \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-gorp:gorp:v1.7.2:go_gorp_gorp/vendor/gopkg.in/gorp.v1 \
		go-mgo:mgo:a6b53ec6cb22:go_mgo_mgo/vendor/gopkg.in/mgo.v2 \
		go-task:slim-sprig:348f09dbbbc0:go_task_slim_sprig/vendor/github.com/go-task/slim-sprig \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		golang:crypto:32db794688a5:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.5.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:60bc85c4be6d:golang_net/vendor/golang.org/x/net \
		golang:sys:bfb29a6856f2:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.5:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.5:google_go_cmp/vendor/github.com/google/go-cmp \
		google:martian:v3.1.0:google_martian_v3/vendor/github.com/google/martian/v3 \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		hexops:gotextdiff:v1.0.3:hexops_gotextdiff/vendor/github.com/hexops/gotextdiff \
		iancoleman:strcase:v0.1.3:iancoleman_strcase/vendor/github.com/iancoleman/strcase \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		lucas-clemente:quic-go:v0.23.0:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		marten-seemann:qpack:v0.2.1:marten_seemann_qpack/vendor/github.com/marten-seemann/qpack \
		marten-seemann:qtls-go1-16:v0.1.4:marten_seemann_qtls_go1_16/vendor/github.com/marten-seemann/qtls-go1-16 \
		marten-seemann:qtls-go1-17:v0.1.0:marten_seemann_qtls_go1_17/vendor/github.com/marten-seemann/qtls-go1-17 \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-sqlite3:v1.14.7:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		miekg:dns:v1.1.42:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-wordwrap:v1.0.1:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		montanaflynn:stats:v0.6.6:montanaflynn_stats/vendor/github.com/montanaflynn/stats \
		nxadm:tail:v1.4.8:nxadm_tail/vendor/github.com/nxadm/tail \
		onsi:ginkgo:v1.16.4:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		ooni:probe-assets:v0.3.1:ooni_probe_assets/vendor/github.com/ooni/probe-assets \
		ooni:psiphon:v0.8.0:ooni_psiphon/vendor/github.com/ooni/psiphon \
		oschwald:geoip2-golang:v1.5.0:oschwald_geoip2_golang/vendor/github.com/oschwald/geoip2-golang \
		oschwald:maxminddb-golang:v1.8.0:oschwald_maxminddb_golang/vendor/github.com/oschwald/maxminddb-golang \
		pborman:getopt:v2.1.0:pborman_getopt_v2/vendor/github.com/pborman/getopt \
		pion:stun:v0.3.5:pion_stun/vendor/github.com/pion/stun \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		rogpeppe:go-internal:v1.8.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		rubenv:sql-migrate:a32ed26c37ea:rubenv_sql_migrate/vendor/github.com/rubenv/sql-migrate \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		upper:db:v3.8.0:upper_db/vendor/upper.io/db.v3 \
		ziutek:mymysql:v1.5.4:ziutek_mymysql/vendor/github.com/ziutek/mymysql

GH_TUPLE+=	shuLhan:go-bindata:v3.3.0:shuLhan_go_bindata/vendor/github.com/shuLhan/go-bindata \
		torbsd:goptlib:v1.1.0:torbsd_goptlib/vendor/git.torproject.org/pluggable-transports/goptlib.git

GL_TUPLE=	yawning:bsaes:0a714cd429ec754482b4001e918db30cd2094405:yawning_bsaes/vendor/gitlab.com/yawning/bsaes.git \
		yawning:obfs4:e330d1b7024b4ab04f7d96cc1afc61325744fafc:yawning_obfs4/vendor/gitlab.com/yawning/obfs4.git \
		yawning:utls:f1bcf4b40e4596d0ccd1dbf8f3a9f4922f9759ca:yawning_utls/vendor/gitlab.com/yawning/utls.git

PLIST_FILES=	bin/ooniprobe

.include <bsd.port.mk>
