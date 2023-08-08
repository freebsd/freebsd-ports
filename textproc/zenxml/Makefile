PORTNAME=	zenxml
PORTVERSION=	2.5
CATEGORIES=	textproc
MASTER_SITES=	SF/zenxml
DISTNAME=	zenXml_${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple C++ XML Processing
WWW=		https://zenxml.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/zen/ ${STAGEDIR}${PREFIX}/include/zenxml/
	${INSTALL_DATA} ${WRKSRC}/zen/*.h ${STAGEDIR}${PREFIX}/include/zen/
	${INSTALL_DATA} ${WRKSRC}/zenxml/*.h ${STAGEDIR}${PREFIX}/include/zenxml/

.include <bsd.port.mk>
