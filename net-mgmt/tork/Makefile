# Created by: Beat Gätzi <beat@chruetertee.ch>
# $FreeBSD$

PORTNAME=	tork
PORTVERSION=	0.30
PORTREVISION=	5
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

.include "${PORTSDIR}/Mk/bsd.commands.mk"

HAVE_TOR!=	${PKG_INFO} -I tor-\* >/dev/null 2>&1 && ${ECHO_CMD} YES || ${ECHO_CMD} NO

.if ${HAVE_TOR} == "YES"
HAVE_TOR_DEVEL!=	${PKG_INFO} -I tor-devel\* >/dev/null 2>&1 && ${ECHO_CMD} YES || ${ECHO_CMD} NO

.if ${HAVE_TOR_DEVEL} == "YES"
OPTIONS_DEFINE=	TOR_DEVEL
OPTIONS_DEFAULT=	TOR_DEVEL
TOR_DEVEL_DESC=		Depend on tor-devel (already installed)
.else
OPTIONS_DEFINE=	TOR
OPTIONS_DEFAULT=	TOR
TOR_DESC=		Depend on tor (already installed)
.endif

.else
OPTIONS_SINGLE=	TOR_PORT
OPTIONS_SINGLE_TOR_PORT=	TOR_DEVEL TOR
OPTIONS_DEFAULT=	TOR_DEVEL
TOR_DEVEL_DESC=	Depend on tor-devel
TOR_DESC=	Depend on tor
.endif

OPTIONS_DEFINE+=	PRIVOXY MIXMINION
OPTIONS_DEFAULT+=	PRIVOXY
PRIVOXY_DESC=	Install privoxy
MIXMINION_DESC=	Install mixminion

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOR_DEVEL}
RUN_DEPENDS+=	${LOCALBASE}/bin/tor:${PORTSDIR}/security/tor-devel
.if ${PORT_OPTIONS:MTOR}
RUN_DEPENDS+=	${LOCALBASE}/bin/tor:${PORTSDIR}/security/tor
.endif

.if ${PORT_OPTIONS:MPRIVOXY}
RUN_DEPENDS+=	${LOCALBASE}/sbin/privoxy:${PORTSDIR}/www/privoxy
.endif

.if ${PORT_OPTIONS:MMIXMINION}
RUN_DEPENDS+=	${LOCALBASE}/bin/mixminion:${PORTSDIR}/mail/mixminion
.endif

.include <bsd.port.mk>
