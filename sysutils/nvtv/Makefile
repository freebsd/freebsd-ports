# New ports collection makefile for:	nv-tv-out
# Date Created:				19 May 2004
# Whom:					Samuel Tardieu <sam@rfc1149.net>
#
# $FreeBSD$
#

PORTNAME=	nvtv
PORTVERSION=	0.4.7
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	SF/nv-tv-out/${PORTNAME}-src/${PORTVERSION}
DISTNAME=	nvtv-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TV output on nvidia card

LIB_DEPENDS=	pci.2:${PORTSDIR}/devel/libpci

ONLY_FOR_ARCHS=	i386

CONFIGURE_ENV=	CC="${CC} -I${PREFIX}/include"

GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_XORG=	x11 xxf86vm xmu

MAN1=		nvtv.1x
MAN8=		nvtvd.8
PLIST_FILES=	bin/nvtv bin/nvtvd

.include <bsd.port.mk>
