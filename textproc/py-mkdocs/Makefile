# $FreeBSD$

PORTNAME=	mkdocs
DISTVERSION=	0.17.2-36
DISTVERSIONSUFFIX=	-gd4c5832
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd_ports@k-worx.org
COMMENT=	Project documentation with Markdown

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=3.3:devel/py-click@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7.1:devel/py-Jinja2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}livereload>=2.5.1:www/py-livereload@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.3.1:textproc/py-markdown@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=5.0:www/py-tornado@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.10:devel/py-yaml@${FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
