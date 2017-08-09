# New ports collection makefile for: ghostbsd packages build server settings
# Date created:        6 dec 2015
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	gbsdbserver
PORTVERSION=	1.1
CATEGORIES=	ports-mgmt

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD packages build server settings

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

RUN_DEPENDS=	poudriere:${PORTSDIR}/ports-mgmt/poudriere \
		portmaster:${PORTSDIR}/ports-mgmt/portmaster \
		nginx:${PORTSDIR}/www/nginx

NO_BUILD=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${STAGEDIR}/${PREFIX}/bin
.include <bsd.port.mk>
