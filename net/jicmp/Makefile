PORTNAME=	jicmp
PORTVERSION=	1.4.4
PORTREVISION=	3
CATEGORIES=	net java
MASTER_SITES=	SF/opennms/JICMP/stable-1.4/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java native interface (JNI) to ICMP (ping)
WWW=		https://www.opennms.org/index.php/Jicmp

DEPRECATED=	several years behind on upstream, no maintainer, moved to https://github.com/OpenNMS/jicmp
EXPIRATION_DATE=	2026-07-28

WRKSRC=		${WRKDIR}/jicmp-${PORTVERSION}

USES=		java libtool
JAVA_VERSION=	8
JAVA_VENDOR=	openjdk
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}

INSTALL_TARGET=	install-strip

pre-everything::
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"Installation settings:"
	@${ECHO_MSG}	"   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG}	"   Location of Java port:    ${JAVA_PORT}"
	@${ECHO_MSG}	""

.include <bsd.port.mk>
