# New ports collection makefile for:   synce-libsynce
# Date created:                14 June 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-libsynce
PORTVERSION=	0.7
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	boris@brooknet.com.au
COMMENT=	Library to support communication with WinCE devices

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

MAN1=		synce.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
