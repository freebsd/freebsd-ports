# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	tcpwatch
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	net python
MASTER_SITES=	http://hathawaymix.org/Software/TCPWatch/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCP monitoring and logging tool with support for HTTP 1.1

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGVERSION=	1.2.1
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
