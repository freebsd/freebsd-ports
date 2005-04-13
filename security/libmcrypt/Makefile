# New ports collection makefile for:	mcrypt
# Date created:		Mon Jun 28 18:02:04 PDT 1999
# Whom:			nsayer@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	libmcrypt
PORTVERSION=	2.5.7
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/lib//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-cipher cryptographic library (used in PHP)

USE_LIBTOOL_VER=15
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-static
INSTALLS_SHLIB=	yes

MAN3=		mcrypt.3

.include <bsd.port.mk>
