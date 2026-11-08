PORTNAME=	jlatexmath
PORTVERSION=	1.0.7
PORTREVISION=	3
CATEGORIES=	math java
MASTER_SITES=	https://repo1.maven.org/maven2/org/scilab/forge/jlatexmath/${PORTVERSION}/:0 \
		https://repo1.maven.org/maven2/org/scilab/forge/jlatexmath-fop/${PORTVERSION}/:1 \
		https://repo1.maven.org/maven2/org/scilab/forge/jlatexmath-font-cyrillic/${PORTVERSION}/:2 \
		https://repo1.maven.org/maven2/org/scilab/forge/jlatexmath-font-greek/${PORTVERSION}/:3
DISTFILES=	${PORTNAME}-${PORTVERSION}.jar:0 \
		${PORTNAME}-fop-${PORTVERSION}.jar:1 \
		${PORTNAME}-font-cyrillic-${PORTVERSION}.jar:2 \
		${PORTNAME}-font-greek-${PORTVERSION}.jar:3
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java API to display mathematical formulas written in LaTeX
WWW=		https://wiki.scilab.org/JLaTeXMath

LICENSE=	GPLv2

RUN_DEPENDS=	${JAVALIBDIR}/xmlgraphics-commons.jar:graphics/xmlgraphics-commons

USES=		java:run

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION}

do-install:
.for f in jlatexmath jlatexmath-fop jlatexmath-font-cyrillic jlatexmath-font-greek
	${INSTALL_DATA} ${DISTDIR}/${f}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}
	${LN} -sf ${f}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${f}.jar
.endfor

.include <bsd.port.mk>
