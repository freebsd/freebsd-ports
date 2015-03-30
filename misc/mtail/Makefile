# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mtail
PORTVERSION=	1.1.1
CATEGORIES=	misc
MASTER_SITES=	http://matt.immute.net/src/mtail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small tail workalike that performs output coloring

USES=		python:run
NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGES LICENSE README
PORTEXAMPLES=	mtailrc

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '1s|/.*|${PYTHON_CMD}|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} $ ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/mtailrc.sample \
		${STAGEDIR}${EXAMPLESDIR}/mtailrc

.include <bsd.port.mk>
