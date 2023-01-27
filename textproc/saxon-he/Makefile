PORTNAME=	saxon-he
DISTVERSION=	10-6
CATEGORIES=	textproc java
MASTER_SITES=	SF/saxon/Saxon-HE/${PORTVERSION:R}/Java/
DISTNAME=	SaxonHE${DISTVERSION}J

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	XSLT 3.0 / XPath 3.1 / XQuery 3.1 processor for Java
WWW=		https://www.saxonica.com/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/notices/LICENSE.txt

USES=		zip
USE_JAVA=	yes
NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes

JARFILES=	jline-2.14.6.jar \
		saxon-he-10.6.jar \
		saxon-he-test-10.6.jar
PLIST_FILES=	${JARFILES:S,^,%%JAVAJARDIR%%/,}

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${JARFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
