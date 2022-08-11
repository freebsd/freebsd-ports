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
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/confregdecode.jar ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/confregdecode ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in README.txt ConfregDecode.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
