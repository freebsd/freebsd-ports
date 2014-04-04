# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	mcollective-puppet-agent
PORTVERSION=	1.7.0
CATEGORIES=	sysutils

MAINTAINER=	anes@anes.su
COMMENT=	Puppet agent manager for mcollective

RUN_DEPENDS=	mcollective>=2:${PORTSDIR}/sysutils/mcollective

USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	6e565cb

NO_BUILD=	yes

MCOLLECTIVEDIR=	${STAGEDIR}${PREFIX}/share/mcollective

do-install:
	@${MKDIR} ${MCOLLECTIVEDIR}
	@cd ${WRKSRC} && ${PAX} -r -w . ${MCOLLECTIVEDIR}

.include <bsd.port.mk>
