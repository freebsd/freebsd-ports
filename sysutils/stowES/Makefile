# ex:ts=8
# New ports collection makefile for:	stowES
# Date created:			Mar 17, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stowES
PORTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.inf.tu-dresden.de/~al10/stowES/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	stow Enhancement Script

RUN_DEPENDS=	stow:${PORTSDIR}/sysutils/stow
.if !exists(/usr/bin/bzip2)
RUN_DEPENDS+=	bzip2:${PORTSDIR}/archivers/bzip2
.endif

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=	stowES.1

.include <bsd.port.mk>
