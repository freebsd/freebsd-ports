# New ports collection makefile for:    airport
# Date created:		2000/09/16
# Whom:			Nick Sayer
#
# $FreeBSD$
#

PORTNAME=	airport
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	net java
MASTER_SITES=	http://edge.mcs.drexel.edu/GICL/people/sevy/airport/
DISTFILES=	configurator_${PORTVERSION:S/.//}${EXTRACT_SUFX}

MAINTAINER=	nsayer@freebsd.org

RUN_DEPENDS=	${LOCALBASE}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk \
		${LOCALBASE}/share/java/classes/jfc-${JFC_VERSION}/swingall.jar:${PORTSDIR}/java/jfc \
		${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper

USE_ZIP=	YES

NO_WRKSUBDIR=	YES

JDK_VERSION=	1.1.8
JFC_VERSION=	1.1.1

NO_BUILD=	yes

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC}; \
		${MKDIR} ${PREFIX}/share/doc/airport/helpdocs; \
		${MKDIR} ${PREFIX}/share/java; \
		${INSTALL_DATA} ${WRKSRC}/*jar ${PREFIX}/share/java; \
		${CP} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/airport; \
		${CP} ${WRKSRC}/COPYING ${PREFIX}/share/doc/airport; \
		${CP} -r ${WRKSRC}/helpdocs/* ${PREFIX}/share/doc/airport/helpdocs; \
		${SED} \
			-e s,%%PREFIX%%,${PREFIX},g \
			-e s/%%JFC_VERSION%%/${JFC_VERSION}/ \
			-e s/%%JDK_VERSION%%/${JDK_VERSION}/ \
			< ${FILESDIR}/airport > ${PREFIX}/bin/airport; \
		${CHMOD} a+x ${PREFIX}/bin/airport

.include <bsd.port.post.mk>
