# New ports collection makefile for:	pam_authsrv
# Date created:				11 May 2006
# Whom:					Jim Pirzyk <pirzyk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pam_authsrv
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.feep.net/pub/software/PAM/pam_authsrv/

MAINTAINER=	pirzyk@FreeBSD.org
COMMENT=	PAM module for per-user authentication

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/security/fwtk:build

RESTRICTED=	No form of redistribution is allowed, because of linkging against fwtk

USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${PORTSDIR}/security/fwtk/work/fwtk" \
		CFLAGS="${CFLAGS} -I${PORTSDIR}/security/fwtk/work/fwtk"
CONFIGURE_ARGS=	--disable-encap --disable-epkg-install
INSTALL_TARGET=	install-real

MAN5=		pam_authsrv.5

.include <bsd.port.mk>
