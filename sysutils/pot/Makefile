# Created by: Luca Pizzamiglio <pizzamig@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pot
PORTVERSION=	0.5.0
CATEGORIES=	sysutils

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Container framework for FreeBSD

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	pizzamig
NO_ARCH=	yes
NO_BUILD=	yes
USE_RC_SUBR=	pot

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/pot \
	    ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	( cd ${WRKSRC}/share/pot && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}/flavours
	${INSTALL_DATA} ${WRKSRC}/etc/pot/pot.default.conf \
		${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/pot/pot.conf.sample \
		${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/pot/flavours/dns.sh \
		${STAGEDIR}${ETCDIR}/flavours

.include <bsd.port.mk>
