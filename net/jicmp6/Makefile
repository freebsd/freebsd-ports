PORTNAME=	jicmp6
PORTVERSION=	1.2.3
CATEGORIES=	net java
MASTER_SITES=	SF/opennms/JICMP6/stable-1.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java native interface (JNI) to ICMPv6
WWW=		https://www.opennms.org/wiki/Jicmp

USES=		java libtool
JAVA_VERSION=	8
JAVA_VENDOR=	openjdk

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}

PLIST_FILES=	lib/libjicmp6.so \
		share/java/jicmp6.jar

.include <bsd.port.mk>
