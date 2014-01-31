# Created by: Jim Pirzyk <pirzyk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pam_pseudo
PORTVERSION=	0.5
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.feep.net/pub/software/PAM/pam_pseudo/

MAINTAINER=	pirzyk@FreeBSD.org
COMMENT=	PAM module for per-user authentication

USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-encap --disable-epkg-install

INSTALL_TARGET=	install-real

.include <bsd.port.mk>
