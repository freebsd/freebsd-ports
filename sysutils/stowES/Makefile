# ex:ts=8
# New ports collection makefile for:	stowES
# Date created:			Mar 17, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stowES
PORTVERSION=	0.4.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.inf.tu-dresden.de/~al10/stowES/download/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	stow:${PORTSDIR}/sysutils/stow
.if !exists(/usr/bin/bzip2)
RUN_DEPENDS+=	bzip2:${PORTSDIR}/archivers/bzip2
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	stowES.1

.include <bsd.port.mk>
