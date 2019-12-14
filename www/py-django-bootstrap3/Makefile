# $FreeBSD$

PORTNAME=	django-bootstrap3
PORTVERSION=	11.1.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Bootstrap 3 support for Django projects

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

# Support for Python 2.7 and Django 1.11, 2.0 was dropped in the 12.0 release
PORTSCOUT=	limit:^11\.

post-extract:
	@${FIND} ${WRKSRC} -name ".DS_Store" -type f -delete

.include <bsd.port.mk>
