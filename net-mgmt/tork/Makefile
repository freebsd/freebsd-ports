# New ports collection makefile for:    tork
# Date created:                         09 Feb 2008
# Whom:                                 Beat Gätzi <beat@chruetertee.ch>
#
# $FreeBSD$
#

PORTNAME=	tork
PORTVERSION=	0.30
PORTREVISION=	4
CATEGORIES=	net-mgmt security
MASTER_SITES=	SF/${PORTNAME}/TorK%20Source%20Tarball/TorK-${PORTVERSION}

MAINTAINER=	thomas.sander@gmx.de
COMMENT=	TorK is an Anonymity Manager for the KDE Desktop

USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	libtool:22 aclocal:19
USE_GETTEXT=	yes
USE_XORG=	xext
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

USE_KDELIBS_VER=3
USE_QT_VER=	3

MAN1=		tork.1 torkarkollon.1 torkify.1 torksocks.1
MAN5=		torksocks.conf.5
MAN8=		torksocks.8

HAVE_TOR!=	if pkg_info -I tor-\* >/dev/null 2>&1 ; then ${ECHO} YES; fi

.if (${HAVE_TOR} == "YES")
HAVE_TOR_DEVEL!=	if pkg_info -I tor-devel\* >/dev/null 2>&1 ; then ${ECHO} YES; fi

.if (${HAVE_TOR_DEVEL} == "YES")
OPTIONS=	TOR_DEVEL	"Depend on tor-devel (already installed)"   On
.else
OPTIONS=	TOR	"Depend on tor (already installed)" On
.endif

.else
OPTIONS=	TOR_DEVEL	"Depend on tor-devel"   On \
		TOR	"Depend on tor"     Off
.endif

OPTIONS+=	PRIVOXY	"Install privoxy"	On \
		MIXMINION "Install mixminion"	Off

.include <bsd.port.pre.mk>

.if defined(WITH_TOR_DEVEL)
.if defined(WITH_TOR)
IGNORE=			cannot depend on tor and tor-devel at the same time
.endif
RUN_DEPENDS+=	${LOCALBASE}/bin/tor:${PORTSDIR}/security/tor-devel
.elif defined(WITH_TOR)
RUN_DEPENDS+=	${LOCALBASE}/bin/tor:${PORTSDIR}/security/tor
.endif

.if defined(WITH_PRIVOXY)
RUN_DEPENDS+=	${LOCALBASE}/sbin/privoxy:${PORTSDIR}/www/privoxy
.endif

.if defined(WITH_MIXMINION)
RUN_DEPENDS+=	${LOCALBASE}/bin/mixminion:${PORTSDIR}/mail/mixminion
.endif

.include <bsd.port.post.mk>
