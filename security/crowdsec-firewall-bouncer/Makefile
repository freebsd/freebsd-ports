PORTNAME=	crowdsec-firewall-bouncer
PORTVERSION=	0.0.23.r2  # NOTE: change BUILD_VERSION and BUILD_TAG as well
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	marco@crowdsec.net
COMMENT=	CrowdSec bouncer written in golang for firewalls

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	git:devel/git@lite \
		go:lang/go

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	crowdsecurity
GH_PROJECT=	cs-firewall-bouncer
GH_TAGNAME=	v0.0.23.r2-freebsd
#GH_TAGNAME is automatically set from DISTVERSION

USE_RC_SUBR=	crowdsec_firewall

SUB_FILES=	pkg-deinstall pkg-install pkg-message

# BUILD_VERSION=$(git describe --tags $(git rev-list --tags --max-count=1))
# BUILD_TAG=$(git rev-parse HEAD)
MAKE_ENV=	BUILD_TAG="bc4bb1d531d47ad94ead2dce3a11f6391b1e8619" \
		BUILD_VERSION="v0.0.23-rc2"

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

.include <bsd.port.mk>
