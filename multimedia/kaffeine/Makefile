# New ports collection makefile for:	kaffeine
# Date created:				2003-06-25
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kaffeine
PORTVERSION=	0.5
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kaffeine

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A xine-base multimedia player

LIB_DEPENDS=	xine.12:${PORTSDIR}/multimedia/libxine

USE_BZIP2=		yes
USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CXXFLAGS="${CFLAGS}"
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		kaffeine.1
MANLANG=	"" de

.include <bsd.port.mk>
