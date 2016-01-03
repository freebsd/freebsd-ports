# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mtail
PORTVERSION=	1.1.1
CATEGORIES=	misc
MASTER_SITES=	http://matt.immute.net/src/mtail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small tail workalike that performs output coloring

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:run tar:tgz
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGES LICENSE README
PORTEXAMPLES=	mtailrc

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '1s|/.*|${PYTHON_CMD}|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} $ ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/mtailrc.sample \
		${STAGEDIR}${EXAMPLESDIR}/mtailrc

.include <bsd.port.mk>
