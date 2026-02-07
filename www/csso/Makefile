PORTNAME=	csso
PORTVERSION=	1.3.9
DISTVERSIONPREFIX=	v
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://nivit.altervista.org/FreeBSD/ports/distfiles/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	CSS optimizer
WWW=		https://github.com/css/csso/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.txt

USES=		nodejs:run
USE_GITHUB=	yes
GH_ACCOUNT=	css

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${INSTALL_DATA} ${WRKSRC}/USAGE ${WRKSRC}/VERSION ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${DATADIR}/bin/${PORTNAME}
	${LN} -sf ${DATADIR}/bin/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/lib

.include <bsd.port.mk>
