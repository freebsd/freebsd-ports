PORTNAME=	xml-commons
DISTVERSION=	1.4.01
PORTREVISION=	1
CATEGORIES=	textproc java
MASTER_SITES=	APACHE/xerces/${PORTNAME}/binaries
DISTNAME=	${PORTNAME}-external-${DISTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides common XML code for Apache projects
WWW=		https://xerces.apache.org/xml-commons/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		java

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}-external-${DISTVERSION}

_JARDIR=	${JAVASHAREDIR}/${PORTNAME}
PLIST_FILES=	${_JARDIR}/xml-apis.jar \
		${_JARDIR}/xml-apis-ext.jar

do-install:
	${MKDIR} ${STAGEDIR}${_JARDIR}
	${INSTALL_DATA} ${WRKSRC}/xml-apis-ext.jar ${STAGEDIR}${_JARDIR}
	${INSTALL_DATA} ${WRKSRC}/xml-apis.jar ${STAGEDIR}${_JARDIR}

.include <bsd.port.mk>
