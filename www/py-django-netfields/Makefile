# $FreeBSD$

PORTNAME=	django-netfields
DISTVERSION=	0.8
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alfred@FreeBSD.org
COMMENT=	Django PostgreSQL netfields implementation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>0:www/py-django18@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0:net/py-netaddr@${FLAVOR}

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipaddress>=0:net/py-ipaddress@${FLAVOR}
.endif

.include <bsd.port.post.mk>
