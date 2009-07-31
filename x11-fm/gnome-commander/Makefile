# New ports collection makefile for:	gnomem-commander
# Date created:		23 April 2002
# Whom:			Edgardo Garcia Hoeffler <edybsd@yahoo.com.ar>
#
# $FreeBSD$
#

PORTNAME=	gnome-commander
PORTVERSION=	1.0.1
PORTREVISION=	7
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File manager for Gnome

.if defined(WITH_FAM)
LIB_DEPENDS=	fam.0:${PORTSDIR}/devel/fam
.else
CONFIGURE_ARGS=	--without-fam
.endif

CONFLICTS=	gnome-commander2-*

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget gnomevfs gnomelibs gdkpixbuf
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

pre-everything::
.if !defined(WITH_FAM)
	@${ECHO} ""
	@${ECHO} "	Define WITH_FAM to add support for the"
	@${ECHO} "	'file alteration monitor' fam"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
