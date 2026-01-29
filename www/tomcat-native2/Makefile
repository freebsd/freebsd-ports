PORTNAME=	tomcat-native
DISTVERSION=	2.0.12
CATEGORIES=	www java
MASTER_SITES=	https://archive.apache.org/dist/tomcat/tomcat-connectors/native/${PORTVERSION}/source/
PKGNAMESUFFIX=	2
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	michaelo@apache.org
COMMENT=	Tomcat native library
WWW=		https://tomcat.apache.org/native-doc/

LICENSE=	APACHE20

IGNORE_FreeBSD_13=		Does not build on FreeBSD 13.x due to OpenSSL 1.1.1

LIB_DEPENDS=	libapr-1.so:devel/apr1

USES=		java libtool ssl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apr=${LOCALBASE} \
		--with-java-home=${JAVA_HOME} \
		--with-ssl=${OPENSSLBASE} \

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
