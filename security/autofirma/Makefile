PORTNAME=	autofirma
DISTVERSION=	1.9
CATEGORIES=	security
MASTER_SITES=	https://firmaelectronica.gob.es/content/dam/firmaelectronica/descargas-software/autofirma19/
DISTNAME=	Autofirma_Linux_Debian

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Spanish Government digital signature application
WWW=		https://sedediatid.digital.gob.es/es-es/firmaelectronica/Paginas/AutoFirma.aspx

LICENSE=	GPLv2 EUPL11
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/usr/share/common-licenses/eupl-1.1.txt

LIB_DEPENDS=	libnss3.so:security/nss

USES=		desktop-file-utils java zip
JAVA_VERSION=	24
JAVA_VENDOR=	openjdk

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

NO_BUILD=	yes

SUB_FILES=	${PORTNAME} \
		Autofirma.js \
		afirma.desktop \
		pkg-message
SUB_LIST+=	JAVA_HOME=${JAVA_HOME} \
		JAVA=${JAVA}

WRKSRC=${WRKDIR}

post-extract:
	${TAR} -C ${WRKDIR} -xvzf ${WRKDIR}/autofirma_1_9.deb
	${TAR} -C ${WRKDIR} -xvzf ${WRKDIR}/data.tar.gz
	${ZIP_CMD} -d ${PORTNAME}.jar "nss/WINDOWS/*" "windows/*" "osx/*" "linux/*"

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/usr/lib/Autofirma/autofirma.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/usr/lib/Autofirma/Autofirma.png ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/afirma.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKDIR}/Autofirma.js ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
