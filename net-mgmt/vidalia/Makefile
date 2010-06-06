# New ports collection makefile for:	vidalia
# Date created:		2007-02-19
# Whom:			Fabian Keil <fk@fabiankeil.de>
#
# $FreeBSD$
#

PORTNAME=	vidalia
PORTVERSION=	0.2.9
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://www.torproject.org/vidalia/dist/

MAINTAINER=	fk@fabiankeil.de
COMMENT=	A graphical Tor controller based on Qt 4.x

USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
INSTALLS_ICONS=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build qmake_build rcc_build uic_build network xml linguist_build
MAKE_JOBS_SAFE=	yes

HAVE_TOR!=	if pkg_info -I tor-\* >/dev/null 2>&1 ; then ${ECHO} YES; fi

.if (${HAVE_TOR} == "YES")
HAVE_TOR_DEVEL!=	if pkg_info -I tor-devel\* >/dev/null 2>&1 ; then ${ECHO} YES; fi

.if (${HAVE_TOR_DEVEL} == "YES")
OPTIONS=	TOR_DEVEL	"Depend on tor-devel (already installed)"	On
.else
OPTIONS=	TOR		"Depend on tor (already installed)"	On
.endif

.else

OPTIONS=	TOR_DEVEL	"Depend on tor-devel"	On \
		TOR		"Depend on tor"		Off

.endif

.include <bsd.port.pre.mk>

.if defined(WITH_TOR_DEVEL)
.if defined(WITH_TOR)
IGNORE=		cannot depend on tor and tor-devel at the same time
.endif
RUN_DEPENDS+=	${LOCALBASE}/bin/tor:${PORTSDIR}/security/tor-devel
.elif defined(WITH_TOR)
RUN_DEPENDS+=	${LOCALBASE}/bin/tor:${PORTSDIR}/security/tor
.endif

.include <bsd.port.post.mk>
