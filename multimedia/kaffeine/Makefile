# New ports collection makefile for:	kaffeine
# Date created:				2003-06-25
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kaffeine
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kaffeine

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A xine-base multimedia player

LIB_DEPENDS=	xine.9:${PORTSDIR}/multimedia/libxine

USE_BZIP2=		yes
USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CXXFLAGS="${CFLAGS} -fPIC"
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "amd64"
BROKEN=	"crashes on start"
.endif

.include <bsd.port.post.mk>
