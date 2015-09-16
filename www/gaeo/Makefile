# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	gaeo
PORTVERSION=	0.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www devel python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source web framework running on Google App Engine

RUN_DEPENDS=	google-appengine>=1.1.0:${PORTSDIR}/www/google-appengine \
		${PYTHON_PKGNAMEPREFIX}simplejson>1.9:${PORTSDIR}/devel/py-simplejson

PROJECTHOST=	google-app-engine-oil

USES=		python zip
USE_PYTHON=	distutils autoplist

PORTDOCS=	LICENSE NOTICE README.TXT CHANGELOG

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
