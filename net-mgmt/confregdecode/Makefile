# New ports collection makefile for: The cisco Systems IOS(tm) config register decoder
# Date created:		24 May 2001
# Whom:			Joe Clarke <marcus@marcuscom.com>
#
# $FreeBSD$
#

PORTNAME=	confregdecode
PORTVERSION=	1.2.1
CATEGORIES=	net-mgmt java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cosi-nms
DISTNAME=	confregdecode-src-${PORTVERSION}

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Cisco Systems IOS(tm) configuration register decoder

USE_JAVA=	1.1+
NEED_JAVAC=	YES
ALL_TARGET=	jar
MAKE_ENV=	JAVAC="${JAVAC}" JAR="${JAR}"

do-install:
	${MKDIR} ${PREFIX}/share/java
	${INSTALL_DATA} ${WRKSRC}/confregdecode.jar ${PREFIX}/share/java
	${SED} \
		-e s,%%PREFIX%%,${PREFIX}, \
		-e s,%%LOCALBASE%%,${LOCALBASE}, \
		< ${FILESDIR}/confregdecode > ${WRKSRC}/confregdecode; \
	${INSTALL_SCRIPT} ${WRKSRC}/confregdecode ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in README.txt ConfregDecode.html
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
