# New ports collection makefile for:	tcpwatch
# Date created:		2004-05-11
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	tcpwatch
PORTVERSION=	1.3
CATEGORIES=	net python
MASTER_SITES=	http://hathawaymix.org/Software/TCPWatch/

MAINTAINER=	ports@c0decafe.net
COMMENT=	TCP monitoring and logging tool with support for HTTP 1.1

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/tcpwatch.py

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
