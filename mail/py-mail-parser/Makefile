# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mail-parser
PORTVERSION=	3.11.0
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrapper for email standard library

LICENSE=	APACHE20

RUN_DEPENDS=	msgconvert:mail/p5-Email-Outlook-Message \
		${PY_IPADDRESS} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=3.17.0:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.13.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|==|>=|' ${WRKSRC}/requirements.txt ${WRKSRC}/mail_parser.egg-info/requires.txt

.include <bsd.port.mk>
