# New ports collection makefile for:	kaffeine
# Date created:				2003-06-25
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kaffeine
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kaffeine

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A xine-base multimedia player

LIB_DEPENDS=	xine.13:${PORTSDIR}/multimedia/libxine

USE_BZIP2=		yes
USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CXXFLAGS="${CFLAGS}"
CONFIGURE_TARGET=

MAN1=		kaffeine.1
MANLANG=	"" de

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xorg
CONFIGURE_ARGS+=	--with-xorg
.endif

.include <bsd.port.post.mk>
