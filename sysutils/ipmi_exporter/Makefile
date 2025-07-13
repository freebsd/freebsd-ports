PORTNAME=	ipmi_exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.1
CATEGORIES=	sysutils

MAINTAINER=	meka@tilda.center
COMMENT=	IPMI exporter for Prometheus
WWW=		https://github.com/prometheus-community/ipmi_exporter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreeipmi.so:sysutils/freeipmi

USES=		go:modules
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/prometheus-community/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		etc/${PORTNAME}/ipmi_local.yml.sample \
		etc/${PORTNAME}/ipmi_remote.yml.sample

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/ipmi_local.yml ${STAGEDIR}${ETCDIR}/ipmi_local.yml.sample
	${INSTALL_DATA} ${WRKSRC}/ipmi_remote.yml ${STAGEDIR}${ETCDIR}/ipmi_remote.yml.sample

.include <bsd.port.mk>
