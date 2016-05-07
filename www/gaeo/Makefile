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

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	google-appengine>=1.1.0:www/google-appengine \
		${PYTHON_PKGNAMEPREFIX}simplejson>1.9:devel/py-simplejson

PROJECTHOST=	google-app-engine-oil

USES=		python zip
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

PORTDOCS=	LICENSE NOTICE README.TXT CHANGELOG

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
