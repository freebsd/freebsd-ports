# New ports collection makefile for:    airport
# Date created:		2000/09/16
# Whom:			Nick Sayer
#
# $FreeBSD$
#

PORTNAME=	airport
PORTVERSION=	1.0
CATEGORIES=	net java
MASTER_SITES=	http://edge.mcs.drexel.edu/GICL/people/sevy/airport/
DISTFILES=	configurator${EXTRACT_SUFX} swing${EXTRACT_SUFX}

MAINTAINER=	nsayer@freebsd.org

RUN_DEPENDS=    ${LOCALBASE}/jre${JDK_VERSION}/bin/jre:${PORTSDIR}/java/jre

USE_ZIP=	YES

NO_WRKSUBDIR=	YES

JDK_VERSION=	1.1.8

NO_BUILD=	yes

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC}; \
		${MKDIR} ${PREFIX}/share/airport; \
		${CP} -r ${WRKSRC}/* ${PREFIX}/share/airport; \
		${SED} -e s,%%PREFIX%%,${PREFIX}, -e s/%%JDK_VERSION%%/${JDK_VERSION}/ < ${FILESDIR}/airport > ${PREFIX}/bin/airport; \
		${CHMOD} a+x ${PREFIX}/bin/airport

.include <bsd.port.post.mk>
