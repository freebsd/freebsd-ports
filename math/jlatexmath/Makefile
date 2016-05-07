# Created by: rfarmer@predatorlabs.net
# $FreeBSD$

PORTNAME=	jlatexmath
PORTVERSION=	1.0.3
CATEGORIES=	math java
MASTER_SITES=	http://forge.scilab.org/upload/jlatexmath/files/
DISTNAME=	${PORTNAME}-src-all-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Java API to display mathematical formulas written in LaTeX

LICENSE=	GPLv2

USES=		zip
USE_JAVA=	yes
JAVA_BUILD=	yes
JAVA_RUN=	yes
USE_ANT=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	FOP EXAMPLES
OPTIONS_DEFAULT=	FOP
OPTIONS_SUB=	yes

FOP_DESC=		textproc/fop plugin (required for math/scilab)
FOP_BUILD_DEPENDS=	fop:textproc/fop \
			${JAVALIBDIR}/xmlgraphics-commons.jar:graphics/xmlgraphics-commons
FOP_RUN_DEPENDS:=	${FOP_BUILD_DEPENDS} \
			${JAVASHAREDIR}/batik/batik.jar:graphics/batik \
			${JAVALIBDIR}/avalon-framework.jar:devel/avalon-framework \
			${JAVALIBDIR}/commons-io.jar:devel/jakarta-commons-io \
			${JAVALIBDIR}/commons-logging.jar:java/jakarta-commons-logging \
			${JAVALIBDIR}/xml-apis-ext.jar:textproc/xml-commons
FOP_ALL_TARGET=		fop

post-patch:
	${REINPLACE_CMD} -e 's|/usr/share/java/fop.jar|${LOCALBASE}/share/java/fop/build/fop.jar|' ${WRKSRC}/fop.properties
	${REINPLACE_CMD} -e 's|/usr/share/java/batik.jar|${LOCALBASE}/share/java/batik/batik.jar|' ${WRKSRC}/fop.properties
	${REINPLACE_CMD} -e 's|/usr/share/java/|${JAVALIBDIR}/|' ${WRKSRC}/fop.properties

pre-install:
# Remove empty directory
	-${RMDIR} ${WRKSRC}/examples/Macros/bin

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/jlatexmath-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/jlatexmath.jar

do-install-EXAMPLES-on:
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

do-install-FOP-on:
	${INSTALL_DATA} ${WRKSRC}/dist/jlatexmath-fop-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/jlatexmath-fop.jar

.include <bsd.port.mk>
