# New ports collection makefile for:	gnomesystemtools
# Date created:				17 May 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomesystemtools
PORTVERSION=	0.91.0
PORTREVISION=	3
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-system-tools/0.91
DISTNAME=	gnome-system-tools-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to configure workstations

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack libgnomeui
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
CONFIGURE_ARGS+=	--enable-services
PLIST_SUB+=		SERVICES=""
.else
PLIST_SUB+=		SERVICES="@comment "
.endif

.include <bsd.port.post.mk>
