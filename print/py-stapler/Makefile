# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stapler
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
#DISTNAME=	PyPDF2-${PORTVERSION}

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Manipulate PDF documents from the command line

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}more-itertools5>=2.2:devel/py-more-itertools5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdf2>=1.24:print/py-pdf2@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
