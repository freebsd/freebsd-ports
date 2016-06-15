# Created by: Olivier Cochard-Labbé <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	maxminddb
PORTVERSION=	1.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net python geography
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Python module for reading MaxMind DB file

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	MaxMind-DB-Reader-python

USES=		localbase python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipaddr>=0:devel/py-ipaddr
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/maxminddb/extension.so

.include <bsd.port.post.mk>
