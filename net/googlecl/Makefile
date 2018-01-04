# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googlecl
PORTVERSION=	0.9.15.1
CATEGORIES=	net www python

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Command line tools for the Google Data APIs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/License

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdata>0:devel/py-gdata@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauth2client>0:security/py-oauth2client@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>0:www/py-httplib2@${FLAVOR}

USES=		python:2
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT=	vinitkumar
GH_TAGNAME=	e54a789
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
