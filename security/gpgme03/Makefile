# New ports collection makefile for:	gpgme
# Date created:		15 June 2001
# Whom:			teramoto@comm.eng.osaka-u.ac.jp
#
# $FreeBSD$
#

PORTNAME=	gpgme
PORTVERSION=	0.2.3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/gpgme/

MAINTAINER=	teramoto@comm.eng.osaka-u.ac.jp

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
MAKE_ENV+=	PORT_LIBTOOL=${LIBTOOL}

.include <bsd.port.mk>
