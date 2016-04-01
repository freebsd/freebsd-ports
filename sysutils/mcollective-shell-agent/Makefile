# Created by: Bartek Rutkowski <robak@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mcollective-shell-agent
PORTVERSION=	0.0.2
CATEGORIES=	sysutils

MAINTAINER=	robak@FreeBSD.org
COMMENT=	MCollective shell agent plugin

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	mcollective>=2.2.4:sysutils/mcollective

USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs

PLIST_FILES=	share/mcollective/agent/shell/job.rb \
		share/mcollective/agent/shell.rb \
		share/mcollective/agent/shell.ddl
PLIST_DIRS=	share/mcollective/agent/shell

NO_BUILD=	yes

do-install:

	@${MKDIR} ${STAGEDIR}${PREFIX}/${PLIST_DIRS}
	${INSTALL_DATA} ${WRKSRC}/lib/mcollective/agent/shell/job.rb ${STAGEDIR}${PREFIX}/share/mcollective/agent/shell/
	${INSTALL_DATA} ${WRKSRC}/lib/mcollective/agent/shell.rb ${STAGEDIR}${PREFIX}/share/mcollective/agent/
	${INSTALL_DATA} ${WRKSRC}/lib/mcollective/agent/shell.ddl ${STAGEDIR}${PREFIX}/share/mcollective/agent/

.include <bsd.port.mk>
