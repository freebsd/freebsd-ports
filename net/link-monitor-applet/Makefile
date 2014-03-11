# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	link-monitor-applet
PORTVERSION=	3.0
CATEGORIES=	net ipv6
MASTER_SITES=	SAVANNAH/${PORTNAME:S/-applet//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME applet displaying the round-trip time to one or more hosts

LICENSE=	GPLv3

DEPRECATED=	gnome-panel 2.x will be updated in the GNOME 3 import 
EXPIRATION_DATE=2014-04-10
BROKEN=		Does not build

BUILD_DEPENDS=	gob2:${PORTSDIR}/devel/gob2
LIB_DEPENDS=	GeoIP:${PORTSDIR}/net/GeoIP

USE_BZIP2=	yes
USE_GNOME=	gnomepanel gnomeprefix libgnomeui librsvg2 
USES=		gettext
INSTALLS_OMF=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	link-monitor-applet.schemas

NO_STAGE=	yes
do-configure:
	@(cd ${WRKSRC} && ${SH} jb configure cc="${CC}" cflags="${CFLAGS}" \
		cppflags="${CPPFLAGS}" ldflags="${LDFLAGS}" \
		libdir="${PREFIX}/libdata" prefix="${PREFIX}")

do-build:
	@(cd ${WRKSRC} && ${SH} jb build)
	
do-install:
	@(cd ${WRKSRC} && ${SH} jb install)

.include <bsd.port.mk>
