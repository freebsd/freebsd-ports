# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomcat-native
PORTVERSION=	1.2.16
CATEGORIES=	www java
MASTER_SITES=	APACHE/tomcat/tomcat-connectors/native/${PORTVERSION}/source
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Tomcat native library

LICENSE=	APACHE20

LIB_DEPENDS=	libapr-1.so:devel/apr1

WRKSRC=		${WRKDIR}/${DISTNAME}/native

USES=		libtool ssl
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
		lib/libtcnative-1.so.0.2.16

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtcnative-1.so.0.2.16

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
IGNORE_FreeBSD_10=	Requires OpenSSL 1.0.2 (set DEFAULT_VERSIONS+=ssl=openssl)
.endif

.include <bsd.port.post.mk>
