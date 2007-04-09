# New ports collection makefile for:	gchemutils
# Date created:			Mar 18, 2003
# Whom:				Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$

PORTNAME=	gchemutils
PORTVERSION=	0.6.5
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}/0.6
DISTNAME=	gnome-chemistry-utils-${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	C++ classes and Gtk2 widgets related to chemistry

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext \
		openbabel.1:${PORTSDIR}/science/openbabel \
		goffice-1.2:${PORTSDIR}/devel/goffice1

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libglade2 libgnomeprintui libgnomeui
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

MAN1=		gchem3d-viewer.1 gchemcalc.1 gchemtable.1
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
