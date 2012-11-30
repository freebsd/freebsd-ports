# New ports collection makefile for:	link-monitor-applet
# Date created:			27 Jul 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	link-monitor-applet
PORTVERSION=	3.0
CATEGORIES=	net ipv6
MASTER_SITES=	SAVANNAH/${PORTNAME:S/-applet//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME applet displaying the round-trip time to one or more hosts

LICENSE=	GPLv3

BUILD_DEPENDS=	gob2:${PORTSDIR}/devel/gob2
LIB_DEPENDS=	GeoIP:${PORTSDIR}/net/GeoIP

USE_BZIP2=	yes
USE_GNOME=	gnomepanel gnomeprefix libgnomeui librsvg2 
USE_GETTEXT=	yes
INSTALLS_OMF=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	link-monitor-applet.schemas

do-configure:
	@(cd ${WRKSRC} && ${SH} jb configure cc="${CC}" cflags="${CFLAGS}" \
		cppflags="${CPPFLAGS}" ldflags="${LDFLAGS}" \
		libdir="${PREFIX}/libdata" prefix="${PREFIX}")

do-build:
	@(cd ${WRKSRC} && ${SH} jb build)
	
do-install:
	@(cd ${WRKSRC} && ${SH} jb install)

.include <bsd.port.mk>
