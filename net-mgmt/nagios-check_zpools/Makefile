# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	check_zpools
PORTVERSION=	1.0
CATEGORIES=	net-mgmt
PKGNAMEPREFIX=	nagios-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Nagios plugin that checks zpool state

RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	Napsty
GH_TAGNAME=	0334625
NO_BUILD=	yes
USES=		shebangfix
SHEBANG_FILES=	check_zpools.sh

PLIST_FILES=	libexec/nagios/check_zpools

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_zpools.sh \
		${STAGEDIR}${PREFIX}/libexec/nagios/check_zpools

.include <bsd.port.mk>
