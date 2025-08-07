PORTNAME=	crowdsec-blocklist-mirror
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.2
DISTVERSIONSUFFIX=	-freebsd
PORTREVISION=	16
CATEGORIES=	security

MAINTAINER=	marco@crowdsec.net
COMMENT=	CrowdSec Blocklist Mirror
WWW=		https://github.com/crowdsecurity/cs-blocklist-mirror

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	git:devel/git@lite

USES=		gmake go:no_targets

USE_GITHUB=	yes
GH_ACCOUNT=	crowdsecurity
GH_PROJECT=	cs-blocklist-mirror
_BUILD_TAG=	60597cec
USE_RC_SUBR=	crowdsec_mirror

MAKE_ARGS=	BUILD_VERSION="${DISTVERSIONFULL}" \
		BUILD_TAG="${_BUILD_TAG}" \
		BUILD_VENDOR_FLAGS="-mod=vendor -modcacherw"

ETCDIR=		${PREFIX}/etc/crowdsec/bouncers

SUB_FILES=	pkg-deinstall pkg-install pkg-message

do-install:
	#
	# Binaries
	#

	${INSTALL_PROGRAM} ${WRKSRC}/crowdsec-blocklist-mirror \
		${STAGEDIR}${PREFIX}/bin/crowdsec-blocklist-mirror

	#
	# Configuration
	#

	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/crowdsec-blocklist-mirror.yaml \
		${STAGEDIR}${ETCDIR}/crowdsec-blocklist-mirror.yaml.sample

.include <bsd.port.mk>
