# Created by: Alex Stangl <alex@stangl.us>
# $FreeBSD$

PORTNAME=	pauker
DISTVERSION=	1.8
CATEGORIES=	misc java
MASTER_SITES=	SF
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	alex@stangl.us
COMMENT=	Java-based flashcard learning using the Leitner system

USE_JAVA=	yes
NO_BUILD=	yes

do-install:
	@${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/pauker.jar
	@${PRINTF} "#!/bin/sh\nexec \"${JAVA}\" -jar \"${JAVAJARDIR}/pauker.jar\" \"\$$@\"\n" > ${WRKDIR}/pauker
	@${INSTALL_SCRIPT} ${WRKDIR}/pauker ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
