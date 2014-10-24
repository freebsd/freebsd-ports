# Created by: Masaki TAGAWA <masaki@club.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	reposado
PORTVERSION=	0.0.20130415
CATEGORIES=	net

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	Tools for replicating the Apple's Software Update Service

RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	wdas
GH_COMMIT=	${GH_TAGNAME}
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	1bcf4f0

LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	distutils

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/code/reposadolib/reposadocommon.py
	@${REINPLACE_CMD} -e "s,%%PORTVERSION%%,${PORTVERSION},g" \
		${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR} && \
		${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
