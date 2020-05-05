# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomcat-native
PORTVERSION=	1.2.24
CATEGORIES=	www java
MASTER_SITES=	APACHE/tomcat/tomcat-connectors/native/${PORTVERSION}/source
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Tomcat native library

LICENSE=	APACHE20

LIB_DEPENDS=	libapr-1.so:devel/apr1

USES=		libtool ssl
USE_JAVA=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apr=${LOCALBASE} \
		--with-java-home=${JAVA_HOME} \
		--with-ssl=${OPENSSLBASE}

WRKSRC=	${WRKDIR}/${DISTNAME}/native

SOVERSION=	${PORTVERSION:S/^1.//1}
PLIST_FILES=	lib/libtcnative-1.a \
		lib/libtcnative-1.so \
		lib/libtcnative-1.so.0 \
		lib/libtcnative-1.so.0.${SOVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtcnative-1.so.0.${SOVERSION}

.include <bsd.port.mk>
