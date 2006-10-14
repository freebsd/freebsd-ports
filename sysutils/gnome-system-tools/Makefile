# New ports collection makefile for:	gnomesystemtools
# Date created:				17 May 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-system-tools/Makefile,v 1.45 2006/07/27 00:40:38 marcus Exp $
#

PORTNAME=	gnome-system-tools
PORTVERSION=	2.14.0
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-system-tools/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-system-tools-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to configure workstations

BUILD_DEPENDS=	${LOCALBASE}/share/setup-tool-backends/scripts/xml.pl:${PORTSDIR}/sysutils/system-tools-backends
RUN_DEPENDS=	${LOCALBASE}/share/setup-tool-backends/scripts/xml.pl:${PORTSDIR}/sysutils/system-tools-backends

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
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
