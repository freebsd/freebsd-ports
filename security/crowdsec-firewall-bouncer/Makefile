PORTNAME=	crowdsec-firewall-bouncer
PORTVERSION=	0.0.13
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Crowdsec bouncer written in golang for firewalls

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	crowdsec>0:security/crowdsec

USES=		go:modules

USE_RC_SUBR=	crowdsec_firewall

GO_MODULE=	github.com/crowdsecurity/cs-firewall-bouncer

GO_BUILDFLAGS=	-ldflags "-s -w \
		-X github.com/crowdsecurity/cs-firewall-bouncer/pkg/version.Version=v${PORTVERSION} \
		-X github.com/crowdsecurity/cs-firewall-bouncer/pkg/version.Tag=freebsd \
		-X github.com/crowdsecurity/cs-firewall-bouncer/pkg/version.BuildDate=`date -u '+%Y-%m-%d_%I:%M:%S%p'`"

SUB_FILES=	pkg-message

post-patch:
	${REINPLACE_CMD} 's,$${BACKEND},pf,g' \
		${WRKSRC}/config/crowdsec-firewall-bouncer.yaml

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}

	${INSTALL_DATA} ${WRKSRC}/config/crowdsec-firewall-bouncer.yaml \
		${STAGEDIR}${ETCDIR}/crowdsec-firewall-bouncer.yaml.sample

	${INSTALL_PROGRAM} ${WRKDIR}/bin/crowdsec-firewall-bouncer \
		${STAGEDIR}${PREFIX}/bin/crowdsec-firewall-bouncer

.include <bsd.port.mk>
