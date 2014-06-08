# Created by: Joe Clarke <marcus@marcuscom.com>
# $FreeBSD$

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

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/confregdecode.jar ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/confregdecode ${STAGEDIR}${PREFIX}/bin

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in README.txt ConfregDecode.html
	${INSTALL_MAN} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
