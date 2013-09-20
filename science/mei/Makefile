# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	mei
PORTVERSION=	1.0.3
CATEGORIES=	science parallel
MASTER_SITES=	http://research.edf.com/fichiers/fckeditor/Commun/Innovation/logiciels/code_saturne/Releases/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Mathematical Expression Interpreter

LICENSE=	LGPL21

LIB_DEPENDS=	bft.1:${PORTSDIR}/science/bft
BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_ZIP=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bft=${LOCALBASE}

MAN1=		mei-config.1

.if defined(MAINTAINER_MODE)
NO_STAGE=	yes
regression-test:
	(cd ${WRKSRC}/tests &&	\
	${MAKE} check &&	\
	./mei_test )
.endif

.include <bsd.port.mk>
