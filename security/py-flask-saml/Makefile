# $FreeBSD$

PORTNAME=	Flask-SAML
PORTVERSION=	0.4.4
CATEGORIES=	security www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	john@saltant.com
COMMENT=	SAML authentication for Flask web apps

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.8.0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blinker>=1.1:devel/py-blinker@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pysaml24>=4.0.0<5:security/py-pysaml24@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pysaml2>=5.1.0<6.20:security/py-pysaml2@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
