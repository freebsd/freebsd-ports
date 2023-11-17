PORTNAME=	django-ldapdb
DISTVERSION=	1.5.1-7
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gd3a0b20
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	avk@vl.ru
COMMENT=	LDAP database backend for Django
WWW=		https://github.com/django-ldapdb/django-ldapdb

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=2.2:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-ldap>=3.0:net/py-python-ldap@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes
PORTDOCS=	README.rst

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
