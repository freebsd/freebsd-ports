# New ports collection makefile for:	coaster
# Date created:				11 Nov 2004
# Whom:					Mezz <mezz7@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	coaster
PORTVERSION=	0.1.4.2
PORTREVISION=	1
CATEGORIES=	sysutils gnome
#MASTER_SITES=	http://www.coaster-burn.org/files/coaster/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mezz

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A disc burning application for Gnome 2

LIB_DEPENDS=	gconfmm-2.6:${PORTSDIR}/devel/gconfmm26 \
		glademm-2.4:${PORTSDIR}/devel/libglademm24 \
		gnomevfsmm-2.6:${PORTSDIR}/devel/gnome-vfsmm \
		xml\\+\\+-2.6:${PORTSDIR}/textproc/libxml++26

USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack desktopfileutils \
		nautiluscdburner
USE_GCC=	3.4
USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=		AUTHORS COPYING ChangeLog NEWS README TODO
GCONF_SCHEMAS=	coaster.schemas

post-install:
	@-update-desktop-database
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
