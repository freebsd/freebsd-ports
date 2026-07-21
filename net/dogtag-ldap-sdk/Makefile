PORTNAME=	dogtag-ldap-sdk
DISTVERSIONPREFIX=	v
DISTVERSION=	5.6.0
CATEGORIES=	net java

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Dogtag LDAP SDK for Java
WWW=		https://github.com/dogtagpki/ldap-sdk

LICENSE=	GPLv2+ LGPL21+ MPL11
LICENSE_COMB=	dual

BUILD_DEPENDS=	${JAVAJARDIR}/jss.jar:security/dogtag-jss \
		${JAVAJARDIR}/slf4j-api.jar:devel/slf4j
RUN_DEPENDS=	${JAVAJARDIR}/jss.jar:security/dogtag-jss \
		${JAVAJARDIR}/slf4j-api.jar:devel/slf4j

USES=		java:ant,run
USE_GITHUB=	yes
GH_ACCOUNT=	dogtagpki
GH_PROJECT=	ldap-sdk

JAVA_VERSION=	17

MAKE_ARGS=	-Djss.lib=${JAVAJARDIR}/jss.jar \
		-Dslf4j.lib=${JAVAJARDIR}/slf4j-api.jar
ALL_TARGET=	dist-jdk

NO_ARCH=	yes

BUILD_WRKSRC=	${WRKSRC}/java-sdk

PLIST_FILES=	${JAVAJARDIR}/ldapjdk.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/dist/packages/ldapjdk.jar ${STAGEDIR}${JAVAJARDIR}/ldapjdk.jar

.include <bsd.port.mk>
