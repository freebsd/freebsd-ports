# New ports collection makefile for:   usbhotkey
# Date created:        16 July 2007
# Whom:                ntarmos@ceid.upatras.gr
#
# $FreeBSD$
#

PORTNAME=		usbhotkey
PORTVERSION=		0.3.1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	usbhotkey

MAINTAINER=		ntarmos@ceid.upatras.gr
COMMENT=		A utility to remap USB keyboards under X11

LIB_DEPENDS=		hid.0:${PORTSDIR}/devel/libhid \
			Xtst.6:${PORTSDIR}/x11/libXtst

OPTIONS=		GUI "Enable GUI bits (Imlib dependency)" on

USE_RUBY=		yes
USE_GMAKE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		CFLAGS="${CFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" \
			LDFLAGS="${LDFLAGS} -L${X11BASE}/lib -L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GUI)
LIB_DEPENDS+=		Imlib.5:${PORTSDIR}/graphics/imlib
.else
CONFIGURE_ARGS+=	--without-Imlib
.endif

.include <bsd.port.post.mk>
