PORTNAME=	promxy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.93
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	timp87@gmail.com
COMMENT=	Aggregating proxy to enable HA prometheus
WWW=		https://github.com/jacksontj/promxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
USE_RC_SUBR=	promxy
GO_MODULE=	github.com/jacksontj/promxy
GO_TARGET=	./cmd/promxy
GO_BUILDFLAGS=	-ldflags=" \
			-X github.com/prometheus/common/version.Version=v${DISTVERSION} \
			-X github.com/prometheus/common/version.Revision=${PORTREVISION} \
			-X github.com/prometheus/common/version.Branch=release-${PORTVERSION:R} \
			-X github.com/prometheus/common/version.BuildUser=${USER} \
			-X github.com/prometheus/common/version.BuildDate=$$(date +'%Y%m%d-%T')"

SUB_LIST=	GROUPS=${GROUPS} \
		USERS=${USERS}

USERS=		promxy
GROUPS=		promxy

post-patch:
	@${REINPLACE_CMD} 's|"\*rule"|"${ETCDIR}/*rule"|' ${WRKSRC}/cmd/promxy/config.yaml

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for f in alert_example.rule config.yaml
	${INSTALL_DATA} ${WRKSRC}/cmd/promxy/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor

.include <bsd.port.mk>
