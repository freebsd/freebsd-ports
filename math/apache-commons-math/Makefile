PORTNAME=	commons-math
PORTVERSION=	3.6.1
PORTREVISION=	3
CATEGORIES=	math java
MASTER_SITES=	APACHE_COMMONS_SOURCE \
		https://repo1.maven.org/maven2/junit/junit/4.8.2/:source2
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}3-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		junit-4.8.2.jar:source2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Java library of self-contained mathematics and statistics components
WWW=		https://commons.apache.org/proper/commons-math/

LICENSE=	APACHE20

USES=		java:ant,run
USE_LOCALE=	en_US.ISO8859-1

ALL_TARGET=	compile jar
MAKE_ARGS=	-Dlibdir=${WRKDIR} -Dnoget=true

JARFILE=	${PORTNAME:S,3,,}-3.6.jar
DESTJARFILE=	${PORTNAME}.jar
PLIST_FILES+=	${JAVAJARDIR}/${DESTJARFILE}
PORTDOCS=	LICENSE.txt NOTICE.txt RELEASE-NOTES.txt license-header.txt

OPTIONS_DEFINE=	DOCS

DOCS_ALL_TARGET=	javadoc

NO_ARCH=	yes

post-extract:
	${MKDIR} ${WRKSRC}/lib
	${CP} ${DISTDIR}/junit-4.8.2.jar ${WRKSRC}/lib/

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/target/${JARFILE} ${STAGEDIR}${JAVAJARDIR}/${DESTJARFILE}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
