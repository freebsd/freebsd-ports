# New ports collection makefile for:	vidalia
# Date created:		2007-02-19
# Whom:			Fabian Keil <fk@fabiankeil.de>
#
# $FreeBSD$
#

PORTNAME=	vidalia
PORTVERSION=	0.0.14
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://www.vidalia-project.net:8001/vidalia/\
		http://tor.eff.org/dist/vidalia-bundles/

MAINTAINER=	fk@fabiankeil.de
COMMENT=	A graphical Tor controller based on Qt 4.x

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

HAS_CONFIGURE=	yes

USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui moc qmake rcc uic network xml linguist

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

post-extract:
	${REINPLACE_CMD} -e 's@/bin/lrelease@/bin/lrelease-qt4@' ${WRKSRC}/configure

post-configure:
.if defined(TOR_CONTROL_ADDR)
	 ${REINPLACE_CMD} -e 's@127\.0\.0\.1@${TOR_CONTROL_ADDR}@' ${WRKSRC}/src/config/torsettings.cpp
.endif
	 ${REINPLACE_CMD} -E -e 's@(INCPATH +=)@\1 -I${X11BASE}/include@' ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
