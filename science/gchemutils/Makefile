# New ports collection makefile for:	gchemutils
# Date created:			Mar 18, 2003
# Whom:				Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$

PORTNAME=	gchemutils
PORTVERSION=	0.8.1
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}/0.8
DISTNAME=	gnome-chemistry-utils-${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	C++ classes and Gtk2 widgets related to chemistry

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext \
		openbabel.3:${PORTSDIR}/science/openbabel \
		goffice-0.4:${PORTSDIR}/devel/goffice
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/bodr.pc:${PORTSDIR}/science/bodr \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:${PORTSDIR}/science/chemical-mime-data
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/bodr.pc:${PORTSDIR}/science/bodr \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:${PORTSDIR}/science/chemical-mime-data

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack intlhack libglade2 libgnomeprintui libgnomeui gnomedocutils
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"
INSTALLS_ICONS=	yes
GCONF_SCHEMAS=	gcrystal.schemas

MAN1=		gchem3d-viewer.1 gchemcalc.1 gchemtable.1 gcrystal.1
MAN3=		libgcu.3

OPTIONS=	MOZILLA "Build mozilla plugin" off

.include <bsd.port.pre.mk>

.if defined(WITH_MOZILLA)
USE_GECKO=	mozilla
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
CONFIGURE_ARGS+=--enable-mozilla-plugin
PLIST_SUB=	MOZILLA=""
.else
CONFIGURE_ARGS+=--disable-mozilla-plugin
PLIST_SUB=	MOZILLA="@comment "
.endif

.include <bsd.port.post.mk>
