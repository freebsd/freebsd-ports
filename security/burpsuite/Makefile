# New ports collection makefile for:    Burpsuite
# Date created:				2010-02-22
# Whom:					Niels Heinen
#
# $FreeBSD$
#

PORTNAME=	burpsuite
PORTVERSION=	1.3.03
CATEGORIES=	security java
MASTER_SITES=	http://www.portswigger.net/suite/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	niels@FreeBSD.org
COMMENT=	Burp Suite is an integrated platform for testing web applications

USE_ZIP=	YES
USE_JAVA=	YES
JAVA_VERSION=	1.4+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/${PORTNAME} %%JAVAJARDIR%%/${DISTNAME}.jar

#.if !defined(NOPORTDOCS)
PORTDOCS=	readme_-_running_burp.txt terms_and_conditions.txt
#.endif

.include <bsd.port.pre.mk>

post-extract:
	${MV} ${WRKSRC}/readme\ -\ running\ burp.txt ${WRKSRC}/readme_-_running_burp.txt
	${MV} ${WRKSRC}/terms\ and\ conditions.txt ${WRKSRC}/terms_and_conditions.txt

pre-install:
	@${SED} -e 's:%%PATH%%:${JAVAJARDIR}/:' \
		-e 's:%%JAVA_CMD%%:${JAVA}:' \
		-e 's:%%BURP%%:${JAVAJARDIR}/${DISTNAME}.jar:' \
		< ${FILESDIR}/${PORTNAME}.sh > ${WRKDIR}/${PORTNAME}

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme_-_running_burp.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/terms_and_conditions.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
