# $FreeBSD$

PORTNAME=	mkdesktop
PORTVERSION=	1.8
CATEGORIES=	sysutils

MAINTAINER=	bourne.identity@hotmail.com
COMMENT=	Powerful, flexible utility to setup a FreeBSD desktop

RUN_DEPENDS=	pkg>0:ports-mgmt/pkg

USE_GITHUB=	yes
GH_ACCOUNT=	bourne-again

NO_BUILD=	yes
NO_ARCH=	yes

DATA1=		stage-definitions
DATA2=		mkdesktop.help
PLIST_FILES=	bin/${PORTNAME} ${DATADIR}/${DATA1} ${DATADIR}/${DATA2}

do-install:
		${MKDIR} ${STAGEDIR}${DATADIR}
		${INSTALL_DATA} ${WRKSRC}/${DATA1} ${STAGEDIR}${DATADIR}
		${INSTALL_DATA} ${WRKSRC}/${DATA2} ${STAGEDIR}${DATADIR}
		${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
