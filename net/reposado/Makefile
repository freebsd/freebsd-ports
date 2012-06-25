# New ports collection makefile for: reposado
# Date created:		23 Jun 2012
# Whom:			Masaki TAGAWA <masaki@club.kyutech.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	reposado
PORTVERSION=	0.0.20120620
CATEGORIES=	net
MASTER_SITES=	https://nodeload.github.com/wdas/reposado/zipball/${TAG}?dummy=/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0.0.//}

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	Tools for replicating the Apple's Software Update Service

RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl

LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	yes

TAG=		edfdb87
WRKSRC=		${WRKDIR}/wdas-reposado-${TAG}
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/code/reposadolib/reposadocommon.py
	@${REINPLACE_CMD} -e "s,%%PORTVERSION%%,${PORTVERSION},g" \
		${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.md ${DOCSDIR} &&\
			${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
