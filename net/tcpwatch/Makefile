# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	tcpwatch
PORTVERSION=	1.3
PORTREVISION=	4
CATEGORIES=	net python
MASTER_SITES=	http://hathawaymix.org/Software/TCPWatch/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCP monitoring and logging tool with support for HTTP 1.1

LICENSE=	ZPL20
LICENSE_NAME=	Zope Public License version 2.0
LICENSE_TEXT=	The license: ${LICENSE} (${LICENSE_NAME}) is standard, please read from the web.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent optsuffix
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
