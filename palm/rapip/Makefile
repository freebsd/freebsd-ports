# New ports collection makefile for:   rapip
# Date created:                15 June 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	rapip
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	boris@brooknet.com.au
COMMENT=	KIO-slave and trayapp for access to WinCE devices

LIB_DEPENDS+=	synce.0:${PORTSDIR}/palm/synce-libsynce \
		rapi.2:${PORTSDIR}/palm/synce-librapi2
RUN_DEPENDS+=	synce-serial-start:${PORTSDIR}/palm/synce-serial \
		dccm:${PORTSDIR}/palm/synce-dccm

USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
