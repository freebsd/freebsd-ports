# Created by: Martin Tournoij <martin@arp242.net>
# $FreeBSD$

PORTNAME=	spamdb-curses
PORTVERSION=	1.2
CATEGORIES=	mail python
MASTER_SITES=	http://code.arp242.net/spamdb-curses/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses interface for OpenBSD spamd spam database (spamdb)

LICENSE=	MIT

BROKEN=		unfetchable

RUN_DEPENDS=	${LOCALBASE}/sbin/spamdb:mail/spamd

USES=		python:2.7
USE_PYTHON=	distutils

.include <bsd.port.mk>
