# New ports collection makefile for: The cisco Systems IOS(tm) config register decoder
# Date created:		24 May 2001
# Whom:			Joe Clarke <marcus@marcuscom.com>
#
# $FreeBSD$
#

PORTNAME=	confregdecode
PORTVERSION=	1.0.1
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cosi-nms
DISTNAME=	confregdecode-src-${PORTVERSION}

MAINTAINER=	marcus@FreeBSD.org

USE_JAVA=	1.1+
NEED_JAVAC=	YES
ALL_TARGET=	jar
MAKE_ENV=	JAVAC="${JAVAC}" JAR="${JAR}"

do-install:
	@${MKDIR} ${PREFIX}/share/java
	@${INSTALL_DATA} ${WRKSRC}/confregdecode.jar ${LOCALBASE}/share/java
	@${SED} \
		-e s,%%PREFIX%%,${PREFIX}, \
		-e s,%%LOCALBASE%%,${LOCALBASE}, \
		< ${FILESDIR}/confregdecode > ${PREFIX}/bin/confregdecode; \
	${CHMOD} a+x ${PREFIX}/bin/confregdecode

post-install:
	@${MKDIR} ${PREFIX}/share/doc/confregdecode
	@${INSTALL_DATA} ${WRKSRC}/README.txt ${LOCALBASE}/share/doc/confregdecode
	@${INSTALL_DATA} ${WRKSRC}/ConfregDecode.html ${LOCALBASE}/share/doc/confregdecode

.include <bsd.port.mk>
