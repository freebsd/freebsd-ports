# Created by: Trevor Caira <trevor@bitba.se>
# $FreeBSD$

PORTNAME=	selector
PORTVERSION=	0.9.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	trevor@bitba.se
COMMENT=	WSGI request delegation (a.k.a. routing)

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}resolver>=0.2.1:${PORTSDIR}/devel/py-resolver

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's/license="MIT",/license="MIT", zip_safe=False,/' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
