# Created by: rfarmer@predatorlabs.net
# $FreeBSD$

PORTNAME=	jeuclid
PORTVERSION=	3.1.9
CATEGORIES=	math java
MASTER_SITES=	SF/${PORTNAME}/3.1.x/${PORTVERSION}/
EXTRACT_SUFX=	-distribution.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java based MathML rendering solution

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_RUN=	yes
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|BASEDIR=`dirname $$0`/..|BASEDIR=${DATADIR}|g' ${WRKSRC}/bin/foprep
	${REINPLACE_CMD} -e 's|BASEDIR=`dirname $$0`/..|BASEDIR=${DATADIR}|g' ${WRKSRC}/bin/listfonts
	${REINPLACE_CMD} -e 's|BASEDIR=`dirname $$0`/..|BASEDIR=${DATADIR}|g' ${WRKSRC}/bin/mathviewer
	${REINPLACE_CMD} -e 's|BASEDIR=`dirname $$0`/..|BASEDIR=${DATADIR}|g' ${WRKSRC}/bin/mml2xxx

do-install:
	${MKDIR} ${DATADIR}/repo
	(cd ${WRKSRC}/repo/ && ${COPYTREE_SHARE} \* ${DATADIR}/repo/)
	${INSTALL_SCRIPT} ${WRKSRC}/bin/foprep ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/listfonts ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mathviewer ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mml2xxx ${PREFIX}/bin

.include <bsd.port.mk>
