# New ports collection makefile for:    airport
# Date created:		2000/09/16
# Whom:			Nick Sayer
#
# $FreeBSD$
#

PORTNAME=	airport
PORTVERSION=	1.5.2
CATEGORIES=	net java
MASTER_SITES=	http://edge.mcs.drexel.edu/GICL/people/sevy/airport/
DISTFILES=	configurator_${PORTVERSION:S/.//g}${EXTRACT_SUFX} \
		link_monitor_${LINKMONVERSION:S/.//}${EXTRACT_SUFX} \
		host_monitor_${HOSTMONVERSION:S/.//}${EXTRACT_SUFX} \
		airportmodemutility_${MODEMVERSION:S/.//}${EXTRACT_SUFX}

MAINTAINER=	ports@freebsd.org

RUN_DEPENDS=	${LOCALBASE}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk \
		${LOCALBASE}/share/java/classes/jfc-${JFC_VERSION}/swingall.jar:${PORTSDIR}/java/jfc \
		${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper

EXTRACT_BEFORE_ARGS=	-q -o

USE_ZIP=	YES

NO_WRKSUBDIR=	YES

JDK_VERSION=	1.1.8
JFC_VERSION=	1.1.1
LINKMONVERSION=	1.1
HOSTMONVERSION=	1.0
MODEMVERSION=	1.4

NO_BUILD=	yes

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC}; \
		${MKDIR} ${PREFIX}/share/doc/airport/helpdocs; \
		${MKDIR} ${PREFIX}/share/java; \
		${INSTALL_DATA} ${WRKSRC}/*jar ${PREFIX}/share/java; \
		${INSTALL_DATA} ${WRKSRC}/configurator_${PORTVERSION:S/.//g}/*jar ${PREFIX}/share/java; \
		${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/airport; \
		${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/airport; \
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/airport; \
		${INSTALL_DATA} ${WRKSRC}/configurator_${PORTVERSION:S/.//g}/helpdocs/* ${PREFIX}/share/doc/airport/helpdocs; \
		${SED} \
			-e s,%%PREFIX%%,${PREFIX},g \
			-e s/%%JFC_VERSION%%/${JFC_VERSION}/ \
			-e s/%%JDK_VERSION%%/${JDK_VERSION}/ \
			< ${FILESDIR}/airport > ${PREFIX}/bin/airport; \
		${CHMOD} a+x ${PREFIX}/bin/airport
		${LN} ${PREFIX}/bin/airport ${PREFIX}/bin/hostmon
		${LN} ${PREFIX}/bin/airport ${PREFIX}/bin/linkmon
		${LN} ${PREFIX}/bin/airport ${PREFIX}/bin/airmodem

.include <bsd.port.post.mk>
