# ex:ts=8
# New ports collection makefile for:	ickle
# Date created:			Nov 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ickle
PORTVERSION=	0.2.2
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	troff@paranoia.ru

LIB_DEPENDS=	gtkmm:${PORTSDIR}/x11-toolkits/gtk--

WANT_GNOME=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
CONFIGURE_ARGS=	--with-sigc-prefix=${LOCALBASE} \
		--with-gtkmm-prefix=${X11BASE}

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME) || defined(WITH_GNOME)
USE_GNOME=	yes

PLIST_SUB+=	ICKLEDATADIR="share/gnome/" GNOME="" NOGNOME="@comment "
.else
CONFIGURE_ARGS+=	--with-gnome=no

PLIST_SUB+=	ICKLEDATADIR="share/" GNOME="@comment " NOGNOME=""
.endif

pre-everything::
.if !defined(HAVE_GNOME) && !defined(WITH_GNOME)
	@${ECHO_MSG} "===> Define WITH_GNOME		to enable GNOME support"
.endif

.include <bsd.port.post.mk>
