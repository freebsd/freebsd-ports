# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffdec
PORTVERSION=	8.0.1
CATEGORIES=	multimedia java
MASTER_SITES=	http://www.free-decompiler.com/flash/download/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Flash decompiler

LICENSE=	GPLv3+

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.8
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${STAGEDIR}${DATADIR}
	@${MKDIR}  ${STAGEDIR}${DATADIR}/lib
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/lib/

.include <bsd.port.mk>
