# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	acts
PORTVERSION=	1.0
CATEGORIES=	sysutils archivers

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Another Calendar-based Tarsnap Script

USE_GITHUB=	yes
GH_ACCOUNT=	alexjurkiewicz

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/acts ${STAGEDIR}/${PREFIX}/bin/acts
	${INSTALL_DATA} ${WRKSRC}/acts.conf ${STAGEDIR}/${PREFIX}/etc/acts.conf.sample

.include <bsd.port.mk>
