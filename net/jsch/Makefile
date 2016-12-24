# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jsch
PORTVERSION=	0.1.54
CATEGORIES=	net java security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure Java implementation of SSH2

LICENSE=	BSD3CLAUSE

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes

PLIST_FILES+=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/lib/*.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
