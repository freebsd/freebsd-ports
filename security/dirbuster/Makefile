# Created by: Niels Heinen
# $FreeBSD$

PORTNAME=	dirbuster
PORTVERSION=	1.0r1
CATEGORIES=	security java
MASTER_SITES=	SF/${PORTNAME}/DirBuster%20%28jar%20%2B%20lists%29/1.0-RC1/
DISTNAME=	DirBuster-1.0-RC1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DirBuster allows file and directory brute forcing on web servers

LICENSE=	LGPL21+ CC-BY-SA-3.0
LICENSE_COMB=	multi

USES=		zip
USE_JAVA=	yes
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

post-extract:
	@${RM} ${WRKSRC}/${DISTNAME}.sh
	@${RM} ${WRKSRC}/${DISTNAME}.bat

pre-install:
	@${SED} -e 's:%%PATH%%:${DATADIR}/:' \
		-e 's:%%JAVA_CMD%%:${JAVA}:' \
		-e 's:%%DIRBUSTER%%:${DATADIR}/${DISTNAME}.jar:' \
		< ${FILESDIR}/${PORTNAME}.sh > ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
