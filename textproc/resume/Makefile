# New ports collection makefile for:   resume
# Date created:                17 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	resume
PORTVERSION=	1.5.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xmlresume
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	fuyuki@hadaly.org

NO_BUILD=	yes
USE_REINPLACE=	yes

JAVALIBDIR=	${PREFIX}/share/java/classes

post-patch:
	${REINPLACE_CMD} -e 's|\.\./\.\./css|css|' ${WRKSRC}/xsl/params.xsl
	${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	${MKDIR} ${PREFIX}/share/xml/${PORTNAME}
	${CP} -R ${WRKSRC}/dtd/* ${PREFIX}/share/xml/${PORTNAME}
	${MKDIR} ${PREFIX}/share/xsl/${PORTNAME}
	${CP} -R ${WRKSRC}/xsl/* ${PREFIX}/share/xsl/${PORTNAME}
	${CP} -R ${WRKSRC}/css ${PREFIX}/share/xsl/${PORTNAME}/format
	${MKDIR} ${JAVALIBDIR}
	${INSTALL_DATA} ${WRKSRC}/java/*.jar ${JAVALIBDIR}

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
