# New ports collection makefile for:	gabber
# Date created:				20 Jun 2000
# Whom:				Erich Zigler <erich@tacni.net>
#
# $FreeBSD$
#

PORTNAME=	gabber
PORTVERSION=	0.8.8
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME Jabber Client

.if defined(WITH_XMMS)
BUILD_DEPENDS+=	xmms-config:${PORTSDIR}/multimedia/xmms
.endif
LIB_DEPENDS=	gnomemm-1.2.10:${PORTSDIR}/x11-toolkits/gnome--

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget libglade gal
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure jabberoo/configure
CONFIGURE_ENV+=	GNOME_LIBCONFIG_PATH="${LOCALBASE}/lib:${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.if !defined(WITH_XMMS)
CONFIGURE_ARGS=	--disable-xmms
.endif

MAN1=		gabber.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
IGNORE=	"Crashes or hangs on 5.x"
.endif

pre-build:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f

.include <bsd.port.post.mk>
