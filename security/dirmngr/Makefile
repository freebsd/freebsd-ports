# New ports collection makefile for:	dirmngr
# Date created:		06 Feb 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	dirmngr
PORTVERSION=	0.5.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	alpha/dirmngr
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	lofi@freebsd.org
COMMENT=	A client for managing and downloading certificate revocation lists

BUILD_DEPENDS=	${LOCALBASE}/lib/libassuan.a:${PORTSDIR}/security/libassuan
LIB_DEPENDS=	gcrypt.12:${PORTSDIR}/security/libgcrypt \
		gpg-error:${PORTSDIR}/security/libgpg-error \
		ksba.13:${PORTSDIR}/security/libksba

USE_OPENLDAP=	yes
USE_GETOPT_LONG=yes
USE_LIBTOOL_VER=13
USE_GMAKE=	yes
USE_GETTEXT=	yes
INFO=		dirmngr

.include <bsd.port.mk>
