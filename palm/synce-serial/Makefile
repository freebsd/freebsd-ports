# New ports collection makefile for:   synce-serial
# Date created:                14 June 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-serial
PORTVERSION=	0.7
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	boris@brooknet.com.au
COMMENT=	Wrapper for pppd to initiate communications with WinCE devices

MAN8=	synce-serial-config.8 synce-serial-start.8 synce-serial-abort.8

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--program-transform-name=""
INSTALLS_SHLIB=		yes

.include <bsd.port.mk>
