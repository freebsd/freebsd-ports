# New ports collection makefile for:	krename
# Date created:				11 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	krename
PORTVERSION=	2.8.0
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Very powerful batch file renamer for KDE3

USE_BZIP2=	yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
