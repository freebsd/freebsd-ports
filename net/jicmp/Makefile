# Created by: Ryan T. Dean <rtdean@cytherianage.net>

PORTNAME=	jicmp
PORTVERSION=	1.4.4
CATEGORIES=	net java
MASTER_SITES=	SF/opennms/JICMP/stable-1.4/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java native interface (JNI) to ICMP (ping)

WRKSRC=		${WRKDIR}/jicmp-${PORTVERSION}

USES=		libtool
USE_JAVA=	yes
JAVA_VENDOR=	openjdk
JAVA_BUILD=	yes
JAVA_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

pre-everything::
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"Installation settings:"
	@${ECHO_MSG}	"   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG}	"   Location of Java port:    ${JAVA_PORT}"
	@${ECHO_MSG}	""

.include <bsd.port.mk>
