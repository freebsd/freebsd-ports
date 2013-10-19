# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	csso
PORTVERSION=	1.3.9
#PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	http://nivit.altervista.org/FreeBSD/ports/distfiles/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	CSS optimizer

LICENSE=	MIT

RUN_DEPENDS=	node:${PORTSDIR}/www/node

GH_ACCOUNT=	css
GH_COMMIT=	99ae4ad
GH_TAGNAME=	v${PORTVERSION}

NO_BUILD=	yes

USE_GITHUB=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${INSTALL_DATA} ${WRKSRC}/USAGE ${STAGEDIR}${DATADIR}/USAGE
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${DATADIR}/bin/${PORTNAME}
	${LN} -s ${STAGEDIR}${DATADIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/lib

.include <bsd.port.mk>
