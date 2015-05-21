# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	acts
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	sysutils archivers

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Another Calendar-based Tarsnap Script

RUN_DEPENDS=	tarsnap>=0:${PORTSDIR}/sysutils/tarsnap

USE_GITHUB=	yes
GH_ACCOUNT=	alexjurkiewicz

NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} 's|ionice -c3 tarsnap|${LOCALBASE}/bin/tarsnap|' ${WRKSRC}/acts.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/acts ${STAGEDIR}/${PREFIX}/bin/acts
	${INSTALL_DATA} ${WRKSRC}/acts.conf ${STAGEDIR}/${PREFIX}/etc/acts.conf.sample

.include <bsd.port.mk>
