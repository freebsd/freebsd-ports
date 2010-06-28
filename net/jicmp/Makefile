# New ports collection makefile for:	net/jicmp
# Date created:		24 June 2008
# Whom:			Ryan T. Dean <rtdean@cytherianage.net>
#
# $FreeBSD$
#

PORTNAME=	jicmp
PORTVERSION=	1.0.11
CATEGORIES=	net java
MASTER_SITES=	SF/opennms/JICMP/stable-1.0/

MAINTAINER=	rtdean@cytherianage.net
COMMENT=	A Java native interface (JNI) to ICMP (ping)

USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_BUILD=	yes
JAVA_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	automake:19

pre-everything::
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"Installation settings:"
	@${ECHO_MSG}	"   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG}	"   Location of Java port:    ${JAVA_PORT}"
	@${ECHO_MSG}	""

.include <bsd.port.mk>
