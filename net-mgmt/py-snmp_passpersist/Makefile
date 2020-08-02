# $FreeBSD$

PORTNAME=	snmp_passpersist
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	net-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	surajravi@gmail.com
COMMENT=	Python client library for Net-SNMP pass persist backend

LICENSE=	GPLv3

RUN_DEPENDS=	net-snmp>=0:net-mgmt/net-snmp

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	nagius
GH_TAGNAME=	fb0af0d

USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
