# Created by: Ryan T. Dean <rtdean@cytherianage.net>
# $FreeBSD$

PORTNAME=	jicmp
PORTVERSION=	1.4.1
CATEGORIES=	net java
MASTER_SITES=	SF/opennms/JICMP/stable-1.4/

MAINTAINER=	venture37@geeklan.co.uk
COMMENT=	Java native interface (JNI) to ICMP (ping)

WRKSRC=		${WRKDIR}/jicmp-${PORTVERSION}

USE_JAVA=	yes
JAVA_VERSION=	1.6
JAVA_VENDOR=	openjdk
JAVA_BUILD=	yes
JAVA_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}
USE_LDCONFIG=	yes

pre-everything::
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"Installation settings:"
	@${ECHO_MSG}	"   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG}	"   Location of Java port:    ${JAVA_PORT}"
	@${ECHO_MSG}	""

.include <bsd.port.mk>
