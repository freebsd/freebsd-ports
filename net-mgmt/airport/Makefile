# New ports collection makefile for:    airport
# Date created:		2000/09/16
# Whom:			Nick Sayer
#
# $FreeBSD$
#

PORTNAME=	airport
PORTVERSION=	2.0.1
CATEGORIES=	net-mgmt java
MASTER_SITES=	http://edge.mcs.drexel.edu/GICL/people/sevy/airport/
DISTFILES=	configurator_${PORTVERSION:S/.0.1/01/g}${EXTRACT_SUFX} \
		configurator_${OLDAPCVERSION:S/.//g}${EXTRACT_SUFX} \
		link_monitor_${LINKMONVERSION:S/.//}${EXTRACT_SUFX} \
		host_monitor_${HOSTMONVERSION:S/.//}${EXTRACT_SUFX} \
		airportmodemutility_${MODEMVERSION:S/.//}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apple Airport / Lucent RG-1000 configuration program

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

EXTRACT_BEFORE_ARGS=	-q -o

USE_ZIP=	YES
USE_JAVA=	1.2+

NO_WRKSUBDIR=	YES
NO_BUILD=	yes

OLDAPCVERSION=	1.5.2
LINKMONVERSION=	1.1
HOSTMONVERSION=	1.0
MODEMVERSION=	2.0

do-install:
	@cd ${WRKSRC}; \
		${MKDIR} ${PREFIX}/share/doc/airport/helpdocs; \
		${MKDIR} ${PREFIX}/share/java; \
		${INSTALL_DATA} ${WRKSRC}/*jar ${PREFIX}/share/java; \
		${INSTALL_DATA} ${WRKSRC}/configurator_${PORTVERSION:S/.0.1/0/g}/*jar ${PREFIX}/share/java; \
		${INSTALL_DATA} ${WRKSRC}/configurator_${OLDAPCVERSION:S/.//g}/*jar ${PREFIX}/share/java; \
		${INSTALL_DATA} ${WRKSRC}/airportmodemutility_${PORTVERSION:S/.0.1/0/g}/*jar ${PREFIX}/share/java; \
		${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/airport; \
		${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/airport; \
		${INSTALL_DATA} ${WRKSRC}/configurator_${PORTVERSION:S/.0.1/0/g}/helpdocs/* ${PREFIX}/share/doc/airport/helpdocs; \
		${SED} \
			-e s,%%PREFIX%%,${PREFIX},g \
			< ${FILESDIR}/airport > ${PREFIX}/bin/airport; \
		${CHMOD} a+x ${PREFIX}/bin/airport
		${LN} ${PREFIX}/bin/airport ${PREFIX}/bin/airport2
		${LN} ${PREFIX}/bin/airport ${PREFIX}/bin/hostmon
		${LN} ${PREFIX}/bin/airport ${PREFIX}/bin/linkmon
		${LN} ${PREFIX}/bin/airport ${PREFIX}/bin/airmodem

.include <bsd.port.mk>
