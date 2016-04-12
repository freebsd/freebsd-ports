# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	acts
PORTVERSION=	1.2
PORTREVISION=	0
CATEGORIES=	sysutils archivers

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Another Calendar-based Tarsnap Script

RUN_DEPENDS=	tarsnap>=0:sysutils/tarsnap

USE_GITHUB=	yes
GH_ACCOUNT=	alexjurkiewicz

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/acts ${STAGEDIR}/${PREFIX}/bin/acts
	${INSTALL_DATA} ${WRKSRC}/acts.conf.sample ${STAGEDIR}/${PREFIX}/etc/acts.conf.sample

.include <bsd.port.mk>
