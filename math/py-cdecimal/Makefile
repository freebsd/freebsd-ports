# Created by: Maksym Sobolyev <sobomax@FreeBSD.org>

PORTNAME=	cdecimal
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.bytereef.org/software/mpdecimal/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast drop-in replacement for the Decimal module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	upstream does not support it after Python-3.2

USES=		python:3.6-3.8
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} == 3.9
# Note: a fast C implementation of the decimal module (_decimal) is bundled with Python
BROKEN=	no member named 'tp_print' in 'struct _typeobject'
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cdecimal*.so

.include <bsd.port.post.mk>
