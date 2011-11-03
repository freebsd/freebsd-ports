# New ports collection makefile for:	mail/spamdb-curses
# Date created:				2011-10-25
# Whom:					Martin Tournoij <martin@arp242.net>
#
# $FreeBSD$
#

PORTNAME=	spamdb-curses
PORTVERSION=	1.1
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	martin@arp242.net
COMMENT=	Curses interface for OpenBSD spamd spam database (spamdb)

LICENSE=	BSD

RUN_DEPENDS=	${LOCALBASE}/sbin/spamdb:${PORTSDIR}/mail/spamd

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
