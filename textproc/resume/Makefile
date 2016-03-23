# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	resume
DISTVERSION=	1_5_1
PORTREVISION=	2
CATEGORIES=	textproc java
MASTER_SITES=	SF/xml${PORTNAME}/xml${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML Resume library

LICENSE=	MIT

USES=		tar:tgz
USE_JAVA=	yes
NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|\.\./\.\./css|css|' ${WRKSRC}/xsl/params.xsl
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	cd ${WRKSRC}/dtd && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/xml/${PORTNAME}
	cd ${WRKSRC}/xsl && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/xsl/${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} css ${STAGEDIR}${PREFIX}/share/xsl/${PORTNAME}/format
	${INSTALL_DATA} ${WRKSRC}/java/*.jar ${STAGEDIR}${JAVAJARDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
