# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Jmol
DISTVERSION=	14.30.0
CATEGORIES=	science java
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}/Version%20${DISTVERSION:R}/${PORTNAME}%20${DISTVERSION}/:src \
		http://${PORTNAME:tl}.svn.sourceforge.net/viewvc/${PORTNAME:tl}/trunk/${PORTNAME}/selfSignedCertificate/:cert
DISTFILES=	${PORTNAME}-${DISTVERSION}-full${EXTRACT_SUFX}:src \
		selfSignedCertificate.cer:cert \
		selfSignedCertificate.store:cert
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-full${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Java 3D viewer for chemical structures

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_JAVA=	yes
USE_ANT=	yes

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:tl}-${DISTVERSION}
SIGN_DIR=	${WRKSRC}/selfSignedCertificate
SUB_FILES=	${EXES}
SUB_LIST=	JAVA=${JAVA}

EXES=		${PORTNAME:tl} ${PORTNAME:tl}data
JARS=		${PORTNAME}.jar ${PORTNAME}Data.jar ${PORTNAME}Lib.jar

PLIST_FILES=	${EXES:S/^/bin\//} \
		${JARS:S/^/${JAVAJARDIR}\//}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

DESKTOP_ENTRIES="${PORTNAME}" "" "" "${PORTNAME:tl}" "" false

post-extract:
	@${MKDIR} ${SIGN_DIR}
	@${CP} ${DISTDIR}/selfSignedCertificate.cer ${SIGN_DIR}
	@${CP} ${DISTDIR}/selfSignedCertificate.store ${SIGN_DIR}

post-patch:
	@${REINPLACE_CMD} 's|<input message="private property file.*||' ${WRKSRC}/build.xml

do-install:
.for exe in ${EXES}
	${INSTALL_SCRIPT} ${WRKDIR}/${exe} ${STAGEDIR}${PREFIX}/bin
.endfor
.for jar in ${JARS}
	${INSTALL_DATA} ${WRKSRC}/build/${jar} ${STAGEDIR}${JAVAJARDIR}
.endfor

do-install-DOCS-on:
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
