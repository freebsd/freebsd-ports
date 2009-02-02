# New ports collection makefile for:	netboot
# Date created:				16 Apr 2003
# Whom:					dyeske@gmail.com
#
# $FreeBSD$

PORTNAME=	netboot
PORTVERSION=	0.10.2
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Netboot with Packet or NDIS-2 drivers

LIB_DEPENDS=	lzo2.2:${PORTSDIR}/archivers/lzo2

USE_BDB=	42+
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_BISON=	build
CONFIGURE_ARGS+=	--enable-static=no --enable-bootrom=yes

CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="${LIBS} -L${LOCALBASE}/lib"

MAN5=		netboot.5 netboot.config.5 netboot.drivers.5 netboot.db.5
MAN8=		mknbi-mgl.8 makerom.8 mknbi-dos.8 mknbi-linux.8 nbdbtool.8

post-install:
	@if [ ! -f ${PREFIX}/etc/netboot.config ]; then \
		${CP} ${PREFIX}/etc/netboot.config-dist ${PREFIX}/etc/netboot.config; \
	fi

.include <bsd.port.mk>
