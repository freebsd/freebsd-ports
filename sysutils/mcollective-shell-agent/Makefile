# Created by: Bartek Rutkowski <robak@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mcollective-shell-agent
PORTVERSION=	0.0.1
CATEGORIES=	sysutils

MAINTAINER=	robak@FreeBSD.org
COMMENT=	MCollective shell agent plugin

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	mcollective>=2.2.4:${PORTSDIR}/sysutils/mcollective

USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	9fb27d5

PLIST_FILES=	share/mcollective/agent/shell/job.rb \
		share/mcollective/agent/shell.rb \
		share/mcollective/agent/shell.ddl
PLIST_DIRSTRY=	share/mcollective/agent/shell

NO_BUILD=	yes

do-install:

	@${MKDIR} ${STAGEDIR}${PREFIX}/${PLIST_DIRSTRY}
	${INSTALL_DATA} ${WRKSRC}/lib/mcollective/agent/shell/job.rb ${STAGEDIR}${PREFIX}/share/mcollective/agent/shell/
	${INSTALL_DATA} ${WRKSRC}/lib/mcollective/agent/shell.rb ${STAGEDIR}${PREFIX}/share/mcollective/agent/
	${INSTALL_DATA} ${WRKSRC}/lib/mcollective/agent/shell.ddl ${STAGEDIR}${PREFIX}/share/mcollective/agent/

.include <bsd.port.mk>
