# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	amqp
PORTVERSION=	1.3.0
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Low-level AMQP client for Python (fork of amqplib)

LICENSE=	LGPL21

USE_GITHUB=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes

GH_ACCOUNT=	celery
GH_PROJECT=	py-${PORTNAME}
GH_COMMIT=	e422bc0
GH_TAGNAME=	v${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.mk>
