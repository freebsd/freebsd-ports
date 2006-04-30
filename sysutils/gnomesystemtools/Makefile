# New ports collection makefile for:	gnomesystemtools
# Date created:				17 May 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnomesystemtools/Makefile,v 1.40 2006/04/13 07:52:38 bland Exp $
#

PORTNAME=	gnomesystemtools
PORTVERSION=	2.14.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-system-tools/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-system-tools-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to configure workstations

BUILD_DEPENDS=	${X11BASE}/share/setup-tool-backends/scripts/xml.pl:${PORTSDIR}/sysutils/system-tools-backends
RUN_DEPENDS=	${X11BASE}/share/setup-tool-backends/scripts/xml.pl:${PORTSDIR}/sysutils/system-tools-backends

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack nautilus2
USE_AUTOTOOLS=	libtool:15
INSTALLS_OMF=	yes
CONFIGURE_ARGS=	--enable-services
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-system-tools.schemas

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	uses symbols not present in 4.X
.endif

.include <bsd.port.post.mk>
