# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	pynacl
PORTVERSION=	0.3.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyNaCl-${PORTVERSION}

MAINTAINER=	yuri@rawbw.com
COMMENT=	PyNaCl is a Python binding to the Networking and Cryptography library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libnacl.a:${PORTSDIR}/security/nacl \
		${PYTHON_PKGNAMEPREFIX}cffi>0:${PORTSDIR}/devel/py-cffi
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:${PORTSDIR}/devel/py-cffi

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/nacl/_lib/_cffi__xfc5fefe5xfb751af7.so

.include <bsd.port.mk>
