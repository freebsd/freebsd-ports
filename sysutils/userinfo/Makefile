# Ports collection Makefile for:	userinfo
# Date created:		5 November 2002
# Whom:			Ben Kibbey <bjk@arbornet.org>
#
# $FreeBSD$
#

PORTNAME=	userinfo
PORTVERSION=	2.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bjk

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Show information about local users

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--mandir=${TARGETDIR}/man

MAN1=		ui.1
MLINKS=		ui.1 userinfo.1

.include <bsd.port.mk>
