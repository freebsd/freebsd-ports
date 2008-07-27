# New ports collection makefile for:   synce-trayicon
# Date created:                28 August 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-trayicon
PORTVERSION=	0.11
CATEGORIES=	palm
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	ports@logvinov.com
COMMENT=	GNOME tray icon showing battery and storage status of a WinCE device

LIB_DEPENDS=	rra.0:${PORTSDIR}/palm/synce-librra \
		gtop-2.0.7:${PORTSDIR}/devel/libgtop

OPTIONS=	NOTIFY	"Enable libnotify support"	on

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget libgnomeui
INSTALLS_ICONS=	yes
GCONF_SCHEMAS=	${PORTNAME}.schemas
LDFLAGS+=	-L${LOCALBASE}/lib -lsynce
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
SUB_FILES=	pkg-message

MAN1=		${PORTNAME}.1

.include <bsd.port.pre.mk>

.if defined(WITH_NOTIFY)
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
RUN_DEPENDS+=	${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon
.endif

post-patch:
.if !defined(WITH_NOTIFY)
	@${REINPLACE_CMD} -e 's|enable_notify=yes|enable_notify=no|' ${WRKSRC}/configure
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
