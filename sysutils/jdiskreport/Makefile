# New ports collection makefile for:	jdiskreport
# Date created:				26th May 2003
# Whom:					jon@witchspace.com
#
# $FreeBSD$
#

PORTNAME=	jdiskreport
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	sysutils java
MASTER_SITES=	http://www.jGoodies.com/download/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION:S,.,_,g}

MAINTAINER=	jon@witchspace.com
COMMENT=	Java program to graphically display disk usage statistics

RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/javavmwrapper

USE_ZIP=	YES
USE_JAVA=	1.3

PLIST_SUB=	JDISKDIR=${JDISKDIR:S,${PREFIX}/,,g}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
JAVAVM?=	${LOCALBASE}/bin/javavm
JDISKDIR?=	${PREFIX}/lib/jdiskreport

do-build:
	@cd ${WRKDIR}
	@${SED} -e 's,%%JDISKDIR%%,${JDISKDIR},g' \
		-e 's,%%PORTVERSION%%,${PORTVERSION},g' \
		-e 's,%%JAVAVM%%,${JAVAVM},g' ${FILESDIR}/jdiskreport.sh \
		> ${WRKDIR}/jdiskreport

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/jdiskreport ${PREFIX}/bin
	-@${MKDIR} ${JDISKDIR}
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/jdiskreport-${PORTVERSION}.jar ${JDISKDIR}

.include <bsd.port.mk>
