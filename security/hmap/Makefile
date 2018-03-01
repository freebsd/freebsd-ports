# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	hmap
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://ujeni.murkyroc.com/hmap/code/current/
DISTNAME=	${PORTNAME}

MAINTAINER=	onatan@gmail.com
COMMENT=	Web server fingerprinting utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

USES=		dos2unix python
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|DATADIR|${DATADIR}|; s|#! /usr/bin/env python|#!${PYTHON_CMD}|' ${WRKSRC}/hmap.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/hmap.py ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/known.servers/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README BUGS FAQS HIDING_GUIDE KNOWN_TESTS
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
