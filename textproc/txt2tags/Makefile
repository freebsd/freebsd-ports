# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	txt2tags
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert simply formatted text into markup (e.g., HTML)

USES=		python:2 shebangfix tar:tgz
SHEBANG_FILES=	extras/html-update.sh
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	ChangeLog README userguide.pdf
SAMPLE_DIRS=	css img module

post-patch:
	@${REINPLACE_CMD} -e 's|/env python|/env python2|' \
		${WRKSRC}/txt2tags
	@${MV} ${WRKSRC}/doc/userguide.pdf ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/txt2tags ${STAGEDIR}${PREFIX}/bin
.for dir in ${SAMPLE_DIRS}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/samples/${dir}/* ${STAGEDIR}${EXAMPLESDIR}/${dir}
.endfor
	${INSTALL_DATA} ${WRKSRC}/samples/sample* ${STAGEDIR}${EXAMPLESDIR}/
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/extras
	${CP} -a ${WRKSRC}/extras/* ${STAGEDIR}${EXAMPLESDIR}/extras
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
