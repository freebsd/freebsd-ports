# Created by: Nikolai Lifanov <lifanov@FreeBSD.org> and Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zrepl
PORTVERSION=	0.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	ZFS dataset replication tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go
USE_RC_SUBR=	zrepl
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
USE_GITHUB=	yes
GH_SUBDIR=	src/github.com/zrepl/zrepl
GH_TUPLE=	beorn7:perks:3a771d9:perks/src/github.com/beorn7/perks \
		fatih:color:v1.7.0:color/src/github.com/fatih/color \
		ftrvxmtrx:fd:c6d8003:fd/src/github.com/ftrvxmtrx/fd \
		gdamore:encoding:b23993c:encoding/src/github.com/gdamore/encoding \
		gdamore:tcell:v1.1.0:tcell/src/github.com/gdamore/tcell \
		go-logfmt:logfmt:v0.4.0:logfmt/src/github.com/go-logfmt/logfmt \
		golang:net:351d144:net/src/golang.org/x/net \
		golang:protobuf:v1.3.1:protobuf/src/github.com/golang/protobuf \
		golang:sync:e225da7:sync/src/golang.org/x/sync \
		golang:sys:4ed8d59:sys/src/golang.org/x/sys \
		golang:text:v0.3.0:go_text/src/golang.org/x/text \
		google:go-genproto:bd91e49:genproto/src/google.golang.org/genproto \
		google:uuid:v1.1.1:uuid/src/github.com/google/uuid \
		grpc:grpc-go:v1.17.0:grpc/src/google.golang.org/grpc \
		jinzhu:copier:db4671f:copier/src/github.com/jinzhu/copier \
		kr:pretty:cfb55aa:pretty/src/github.com/kr/pretty \
		kr:text:7cafcd8:text/src/github.com/kr/text \
		lucasb-eyer:go-colorful:v1.0:go_colorful/src/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:v0.0.3:go_isatty/src/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.3:go_runewidth/src/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.0:golang_protobuf_extensions/src/github.com/matttproud/golang_protobuf_extensions \
		pkg:errors:v0.8.1:errors/src/github.com/pkg/errors \
		problame:go-netssh:09d6bc4:go_netssh/src/github.com/problame/go-netssh \
		problame:go-rwccmd:391d2c7:go_rwccmd/src/github.com/problame/go-rwccmd \
		prometheus:client_golang:e11c6ff:client_golang/src/github.com/prometheus/client_golang \
		prometheus:client_model:99fa1f4:client_model/src/github.com/prometheus/client_model \
		prometheus:common:d0f7cd6:common/src/github.com/prometheus/common \
		prometheus:procfs:8b1c2da:procfs/src/github.com/prometheus/procfs \
		spf13:cobra:b787445:cobra/src/github.com/spf13/cobra \
		spf13:pflag:v1.0.0:pflag/src/github.com/spf13/pflag \
		stretchr:testify:v1.1.4:testify/src/github.com/stretchr/testify \
		theckman:goconstraint:v1.11.0:goconstraint/src/github.com/theckman/goconstraint \
		zrepl:yaml-config:08227ad:yaml_config/src/github.com/zrepl/yaml-config

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_USES=		python:build
MANPAGES_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR}
MANPAGES_PLIST_FILES=	man/man1/zrepl.1.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD"
SUB_LIST+=	DAEMON_LOGGING="-S -l \$${zrepl_facility} -s \$${zrepl_priority} -T \$${name}"
.else
SUB_LIST+=	DAEMON_LOGGING=""
.endif

post-extract:
	${LN} -sf ${WRKSRC}/src ${WRKDIR}

post-build-MANPAGES-on:
	@${MAKE_CMD} -C ${WRKSRC}/docs SPHINXBUILD=sphinx-build-${PYTHON_VER} man

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zrepl/samples
	${INSTALL_DATA} ${WRKSRC}/dist/grafana/grafana-prometheus-zrepl-0.1.json ${STAGEDIR}${PREFIX}/share/zrepl/samples/
	${INSTALL_DATA} ${WRKSRC}/config/samples/* ${STAGEDIR}${PREFIX}/share/zrepl/samples/

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d \
		${STAGEDIR}${PREFIX}/etc/syslog.d \
		${STAGEDIR}${PREFIX}/etc/zrepl \
		${STAGEDIR}/var/run/zrepl
	${INSTALL_DATA} ${FILESDIR}/newsyslog-zrepl.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/zrepl.conf.sample
	${INSTALL_DATA} ${FILESDIR}/syslog-zrepl.conf.sample ${STAGEDIR}${PREFIX}/etc/syslog.d/zrepl.conf.sample
	${INSTALL_DATA} ${FILESDIR}/zrepl.yml.sample ${STAGEDIR}${PREFIX}/etc/zrepl/zrepl.yml.sample

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/docs/_build/man/zrepl.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.post.mk>
