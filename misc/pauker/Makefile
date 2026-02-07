PORTNAME=	pauker
DISTVERSION=	1.8
CATEGORIES=	misc education java
MASTER_SITES=	SF
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java-based flashcard learning using the Leitner system
WWW=		https://pauker.sourceforge.net

USES=		java

NO_BUILD=	yes

do-install:
	@${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/pauker.jar
	@${PRINTF} "#!/bin/sh\nexec \"${JAVA}\" -jar \"${JAVAJARDIR}/pauker.jar\" \"\$$@\"\n" > ${WRKDIR}/pauker
	@${INSTALL_SCRIPT} ${WRKDIR}/pauker ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
