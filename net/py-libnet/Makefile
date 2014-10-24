# Created by: ijliao
# $FreeBSD$

PORTNAME=	libnet
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python module for the libnet packet construction library

LICENSE=	GPLv3

LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet

USES=		python
USE_PYTHON=	distutils pythonprefix

USE_GITHUB=	yes
GH_ACCOUNT=	allfro
GH_PROJECT=	pylibnet
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	b2fa552

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES
OSVER=		uname -r

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} \
	${WRKSRC}/build/lib.${OPSYS:tl}-$$(${OSVER})-${ARCH}-${PYTHON_VER}/${PORTNAME}.so \
	${STAGEDIR}${PYTHON_SITELIBDIR}
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
