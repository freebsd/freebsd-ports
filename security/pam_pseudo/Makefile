# New ports collection makefile for:	pam_pseudo
# Date created:				11 May 2006
# Whom:					Jim Pirzyk <pirzyk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pam_pseudo
PORTVERSION=	0.4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.feep.net/pub/software/PAM/pam_pseudo/

MAINTAINER=	pirzyk@FreeBSD.org
COMMENT=	PAM module for per-user authentication

USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--disable-encap --disable-epkg-install

INSTALL_TARGET=	install-real

MAN5=		pam_pseudo.5

.include <bsd.port.mk>
