# Created by: Christer Edwards <christer.edwards@gmail.com>
# $FreeBSD$

PORTNAME=	bastille
PORTVERSION=	0.4.20191025
CATEGORIES=	sysutils

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Jail automation framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	bastillebsd
GH_TAGNAME=	973c2bc

NO_BUILD=	yes
NO_ARCH=	yes

USE_RC_SUBR=	bastille

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PREFIX}/bin/bastille ${STAGEDIR}${PREFIX}/bin

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/${DATADIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/${ETCDIR}/bastille.conf ${STAGEDIR}${ETCDIR}/bastille.conf.sample

.include <bsd.port.mk>
