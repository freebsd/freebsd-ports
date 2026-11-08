PORTNAME=	httpclient5
DISTVERSION=	5.6.2	# Check the compatibility with math/scilab
CATEGORIES=	www java
MASTER_SITES=	https://repo1.maven.org/maven2/org/apache/httpcomponents/client5/httpclient5/${DISTVERSION}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Java components implementing the client side HTTP services v5
WWW=		https://hc.apache.org/httpcomponents-client-5.6.x/

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
