# New ports collection makefile for:   synce-dccm
# Date created:                14 June 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	vdccm
PORTVERSION=	0.10.1
CATEGORIES=	palm
MASTER_SITES=	SF/synce/SynCE/${PORTVERSION}
PKGNAMEPREFIX=	synce-

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Listener daemon for connections from WinCE devices

LIB_DEPENDS=	synce.0:${PORTSDIR}/palm/synce-libsynce

OPTIONS=	DESKTOP	"Enable desktop integration"	on

MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_ICONV=	yes
CONFIGURE_ARGS=	--with-libiconv=${LOCALBASE} \
		--with-libsynce=${LOCALBASE}

MAN1=		triggerconnection.1 ${PORTNAME}.1
PLIST_FILES=	bin/triggerconnection bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_DESKTOP)
CONFIGURE_ARGS+=	--enable-desktop-integration=yes
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		hal.1:${PORTSDIR}/sysutils/hal
USE_GNOME+=	glib20
.else
CONFIGURE_ARGS+=	--enable-desktop-integration=no
.endif

.include <bsd.port.post.mk>
