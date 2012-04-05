# New ports collection makefile for:    Burpsuite
# Date created:				2010-02-22
# Whom:					Niels Heinen
#
# $FreeBSD$
#

PORTNAME=	burpsuite
PORTVERSION=	1.4.01
CATEGORIES=	security java
MASTER_SITES=	http://www.portswigger.net/burp/ \
		${MASTER_SITE_LOCAL:S,%SUBDIR%,sbz,}
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Burp Suite is an integrated platform for testing web applications

USE_ZIP=	YES
USE_JAVA=	YES
JAVA_VERSION=	1.5+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		%%JAVAJARDIR%%/${DISTNAME}.jar

PORTDOCS=	readme_-_running_burp.txt

.include <bsd.port.pre.mk>

# Get BSFEL agreement
.if !defined(PACKAGE_BUILDING)
pre-extract:
	@${SH} ${FILESDIR}/license.sh
.endif

post-extract:
	@${MV} ${WRKSRC}/readme\ -\ running\ burp.txt ${WRKSRC}/readme_-_running_burp.txt

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
.endif

.include <bsd.port.post.mk>
