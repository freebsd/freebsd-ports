# New ports collection makefile for: The cisco Systems IOS(tm) config register decoder
# Date created:		24 May 2001
# Whom:			Joe Clarke <marcus@marcuscom.com>
#
# $FreeBSD$
#

PORTNAME=	confregdecode
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	net-mgmt java
MASTER_SITES=	SF/cosi-nms/${PORTNAME}/${PORTVERSION}
DISTNAME=	confregdecode-src-${PORTVERSION}

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Cisco Systems IOS(tm) configuration register decoder

USE_JAVA=	yes
ALL_TARGET=	jar
MAKE_ENV=	JAVAC="${JAVAC}" JAR="${JAR}"
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	confregdecode

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/confregdecode.jar ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/confregdecode ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in README.txt ConfregDecode.html
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
