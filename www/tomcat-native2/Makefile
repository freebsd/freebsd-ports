PORTNAME=	tomcat-native
DISTVERSION=	2.0.7
CATEGORIES=	www java
MASTER_SITES=	https://archive.apache.org/dist/tomcat/tomcat-connectors/native/${PORTVERSION}/source/
PKGNAMESUFFIX=	2
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	michaelo@apache.org
COMMENT=	Tomcat native library
WWW=		https://tomcat.apache.org/native-doc/

LICENSE=	APACHE20

LIB_DEPENDS=	libapr-1.so:devel/apr1

USES=		libtool ssl
USE_JAVA=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apr=${LOCALBASE} \
		--with-java-home=${JAVA_HOME} \
		--with-ssl=${OPENSSLBASE} \
		--disable-openssl-version-check

WRKSRC=	${WRKDIR}/${DISTNAME}/native

SOVERSION=	${PORTVERSION:E}
MAJORVERSION=	${PORTVERSION:R:R}
PLIST_FILES=	lib/libtcnative-${MAJORVERSION}.so \
		lib/libtcnative-${MAJORVERSION}.so.0 \
		lib/libtcnative-${MAJORVERSION}.so.0.0.${SOVERSION}

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libtcnative-${MAJORVERSION}.a
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtcnative-${MAJORVERSION}.so.0.0.${SOVERSION}

.include <bsd.port.mk>
