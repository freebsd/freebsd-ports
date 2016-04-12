# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	csso
PORTVERSION=	1.3.9
DISTVERSIONPREFIX=	v
#PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	http://nivit.altervista.org/FreeBSD/ports/distfiles/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	CSS optimizer

LICENSE=	MIT

RUN_DEPENDS=	node:www/node

GH_ACCOUNT=	css

NO_BUILD=	yes

USE_GITHUB=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${INSTALL_DATA} ${WRKSRC}/USAGE ${STAGEDIR}${DATADIR}/USAGE
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${DATADIR}/bin/${PORTNAME}
	${LN} -sf ${DATADIR}/bin/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/lib

.include <bsd.port.mk>
