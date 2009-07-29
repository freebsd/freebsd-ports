# New ports collection makefile for:	gaeo
# Date created:		2008-07-24
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	gaeo
PORTVERSION=	0.2.1
PORTEPOCH=	1
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	An open-source web framework running on Google App Engine

RUN_DEPENDS=	google-appengine>=1.1.0:${PORTSDIR}/www/google-appengine \
		${PYTHON_PKGNAMEPREFIX}simplejson>1.9:${PORTSDIR}/devel/py-simplejson

PROJECTHOST=	google-app-engine-oil

USE_ZIP=	yes
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

GAEOHOME=	${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}

PORTDOCS=	LICENSE NOTICE README.TXT

post-patch:
	${REINPLACE_CMD} -e "s,%%GAEOHOME%%,${GAEOHOME},g" ${WRKSRC}/bin/gaeo.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
