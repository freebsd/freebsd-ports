# New ports collection makefile for:	medusa
# Date created:		2006-05-01
# Whom:			David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	medusa
PORTVERSION=	1.1
CATEGORIES=	security
MASTER_SITES=	http://www.foofus.net/jmk/tools/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	A speedy, massively parallel, modular, login brute-forcer

LIB_DEPENDS=	ssh2:${PORTSDIR}/security/libssh2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	"--program-transform="

MAN1=		medusa.1

.include <bsd.port.mk>
