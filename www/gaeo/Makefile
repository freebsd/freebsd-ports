# New ports collection makefile for:	gaeo
# Date created:		2008-07-24
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	gaeo
PORTVERSION=	45
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-trunk-r${PORTVERSION}

MAINTAINER=	yzlin@cs.nctu.edu.tw
COMMENT=	An open-source web framework running on Google App Engine

RUN_DEPENDS=	google-appengine>=1.1.0:${PORTSDIR}/www/google-appengine

PROJECTHOST=	google-app-engine-oil

NO_BUILD=	yes

USE_PYTHON=	2.5+
USE_ZIP=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR},g" ${WRKSRC}/bin/gaeo.py

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "gaeo" ${DATADIR}
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${DOCSDIR}/README
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gaeo.py ${PREFIX}/bin/gaeo.py
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gaeogen.py ${PREFIX}/bin/gaeogen.py

.include <bsd.port.mk>
