# ex:ts=8
# New ports collection makefile for:	ickle
# Date created:			Nov 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ickle
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	ICQ2000 protocol implementation

LIB_DEPENDS=	gtkmm:${PORTSDIR}/x11-toolkits/gtk-- \
		iconv.3:${PORTSDIR}/converters/libiconv \
		icq2000.5:${PORTSDIR}/net/libicq2000

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
WANT_GNOME=	yes
USE_REINPLACE=	yes
USE_SIZE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
CONFIGURE_ARGS=	--with-sigc-prefix=${LOCALBASE} \
		--with-gtkmm-prefix=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="`${LOCALBASE}/bin/sigc-config --cflags`"

post-patch:
	@${REINPLACE_CMD} -E -e 's|(gtkmm_config_args[[:space:]]*=).+$$|\1|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibcapplet}!="" || defined(WITH_GNOME)
USE_GNOME+=	libcapplet
PKGNAMESUFFIX=	-gnome
PLIST_SUB+=	ICKLEDATADIR="share/gnome/" GNOME="" NOGNOME="@comment "
.else
CONFIGURE_ARGS+=	--with-gnome=no

PLIST_SUB+=	ICKLEDATADIR="share/" GNOME="@comment " NOGNOME=""
.endif

.if defined(WITH_ICKLE_CONTROL)
PLIST_SUB+=	ICKLECONTROL=""
.else
CONFIGURE_ARGS+=	--without-ickle-control

PLIST_SUB+=	ICKLECONTROL="@comment "
.endif

pre-everything::
.if ${HAVE_GNOME:Mlibcapplet}=="" && !defined(WITH_GNOME)
	@${ECHO_MSG} "===> Define WITH_GNOME		to enable GNOME support"
.endif
.if !defined(WITH_ICKLE_CONTROL)
	@${ECHO_MSG} "===> Define WITH_ICKLE_CONTROL	to enable external command-line"
	@${ECHO_MSG} "===>				control for the ickle client"
.endif

.include <bsd.port.post.mk>
