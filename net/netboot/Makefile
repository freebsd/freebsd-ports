# New ports collection makefile for:	netboot
# Date created:				16 Apr 2003
# Whom:					dyeske@yahoo.com
#
# $FreeBSD$

PORTNAME=	netboot
PORTVERSION=	0.9.8
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	Netboot with Packet or NDIS-2 drivers

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN5=		netboot.5 netboot.config.5 netboot.drivers.5 netboot.db.5
MAN8=		mknbi-mgl.8 makerom.8 mknbi-dos.8 mknbi-linux.8

post-install:
	@if [ ! -f ${PREFIX}/etc/netboot.config ]; then \
		${CP} ${PREFIX}/etc/netboot.config-dist ${PREFIX}/etc/netboot.config; \
	fi

.include <bsd.port.mk>
