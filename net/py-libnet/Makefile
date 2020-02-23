# Created by: ijliao
# $FreeBSD$

PORTNAME=	libnet
DISTVERSION=	3.0rc1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylibnet-${DISTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python extension for the Libnet packet injection library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

LIB_DEPENDS=	libnet.so:net/libnet

USES=		python:2.7
USE_PYTHON=	autoplist concurrent distutils

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/setup.py

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/libnet.so

.include <bsd.port.mk>
