PORTNAME=	crowdsec-firewall-bouncer
PORTVERSION=	0.0.12
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
		-X github.com/crowdsecurity/cs-firewall-bouncer/pkg/version.Tag=freebsd"

SUB_FILES=	pkg-message

post-patch:
	${REINPLACE_CMD} 's,$${BACKEND},pf,g' \
		${WRKSRC}/config/cs-firewall-bouncer.yaml

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}

	${INSTALL_DATA} ${WRKSRC}/config/cs-firewall-bouncer.yaml \
		${STAGEDIR}${ETCDIR}/cs-firewall-bouncer.yaml.sample

	${INSTALL_PROGRAM} ${WRKDIR}/bin/crowdsec-firewall-bouncer \
		${STAGEDIR}${PREFIX}/bin/cs-firewall-bouncer

.include <bsd.port.mk>
