# $FreeBSD$

PORTNAME=	poezio
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://dev.louiz.org/attachments/download/52/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console XMPP client

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/dns/__init__.py:dns/py-dnspython@${FLAVOR} \
		${PYTHON_SITELIBDIR}/sleekxmpp/__init__.py:net-im/py-sleekxmpp@${FLAVOR}

USES=		tar:xz python:3.3+
USE_PYTHON=	distutils autoplist optsuffix

.include <bsd.port.mk>
