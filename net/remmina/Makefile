# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	remmina
PORTVERSION=	0.9.3
PORTREVISION=	3
CATEGORIES=	net gnome
MASTER_SITES=	SF/${PORTNAME}/0.9

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	The GTK+ Remote Desktop Client

OPTIONS_DEFINE=	SSH GCRYPT TERM AVAHI UNIQUE NLS
OPTIONS_DEFAULT=	SSH GCRYPT TERM AVAHI UNIQUE
SSH_DESC=	SSH tunneling support
GCRYPT_DESC=	libgcrypt support for password encryption
TERM_DESC=	terminal support
UNIQUE_DESC=	Unique-App support

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 desktopfileutils
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -Wl,-rpath -Wl,${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
SUB_FILES=	pkg-message

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MSSH}
BUILD_DEPENDS+=	${LOCALBASE}/include/libssh/libssh.h:${PORTSDIR}/security/libssh
RUN_DEPENDS+=	${LOCALBASE}/lib/libssh.so.4:${PORTSDIR}/security/libssh
.if ${OSVERSION} >= 800040
LDFLAGS+=	-fstack-protector
.endif
.else
CONFIGURE_ARGS+=--disable-ssh
.endif

.if ${PORT_OPTIONS:MGCRYPT}
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt
.else
CONFIGURE_ARGS+=--disable-gcrypt
.endif

.if ${PORT_OPTIONS:MTERM}
USE_GNOME+=	vte
.else
CONFIGURE_ARGS+=--disable-vte
.endif

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	avahi-ui.0:${PORTSDIR}/net/avahi-gtk
.else
CONFIGURE_ARGS+=--disable-avahi
.endif

.if ${PORT_OPTIONS:MUNIQUE}
LIB_DEPENDS+=	unique-1.0.2:${PORTSDIR}/x11-toolkits/unique
.else
CONFIGURE_ARGS+=--disable-unique
.endif

post-install:
	@-update-desktop-database
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
