# New ports collection makefile for:   synce-dccm
# Date created:                14 June 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-dccm
PORTVERSION=	0.9.3
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce
DISTNAME=	synce-vdccm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Listener daemon for connections from WinCE devices

BUILD_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS+=	synce.0:${PORTSDIR}/palm/synce-libsynce

GNU_CONFIGURE=	yes
USE_ICONV=	yes
WRKSRC=		${WRKDIR}/vdccm-${PORTVERSION}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-libiconv=${LOCALBASE} \
			--with-libsynce=${LOCALBASE}

.include <bsd.port.mk>
