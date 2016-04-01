# $FreeBSD$

PORTNAME=	poezio
PORTVERSION=	0.8.1
CATEGORIES=	net-im
MASTER_SITES=	http://dev.louiz.org/attachments/download/52/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Console XMPP client

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/dns/__init__.py:dns/py-dnspython \
		${PYTHON_SITELIBDIR}/sleekxmpp/__init__.py:net-im/py-sleekxmpp

USES=		tar:xz python:3.3+
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) && ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE= you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>
