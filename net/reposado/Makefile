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

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/code/reposadolib/reposadocommon.py
	@${REINPLACE_CMD} -e "s,%%PORTVERSION%%,${PORTVERSION},g" \
		${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR} && \
		${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
