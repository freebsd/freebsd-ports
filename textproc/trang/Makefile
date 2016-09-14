# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$

PORTNAME=	trang
PORTVERSION=	2009.11.11
CATEGORIES=	textproc java
MASTER_SITES=	http://jing-trang.googlecode.com/files/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Multi-format schema converter based on RELAX NG

LICENSE=	BSD3CLAUSE

BROKEN=		Unfetchable (google code has gone away)

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	copying.txt trang-manual.html

SUB_FILES=	trang.sh
PLIST_FILES=	%%JAVAJARDIR%%/trang.jar bin/trang

.include <bsd.port.options.mk>

do-install:
	${INSTALL_DATA} ${WRKSRC}/trang.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/trang.sh ${STAGEDIR}${PREFIX}/bin/trang
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
