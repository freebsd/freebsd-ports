# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mtail
PORTVERSION=	1.1.1
CATEGORIES=	misc
MASTER_SITES=	http://matt.immute.net/src/mtail/ CENKES
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small tail workalike that performs output coloring

NO_BUILD=	yes
USE_PYTHON_RUN=	yes
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGES LICENSE README
PORTEXAMPLES=	mtailrc

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '1s|/.*|${PYTHON_CMD}|' ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${INSTALL} -d ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/mtailrc.sample ${EXAMPLESDIR}/mtailrc
.endif

.include <bsd.port.mk>
