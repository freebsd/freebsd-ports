# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	obfsproxy
PORTVERSION=	0.2.4
PORTEPOCH=	1
CATEGORIES=	security net python
MASTER_SITES=	http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Pluggable transport proxy

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyptlib>=0.0.5:${PORTSDIR}/security/py-pyptlib \
		${PYTHON_PKGNAMEPREFIX}argparse>0:${PORTSDIR}/devel/py-argparse \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.1:${PORTSDIR}/security/py-pycrypto

USE_PYTHON=	yes
USES=		twisted
USE_PYDISTUTILS=easy_install
SUB_FILES=	pkg-message
PYDISTUTILS_PKGNAME=obfsproxy

NO_STAGE=	yes

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
