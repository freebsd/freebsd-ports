PORTNAME=	trang
PORTVERSION=	20241231
CATEGORIES=	textproc java
MASTER_SITES=	https://github.com/relaxng/jing-trang/releases/download/V${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-format schema converter based on RELAX NG
WWW=		http://www.thaiopensource.com/relaxng/trang.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/copying.txt

BROKEN_armv6=		fails to build: modbuild.xml: Java returned: 1
BROKEN_armv7=		fails to build: modbuild.xml: Java returned: 1

USES=		java zip

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes

PORTDOCS=	trang-manual.html

SUB_FILES=	trang.sh

PLIST_FILES=	bin/trang ${JAVAJARDIR}/trang.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/trang.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/trang.sh ${STAGEDIR}${PREFIX}/bin/trang

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
