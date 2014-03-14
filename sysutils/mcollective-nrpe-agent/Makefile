# $FreeBSD$

PORTNAME=	mcollective-nrpe-agent
PORTVERSION=	20130805
CATEGORIES=	sysutils

MAINTAINER=	ports@robakdesign.com
COMMENT=	MCollective NRPE agent plugin

RUN_DEPENDS=	mcollective>=2:${PORTSDIR}/sysutils/mcollective

USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	ee29242

PLIST_FILES=	share/mcollective/agent/nrpe.ddl \
		share/mcollective/agent/nrpe.rb \
		share/mcollective/aggregate/nagios_states.rb \
		share/mcollective/application/nrpe.rb \
		share/mcollective/data/nrpe_data.ddl \
		share/mcollective/data/nrpe_data.rb \
		sbin/check-mc-nrpe
PLIST_DIRSTRY=	share/mcollective/agent \
		share/mcollective/aggregate \
		share/mcollective/application \
		share/mcollective/data

NO_BUILD=	yes

do-install:

.for dir in ${PLIST_DIRSTRY}
	${MKDIR} ${STAGEDIR}${PREFIX}/${dir}
.endfor

	${INSTALL_DATA} ${WRKSRC}/agent/nrpe.ddl ${STAGEDIR}${PREFIX}/share/mcollective/agent/
	${INSTALL_DATA} ${WRKSRC}/agent/nrpe.rb ${STAGEDIR}${PREFIX}/share/mcollective/agent/
	${INSTALL_DATA} ${WRKSRC}/aggregate/nagios_states.rb ${STAGEDIR}${PREFIX}/share/mcollective/aggregate/
	${INSTALL_DATA} ${WRKSRC}/application/nrpe.rb ${STAGEDIR}${PREFIX}/share/mcollective/application/
	${INSTALL_DATA} ${WRKSRC}/data/nrpe_data.ddl ${STAGEDIR}${PREFIX}/share/mcollective/data/
	${INSTALL_DATA} ${WRKSRC}/data/nrpe_data.rb ${STAGEDIR}${PREFIX}/share/mcollective/data/
	${INSTALL_SCRIPT} ${WRKSRC}/sbin/check-mc-nrpe ${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
