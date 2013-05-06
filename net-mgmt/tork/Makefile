# Created by: Beat Gätzi <beat@chruetertee.ch>
# $FreeBSD$

PORTNAME=	tork
PORTVERSION=	0.30
PORTREVISION=	6
CATEGORIES=	net-mgmt security
MASTER_SITES=	SF/${PORTNAME}/TorK%20Source%20Tarball/TorK-${PORTVERSION}

MAINTAINER=	thomas.sander@gmx.de
COMMENT=	TorK is an Anonymity Manager for the KDE Desktop

USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	libtool aclocal:env
USES=		gettext
USE_XORG=	xext
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
AUTOTOOLSFILES=	aclocal.m4

USE_KDELIBS_VER=3
USE_QT_VER=	3

MAN1=		tork.1 torkarkollon.1 torkify.1 torksocks.1
MAN5=		torksocks.conf.5
MAN8=		torksocks.8

OPTIONS_DEFINE=		PRIVOXY

PRIVOXY_DESC=		Install privoxy

OPTIONS_SINGLE=		TOR
OPTIONS_SINGLE_TOR=	TOR_STD TOR_DEVEL

TOR_STD_DESC=		Use stable security/tor port
TOR_DEVEL_DESC=		Use development security/tor-devel port

OPTIONS_DEFAULT=	TOR_STD PRIVOXY

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOR_STD}
RUN_DEPENDS+=	${LOCALBASE}/bin/tor:${PORTSDIR}/security/tor
.else
RUN_DEPENDS+=	${LOCALBASE}/share/tor/geoip6:${PORTSDIR}/security/tor-devel
.endif

.if ${PORT_OPTIONS:MPRIVOXY}
RUN_DEPENDS+=	${LOCALBASE}/sbin/privoxy:${PORTSDIR}/www/privoxy
.endif

.include <bsd.port.mk>
