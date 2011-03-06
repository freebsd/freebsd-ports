# New ports collection makefile for:	jlatexmath
# Date created:				11 February 2010
# Whom:					rfarmer@predatorlabs.net
#
# $FreeBSD$
#

PORTNAME=	jlatexmath
PORTVERSION=	0.9.4
CATEGORIES=	math java
MASTER_SITES=	http://forge.scilab.org/upload/jlatexmath/files/ \
		http://www.predatorlabs.net/dl/
DISTNAME=	${PORTNAME}-src-all-${PORTVERSION}

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Java API to display mathematical formulas written in LaTeX

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_BUILD=	yes
JAVA_RUN=	yes
USE_ANT=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS=	FOP "textproc/fop plugin (required for math/scilab)" ON

.include <bsd.port.options.mk>

.if defined(WITHOUT_FOP)
PLIST_SUB+=	FOP="@comment "
.else
BUILD_DEPENDS=	fop:${PORTSDIR}/textproc/fop \
		${JAVALIBDIR}/xmlgraphics-commons.jar:${PORTSDIR}/graphics/xmlgraphics-commons \
		${JAVASHAREDIR}/batik/batik.jar:${PORTSDIR}/graphics/batik \
		${JAVALIBDIR}/avalon-framework.jar:${PORTSDIR}/devel/avalon-framework \
		${JAVALIBDIR}/commons-io.jar:${PORTSDIR}/devel/jakarta-commons-io \
		${JAVALIBDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
		${JAVALIBDIR}/xml-apis-ext.jar:${PORTSDIR}/textproc/xml-commons

RUN_DEPENDS:=	${BUILD_DEPENDS}

ALL_TARGET+=	fop

PLIST_SUB+=	FOP=""
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/share/java/fop.jar|${LOCALBASE}/share/java/fop/build/fop.jar|' ${WRKSRC}/fop.properties
	${REINPLACE_CMD} -e 's|/usr/share/java/batik.jar|${LOCALBASE}/share/java/batik/batik.jar|' ${WRKSRC}/fop.properties
	${REINPLACE_CMD} -e 's|/usr/share/java/|${JAVALIBDIR}/|' ${WRKSRC}/fop.properties

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/jlatexmath-${PORTVERSION}.jar ${JAVAJARDIR}/jlatexmath.jar
	${INSTALL_DATA} ${WRKSRC}/dist/jlatexmath-fop-${PORTVERSION}.jar ${JAVAJARDIR}/jlatexmath-fop.jar
.if !defined(NOPORTEXAMPLES)
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
