# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomcat-native
PORTVERSION=	1.2.7
CATEGORIES=	www java
MASTER_SITES=	APACHE/tomcat/tomcat-connectors/native/${PORTVERSION}/source
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Tomcat native library

LICENSE=	APACHE20

LIB_DEPENDS=	libapr-1.so:devel/apr1

WRKSRC=		${WRKDIR}/${DISTNAME}/native

USES=		libtool
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes
USE_JAVA=	yes
USE_LDCONFIG=	yes
JAVA_VERSION=	1.6+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apr=${LOCALBASE} \
		--with-java-home=${JAVA_HOME} \
		--with-ssl=${OPENSSLBASE}

PLIST_FILES=	lib/libtcnative-1.a \
		lib/libtcnative-1.so \
		lib/libtcnative-1.so.0 \
		lib/libtcnative-1.so.0.2.7

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtcnative-1.so.0.2.7

.include <bsd.port.mk>
