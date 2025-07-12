PORTNAME=	connect
DISTVERSIONPREFIX=	v
DISTVERSION=	4.60.1
CATEGORIES=	net
PKGNAMEPREFIX=	redpanda-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Stream processor for a wide array of data sources and sinks
WWW=		https://redpanda.com/blog/redpanda-connect

# RCL license applies to some connectors
LICENSE=	APACHE20 RCL
LICENSE_COMB=	multi
LICENSE_NAME_RCL=	Redpanda Community License Agreement
LICENSE_FILE_APACHE20=	${WRKSRC}/licenses/Apache-2.0.txt
LICENSE_FILE_RCL=	${WRKSRC}/licenses/rcl.md
LICENSE_PERMS_RCL=	dist-mirror dist-sell pkg-mirror pkg-sell \
			no-auto-accept
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		go:modules
USE_RC_SUBR=	redpanda_connect

GO_MODULE=	github.com/redpanda-data/connect/v4
GO_TARGET=	./cmd/redpanda-connect

ETCDIR=		${PREFIX}/etc/${PKGNAMEPREFIX}${PORTNAME}

# Redpanda Connect was formerly known as Benthos
USERS=		benthos
GROUPS=		benthos

PLIST_FILES=	"@dir(,,755) %%ETCDIR%%" \
		"@sample %%ETCDIR%%/config.yaml.sample" \
		bin/redpanda-connect

OPTIONS_DEFINE=		ENTERPRISE
ENTERPRISE_DESC=	Enable connectors under the RCL license

.include <bsd.port.pre.mk>

post-patch:
.if !${PORT_OPTIONS:MENTERPRISE}
	@${PATCH} -d ${WRKSRC} < ${FILESDIR}/remove-enterprise-connectors.patch
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/config.yaml ${STAGEDIR}${ETCDIR}/config.yaml.sample

.include <bsd.port.post.mk>
