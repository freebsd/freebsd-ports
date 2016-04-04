# $FreeBSD$

PORTNAME=	Flask-Bootstrap
PORTVERSION=	3.3.2.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	che@bein.link
COMMENT=	Flask extension that adds Bootstrap to your projects

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.10.1:www/py-flask

USES=		python
USE_PYTHON=	autoplist distutils

post-extract:
	@${CHMOD} -R a+rX ${WRKSRC}

.include <bsd.port.mk>
