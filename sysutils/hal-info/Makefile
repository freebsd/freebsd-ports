# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/hal-info/Makefile,v 1.6 2010/03/16 19:33:11 mezz Exp $

PORTNAME=	hal-info
PORTVERSION=	20091130
CATEGORIES=	sysutils
MASTER_SITES=	http://hal.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional FDI files to further classify HAL devices

LIB_PC_DEPENDS=	hal.pc:${PORTSDIR}/sysutils/hal

BUILD_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}
RUN_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}

USE_GMAKE=	yes
USES=	pathfix
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.mk>
