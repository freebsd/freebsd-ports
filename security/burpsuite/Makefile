# Created by: Niels Heinen
# $FreeBSD$

PORTNAME=	burpsuite
PORTVERSION=	1.5
CATEGORIES=	security java
MASTER_SITES=	http://www.portswigger.net/burp/ \
		LOCAL/sbz
DISTNAME=	${PORTNAME}_free_v${PORTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Burp Suite is an integrated platform for testing web applications

USE_JAVA=	yes
NO_BUILD=	yes
JAVA_VERSION=	1.7
JAVA_VENDOR=	openjdk
WRKSRC=		${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		%%JAVAJARDIR%%/${DISTNAME}.jar

NO_STAGE=	yes
.include <bsd.port.pre.mk>

# Get BSFEL agreement
.if !defined(PACKAGE_BUILDING)
pre-extract:
	@${SH} ${FILESDIR}/license.sh
.endif

post-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}/

pre-install:
	@${SED} -e 's:%%PATH%%:${JAVAJARDIR}/:' \
		-e 's:%%JAVA_CMD%%:${JAVA}:' \
		-e 's:%%BURP%%:${JAVAJARDIR}/${DISTNAME}.jar:' \
		< ${FILESDIR}/${PORTNAME}.sh > ${WRKDIR}/${PORTNAME}

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
