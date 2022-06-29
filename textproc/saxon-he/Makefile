# Created by: Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>

PORTNAME=	saxon-he
PORTVERSION=	9.5.1.5
CATEGORIES=	textproc java
MASTER_SITES=	SF/saxon/Saxon-HE/${PORTVERSION:R:R}
DISTNAME=	SaxonHE${PORTVERSION:S,.,-,g}J

MAINTAINER=	makc@FreeBSD.org
COMMENT=	XSLT 2.0 / XPath 2.0 / XQuery 1.0 processor for Java

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/notices/LICENSE.txt

USES=		zip
USE_JAVA=	yes
NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes

JARFILES=	saxon9-unpack.jar \
		saxon9-xqj.jar \
		saxon9he.jar
PLIST_FILES=	${JARFILES:S,^,%%JAVAJARDIR%%/,}

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${JARFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
