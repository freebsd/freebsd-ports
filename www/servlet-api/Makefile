PORTNAME=	servlet-api
PORTVERSION=	2.5
PORTREVISION=	3
CATEGORIES=	www java
MASTER_SITES=	https://repo1.maven.org/maven2/javax/servlet/servlet-api/2.5/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Servlet API
WWW=		http://java.sun.com/products/servlet/

DEPRECATED=	Superseded upstream by newer versions many years ago
EXPIRATION_DATE=	2025-12-31

USES=		java

NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${_DISTDIR}/${DISTFILES} \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
