# New ports collection makefile for:	nautilus-cd-burner
# Date created:				13 April 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nautilus-cd-burner
PORTVERSION=	0.5.3
PORTREVISION=	7
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.5
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD burner view for Nautilus

RUN_DEPENDS=	mkisofs:${PORTSDIR}/sysutils/mkisofs \
		cdrecord:${PORTSDIR}/sysutils/cdrtools

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack nautilus2
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
