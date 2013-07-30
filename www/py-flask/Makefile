# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$
#

PORTNAME=	Flask
PORTVERSION=	0.10.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Micro web framework

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}werkzeug>=0.8:${PORTSDIR}/www/py-werkzeug \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.6:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}itsdangerous>=0.21:${PORTSDIR}/security/py-itsdangerous

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 320
.include "${PORTSDIR}/devel/py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

.include <bsd.port.post.mk>
