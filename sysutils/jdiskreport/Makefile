# Created by: jon@witchspace.com
# $FreeBSD$

PORTNAME=	jdiskreport
DISTVERSION=	1_4_1
CATEGORIES=	sysutils java
MASTER_SITES=	http://www.jGoodies.com/download/${PORTNAME}/

MAINTAINER=	jon@witchspace.com
COMMENT=	Java program to graphically display disk usage statistics

USES=		zip
USE_JAVA=	YES

PLIST_SUB=	JDISKDIR=${JDISKDIR:S,${PREFIX}/,,g}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
JAVAVM?=	${LOCALBASE}/bin/java
JDISKDIR?=	${PREFIX}/lib/jdiskreport

DESKTOP_ENTRIES="JDiskReport" "${COMMENT}" "" "jdiskreport" \
		"System;Filesystem;" false

do-build:
	@cd ${WRKDIR}
	@${SED} -e 's,%%JDISKDIR%%,${JDISKDIR},g' \
		-e 's,%%PORTVERSION%%,${PORTVERSION},g' \
		-e 's,%%JAVAVM%%,${JAVAVM},g' ${FILESDIR}/jdiskreport.sh \
		> ${WRKDIR}/jdiskreport

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/jdiskreport ${STAGEDIR}${PREFIX}/bin
	-@${MKDIR} ${STAGEDIR}${JDISKDIR}
	@${INSTALL_DATA} ${WRKSRC:S|_|.|g}/jdiskreport-${PORTVERSION}.jar \
		${STAGEDIR}${JDISKDIR}

.include <bsd.port.mk>
