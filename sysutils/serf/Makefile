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

GH_ACCOUNT=	hashicorp
GH_SUBDIR:=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

GH_TUPLE=	hashicorp:go-msgpack:fa3f638:msgpack/src/github.com/hashicorp/go-msgpack \
		hashicorp:go-syslog:42a2b57:syslog/src/github.com/hashicorp/go-syslog \
		hashicorp:go.net:104dcad:net/src/github.com/hashicorp/go.net \
		hashicorp:logutils:0dc08b1:logutil/src/github.com/hashicorp/logutils \
		hashicorp:mdns:9d85cf2:mdns/src/github.com/hashicorp/mdns \
		hashicorp:memberlist:9888dc5:memberlist/src/github.com/hashicorp/memberlist \
		armon:circbuf:bbbad09:circbuf/src/github.com/armon/circbuf \
		armon:go-metrics:06b6099:metrics/src/github.com/armon/go-metrics \
		miekg:dns:75e6e86:dns/src/github.com/miekg/dns \
		mitchellh:cli:8102d0e:cli/src/github.com/mitchellh/cli \
		mitchellh:mapstructure:281073e:mapstructure/src/github.com/mitchellh/mapstructure \
		ryanuber:columnize:983d3a5:columnize/src/github.com/ryanuber/columnize \
		golang:crypto:f18420e:crypto/src/golang.org/x/crypto

USE_RC_SUBR=	serf

USERS=		serf
GROUPS=		serf

PLIST_FILES=	bin/serf

STRIP=		# stripping can break go binaries

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; \
		${SETENV} CGO_ENABLED=0 PATH=${PATH}:${LOCALBASE}/go14/bin ${BUILD_ENV} GOPATH=${WRKSRC} \
		go build -o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
