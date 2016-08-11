# $FreeBSD$

PORTNAME?=	mcollective-nrpe-common
PORTVERSION=	3.1.0
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	MCollective common files to interact with the NRPE monitoring system

LICENSE=	APACHE20

RUN_DEPENDS?=	mcollective>=2:sysutils/mcollective

USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs
GH_PROJECT=	mcollective-nrpe-agent

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES?=	share/mcollective/agent/nrpe.ddl \
		share/mcollective/data/nrpe_data.ddl \
		share/mcollective/data/nrpe_data.rb

.if !target(do-install)
do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "agent/*.ddl data" ${STAGEDIR}${PREFIX}/share/mcollective
.endif

.include <bsd.port.mk>
