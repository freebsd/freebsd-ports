# Created by: Martin Tournoij <martin@arp242.net>
# $FreeBSD$

PORTNAME=	spamdb-curses
PORTVERSION=	1.2
CATEGORIES=	mail python
MASTER_SITES=	http://code.arp242.net/spamdb-curses/downloads/

MAINTAINER=	martin@arp242.net
COMMENT=	Curses interface for OpenBSD spamd spam database (spamdb)

LICENSE=	MIT

RUN_DEPENDS=	${LOCALBASE}/sbin/spamdb:${PORTSDIR}/mail/spamd

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

NO_STAGE=	yes
.include <bsd.port.mk>
