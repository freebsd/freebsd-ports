PORTNAME=	crowdsec-firewall-bouncer
PORTVERSION=	0.0.20  # NOTE: change BUILD_VERSION and BUILD_TAG as well
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	marco@crowdsec.net
COMMENT=	CrowdSec bouncer written in golang for firewalls

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	git:devel/git@lite \
		go:lang/go

USES=		gmake

RUN_DEPENDS=	crowdsec>0:security/crowdsec

USE_GITHUB=	yes
GH_ACCOUNT=	crowdsecurity
GH_PROJECT=	cs-firewall-bouncer
GH_TAGNAME=	v0.0.20-freebsd
#GH_TAGNAME is automatically set from DISTVERSION

USE_RC_SUBR=	crowdsec_firewall

SUB_FILES=	pkg-message \
		pkg-deinstall

# BUILD_VERSION=$(git describe --tags $(git rev-list --tags --max-count=1))
# BUILD_TAG=$(git rev-parse HEAD)
MAKE_ENV=	BUILD_VERSION="v0.0.20" \
		BUILD_TAG="a456a4debdf3d3551c89b8490bb942f626027310"

ETCDIR=		${PREFIX}/etc/crowdsec/bouncers

post-patch:
	${REINPLACE_CMD} 's,$${BACKEND},pf,g' \
		${WRKSRC}/config/crowdsec-firewall-bouncer.yaml

do-install:
	#
	# Binaries
	#

	${INSTALL_PROGRAM} ${WRKSRC}/crowdsec-firewall-bouncer \
		${STAGEDIR}${PREFIX}/bin/crowdsec-firewall-bouncer

	#
	# Configuration
	#

	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/crowdsec-firewall-bouncer.yaml \
		${STAGEDIR}${ETCDIR}/crowdsec-firewall-bouncer.yaml.sample

	#
	# Log rotation
	#

	${INSTALL_DATA} ${FILESDIR}/crowdsec-firewall-bouncer.conf-newsyslog ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/crowdsec-firewall-bouncer.conf.sample

.include <bsd.port.mk>
