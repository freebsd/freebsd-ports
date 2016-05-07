# $FreeBSD$

PORTNAME?=	mcollective-service-common
PORTVERSION=	3.1.3
CATEGORIES=	sysutils

MAINTAINER=	romain@FreeBSD.org
COMMENT?=	MCollective common files to manage the OS Services

LICENSE=	APACHE20

RUN_DEPENDS?=	mcollective>=2:sysutils/mcollective

USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs
GH_PROJECT=	mcollective-service-agent

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES?=	share/mcollective/agent/service.ddl \
		share/mcollective/data/service_data.ddl \
		share/mcollective/data/service_data.rb \
		share/mcollective/util/service/base.rb \
		share/mcollective/util/service/puppetservice.rb \
		share/mcollective/validator/service_name.ddl \
		share/mcollective/validator/service_name.rb

.if !target(do-install)
do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "agent/*.ddl data util validator" ${STAGEDIR}${PREFIX}/share/mcollective
.endif

.include <bsd.port.mk>
