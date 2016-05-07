# $FreeBSD$

PORTNAME=	serf
PORTVERSION=	0.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
PKGNAMEPREFIX=	hashicorp-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Service discovery and configuration made easy

LICENSE=	MPL

BUILD_DEPENDS=	go14>=1.4:lang/go14

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp:DEFAULT,go_msgpack,go_syslog,go_net,logutils,mdns,memberlist \
		armon:circbuf,go_metrics miekg:dns mitchellh:cli,mapstructure \
		ryanuber:columnize golang:crypto
GH_PROJECT=	circbuf:circbuf cli:cli columnize:columnize dns:dns \
		go-metrics:go_metrics go-msgpack:go_msgpack \
		go-syslog:go_syslog go.net:go_net logutils:logutils \
		mapstructure:mapstructure mdns:mdns memberlist:memberlist \
		crypto:crypto
GH_TAGNAME=	0dc08b1:logutils 281073e:mapstructure 983d3a5:columnize \
		fa3f638:go_msgpack 9888dc5:memberlist 42a2b57:go_syslog \
		75e6e86:dns 104dcad:go_net 8102d0e:cli 06b6099:go_metrics \
		9d85cf2:mdns bbbad09:circbuf f18420e:crypto

USE_RC_SUBR=	serf

USERS=		serf
GROUPS=		serf

PLIST_FILES=	bin/serf

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in .gitignore .travis.yml CHANGELOG.md LICENSE Makefile README.md \
	client coordinate command commands.go demo deps main.go main_test.go \
	ops-misc scripts serf testutil version.go website
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/hashicorp/${PORTNAME}
.endfor
	@${MKDIR} ${WRKSRC}/src/github.com/armon
	@${MKDIR} ${WRKSRC}/src/github.com/mitchellh
	@${MKDIR} ${WRKSRC}/src/github.com/miekg
	@${MKDIR} ${WRKSRC}/src/github.com/ryanuber
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/code.google.com/p/go.net
	@${MV} ${WRKSRC_circbuf} \
		${WRKSRC}/src/github.com/armon/circbuf
	@${MV} ${WRKSRC_go_metrics} \
		${WRKSRC}/src/github.com/armon/go-metrics
	@${MV} ${WRKSRC_go_msgpack} \
		${WRKSRC}/src/github.com/hashicorp/go-msgpack
	@${MV} ${WRKSRC_go_syslog} \
		${WRKSRC}/src/github.com/hashicorp/go-syslog
	@${MV} ${WRKSRC_logutils} \
		${WRKSRC}/src/github.com/hashicorp/logutils
	@${MV} ${WRKSRC_memberlist} \
		${WRKSRC}/src/github.com/hashicorp/memberlist
	@${MV} ${WRKSRC_mapstructure} \
		${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKSRC_mdns} \
		${WRKSRC}/src/github.com/hashicorp/mdns
	@${MV} ${WRKSRC_cli} \
		${WRKSRC}/src/github.com/mitchellh/cli
	@${MV} ${WRKSRC_columnize} \
		${WRKSRC}/src/github.com/ryanuber/columnize
	@${MV} ${WRKSRC_dns} \
		${WRKSRC}/src/github.com/miekg/dns
	@${MV} ${WRKSRC_go_net} \
		${WRKSRC}/src/github.com/hashicorp/go.net
	@${MV} ${WRKSRC_crypto} \
		${WRKSRC}/src/golang.org/x/crypto
	@${CP} -r ${WRKSRC}/src/github.com/hashicorp/go.net/internal \
		${WRKSRC}/src/code.google.com/p/go.net

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; \
		${SETENV} CGO_ENABLED=0 PATH=${PATH}:${LOCALBASE}/go14/bin ${BUILD_ENV} GOPATH=${WRKSRC} \
		go build -o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
