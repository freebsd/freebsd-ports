# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	txt2tags
PORTVERSION=	2.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Convert simply formatted text into markup (e.g., HTML)

USE_PYTHON=	2
NO_BUILD=	yes

PORTDOCS=	ChangeLog README userguide.pdf
SAMPLE_DIRS=	css img module

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/env python|/env python2|' \
		${WRKSRC}/txt2tags
	@${MV} ${WRKSRC}/doc/userguide.pdf ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/txt2tags ${PREFIX}/bin
.for dir in ${SAMPLE_DIRS}
	@${MKDIR} ${EXAMPLESDIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/samples/${dir}/* ${EXAMPLESDIR}/${dir}
.endfor
	${INSTALL_DATA} ${WRKSRC}/samples/sample* ${EXAMPLESDIR}/
	@${MKDIR} ${EXAMPLESDIR}/extras
	${CP} -a ${WRKSRC}/extras/* ${EXAMPLESDIR}/extras
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
