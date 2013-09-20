# $FreeBSD$

PORTNAME=	gettext
PORTVERSION=	2.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python Gettext po to mo file compiler

LICENSE=	BSD

# Python3 and Pypy 1.7 ready
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	python-${PORTNAME}
USE_ZIP=		yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PYTHON_REL} <= 300
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}unittest2>=0:${PORTSDIR}/devel/py-unittest2
.endif

.include <bsd.port.post.mk>
