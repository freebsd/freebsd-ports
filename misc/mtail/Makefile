# New ports collection makefile for:	mtail
# Date created:		9 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

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

post-patch:
	@${REINPLACE_CMD} -e '1s|/.*|${PYTHON_CMD}|' ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
.ifndef NOPORTEXAMPLES
	@${INSTALL} -d ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/mtailrc.sample ${EXAMPLESDIR}/mtailrc
.endif

.include <bsd.port.mk>
