# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jsch
PORTVERSION=	0.1.49
CATEGORIES=	net java security
MASTER_SITES=	SF

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A pure Java implementation of SSH2

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes

PLIST_FILES+=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${INSTALL_DATA} ${WRKSRC}/dist/lib/*.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
