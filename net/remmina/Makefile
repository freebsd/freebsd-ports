# New ports collection makefile for:	grdc
# Date created:				12 April 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	remmina
PORTVERSION=	0.9.3
CATEGORIES=	net gnome
MASTER_SITES=	SF/${PORTNAME}/0.9

MAINTAINER=	avl@FreeBSD.org
COMMENT=	The GTK+ Remote Desktop Client

OPTIONS=	SSH	"Build with SSH tunneling support"	on \
		GCRYPT	"Build with libgcrypt support for password encryption"	on \
		TERM	"Build with terminal support"	on \
		AVAHI	"Build with Avahi support"	on \
		UNIQUE	"Build with Unique-App support"	on

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 desktopfileutils
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -Wl,-rpath -Wl,${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS}"
SUB_FILES=	pkg-message

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

.include <bsd.port.options.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if !defined(WITHOUT_SSH)
BUILD_DEPENDS+=	${LOCALBASE}/include/libssh/libssh.h:${PORTSDIR}/security/libssh
RUN_DEPENDS+=	${LOCALBASE}/lib/libssh.so.4:${PORTSDIR}/security/libssh
.if ${OSVERSION} >= 800040
LDFLAGS+=	-fstack-protector
.endif
.else
CONFIGURE_ARGS+=--disable-ssh
.endif

.if !defined(WITHOUT_GCRYPT)
LIB_DEPENDS+=	gcrypt.17:${PORTSDIR}/security/libgcrypt
.else
CONFIGURE_ARGS+=--disable-gcrypt
.endif

.if !defined(WITHOUT_TERM)
USE_GNOME+=	vte
.else
CONFIGURE_ARGS+=--disable-vte
.endif

.if !defined(WITHOUT_AVAHI)
LIB_DEPENDS+=	avahi-ui.0:${PORTSDIR}/net/avahi-gtk
.else
CONFIGURE_ARGS+=--disable-avahi
.endif

.if !defined(WITHOUT_UNIQUE)
LIB_DEPENDS+=	unique-1.0.2:${PORTSDIR}/x11-toolkits/unique
.else
CONFIGURE_ARGS+=--disable-unique
.endif

post-install:
	@-update-desktop-database
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
