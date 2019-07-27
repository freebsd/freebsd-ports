# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	acts
PORTVERSION=	1.4.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils archivers

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Another Calendar-based Tarsnap Script

LICENSE=	PD

RUN_DEPENDS=	tarsnap>=0:sysutils/tarsnap

USE_GITHUB=	yes
GH_ACCOUNT=	alexjurkiewicz

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/acts ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/acts.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
