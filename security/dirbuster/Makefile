# Created by: Niels Heinen
# $FreeBSD$

PORTNAME=	dirbuster
PORTVERSION=	1.0r1
CATEGORIES=	security java
MASTER_SITES=	SF/${PORTNAME}/DirBuster%20%28jar%20%2B%20lists%29/1.0-RC1/
DISTNAME=	DirBuster-1.0-RC1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DirBuster allows file and directory brute forcing on web servers

USES=		zip
USE_JAVA=	YES
JAVA_VERSION=	1.6+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-extract:
	${RM} ${WRKSRC}/${DISTNAME}.sh
	${RM} ${WRKSRC}/${DISTNAME}.bat

pre-install:
	@${SED} -e 's:%%PATH%%:${DATADIR}/:' \
		-e 's:%%JAVA_CMD%%:${JAVA}:' \
		-e 's:%%DIRBUSTER%%:${DATADIR}/${DISTNAME}.jar:' \
		< ${FILESDIR}/${PORTNAME}.sh > ${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/* ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
