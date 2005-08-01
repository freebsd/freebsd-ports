# New ports collection makefile for:   synce-libsynce
# Date created:                14 June 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-libsynce
PORTVERSION=	0.9.1
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	lawrance@FreeBSD.org
COMMENT=	Library to support communication with WinCE devices

MAN1=		synce.1

USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=13
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${LOCALBASE}

INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
