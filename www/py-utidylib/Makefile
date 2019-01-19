# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	utidylib
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to tidy-lib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	xdissent
GH_PROJECT=	utidylib
GH_TAGNAME=	8eb8b3041d4dd44d7b64314da477b93b98bd692d

# XXX Better depend on tidy or tidy-devel???
LIB_DEPENDS=	libtidy.so:www/tidy-lib

USES=		python:2.7
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
