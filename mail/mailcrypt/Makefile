# New ports collection makefile for:	mailcrypt
# Date created:        29 May 1998
# Whom:                Murray Stokely <murray@cdrom.com>
#
# $FreeBSD$
#

PORTNAME=	mailcrypt
PORTVERSION=	3.5.8
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Emacs/PGP interface

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ARGS=	lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
INFO=		mailcrypt

.include <bsd.port.mk>
