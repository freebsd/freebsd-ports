# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	servlet-api
PORTVERSION=	2.5
PORTREVISION=	4
CATEGORIES=	www java
MASTER_SITES=	http://maven.ibiblio.org/maven2/javax/servlet/servlet-api/2.5/ \
		http://repo1.maven.org/maven2/javax/servlet/servlet-api/2.5/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Servlet API

LICENSE=	CDDL GPLv2wCE
LICENSE_COMB=	multi
LICENSE_NAME_GPLv2wCE=	GPLv2 with Classpath Exception
LICENSE_PERMS_GPLv2wCE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${_DISTDIR}/${DISTFILES} \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
