# New ports collection makefile for:	grdc
# Date created:				12 April 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	remmina
PORTVERSION=	0.7.5
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	SF/${PORTNAME}/0.7/

MAINTAINER=	avl@FreeBSD.org
COMMENT=	The GTK+ Remote Desktop Client

RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop

OPTIONS=	VNC	"Build with VNC protocol support"	off \
		GNUTLS	"Build VNC with GNUTLS encryption support"	off \
		XDMCP	"Build with XDMCP protocol support"	off \
		SSH	"Build with SSH tunneling support"	off \
		GCRYPT	"Build with libgcrypt support for password encryption"	off \
		TERM	"Build with terminal support"	off \
		AVAHI	"Build with Avahi support"	off \
		UNIQUE	"Build with Unique-App support"	off

MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 desktopfileutils
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_VNC)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
.endif
.else
CONFIGURE_ARGS+=	--disable-vnc
.endif

.if defined(WITH_XDMCP)
RUN_DEPENDS+=	Xephyr:${PORTSDIR}/x11-servers/xephyr
.endif

.if defined(WITH_SSH)
LIB_DEPENDS+=	ssh.4:${PORTSDIR}/security/libssh
.if ${OSVERSION} >= 800040
LDFLAGS+=	-fstack-protector
.endif
.else
CONFIGURE_ARGS+=	--disable-ssh
.endif

.if defined(WITH_GCRYPT)
LIB_DEPENDS+=	gcrypt.17:${PORTSDIR}/security/libgcrypt
.else
CONFIGURE_ARGS+=	--disable-gcrypt
.endif

.if defined(WITH_TERM)
USE_GNOME+=	vte
.else
CONFIGURE_ARGS+=	--disable-vte
.endif

.if defined(WITH_AVAHI)
LIB_DEPENDS+=	avahi-ui.0:${PORTSDIR}/net/avahi-gtk
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if defined(WITH_UNIQUE)
LIB_DEPENDS+=	unique-1.0.2:${PORTSDIR}/x11-toolkits/unique
.else
CONFIGURE_ARGS+=	--disable-unique
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
