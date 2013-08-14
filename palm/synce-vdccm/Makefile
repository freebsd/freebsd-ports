# Created by: Sam Lawrance <boris@brooknet.com.au>
# $FreeBSD$

PORTNAME=	vdccm
PORTVERSION=	0.10.1
CATEGORIES=	palm
MASTER_SITES=	SF/synce/SynCE/${PORTVERSION}
PKGNAMEPREFIX=	synce-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Listener daemon for connections from WinCE devices

LIB_DEPENDS=	synce.0:${PORTSDIR}/palm/synce-libsynce

OPTIONS_DEFINE=	DESKTOP
OPTIONS_DEFAULT=	DESKTOP
DESKTOP_DESC=	Desktop integration


GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USES=		iconv
CONFIGURE_ARGS=	--with-libiconv=${LOCALBASE} \
		--with-libsynce=${LOCALBASE}

MAN1=		triggerconnection.1 ${PORTNAME}.1
PLIST_FILES=	bin/triggerconnection bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.if ${PORT_OPTIONS:MDESKTOP}
CONFIGURE_ARGS+=	--enable-desktop-integration=yes
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		hal.1:${PORTSDIR}/sysutils/hal
USE_GNOME+=	glib20
.else
CONFIGURE_ARGS+=	--enable-desktop-integration=no
.endif

.include <bsd.port.post.mk>
