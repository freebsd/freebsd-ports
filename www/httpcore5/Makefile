PORTNAME=	httpcore5
DISTVERSION=	5.5-beta2	# Check the compatibility with math/scilab
CATEGORIES=	www java
MASTER_SITES=	https://repo1.maven.org/maven2/org/apache/httpcomponents/core5/httpcore5/${DISTVERSION}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Java components implementing the base HTTP protocol v.5
WWW=		https://hc.apache.org/httpcomponents-core-5.5.x/

LICENSE=	APACHE20

USES=		java:run

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar	\
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
