# Created by: rfarmer@predatorlabs.net
# $FreeBSD$

PORTNAME=	jlatexmath
PORTVERSION=	0.9.7
CATEGORIES=	math java
MASTER_SITES=	http://forge.scilab.org/upload/jlatexmath/files/
DISTNAME=	${PORTNAME}-src-all-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
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
FOP_BUILD_DEPENDS=	fop:${PORTSDIR}/textproc/fop \
			${JAVALIBDIR}/xmlgraphics-commons.jar:${PORTSDIR}/graphics/xmlgraphics-commons \
			${JAVASHAREDIR}/batik/batik.jar:${PORTSDIR}/graphics/batik \
			${JAVALIBDIR}/avalon-framework.jar:${PORTSDIR}/devel/avalon-framework \
			${JAVALIBDIR}/commons-io.jar:${PORTSDIR}/devel/jakarta-commons-io \
			${JAVALIBDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
			${JAVALIBDIR}/xml-apis-ext.jar:${PORTSDIR}/textproc/xml-commons
FOP_RUN_DEPENDS:=	${FOP_BUILD_DEPENDS}
FOP_ALL_TARGET=		fop

post-patch:
	${REINPLACE_CMD} -e 's|/usr/share/java/fop.jar|${LOCALBASE}/share/java/fop/build/fop.jar|' ${WRKSRC}/fop.properties
	${REINPLACE_CMD} -e 's|/usr/share/java/batik.jar|${LOCALBASE}/share/java/batik/batik.jar|' ${WRKSRC}/fop.properties
	${REINPLACE_CMD} -e 's|/usr/share/java/|${JAVALIBDIR}/|' ${WRKSRC}/fop.properties

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/jlatexmath-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/jlatexmath.jar
	${INSTALL_DATA} ${WRKSRC}/dist/jlatexmath-fop-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/jlatexmath-fop.jar
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
