# New ports collection makefile for:	blam
# Date created:				20040812
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.22 2006/10/26 05:32:53 tmclau02 Exp $
#

PORTNAME=	blam
PORTVERSION=	1.8.6
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.cmartin.tk/${PORTNAME}/ \
		http://romain.blogreen.org/distfiles/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	A simple feed reader for GNOME

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext \
		${LOCALBASE}/libdata/pkgconfig/webkit-sharp-1.0.pc:${PORTSDIR}/www/webkit-sharp
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/webkit-sharp-1.0.pc:${PORTSDIR}/www/webkit-sharp

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	GMSGFMT="${LOCALBASE}/bin/msgfmt" DATADIRNAME="share"
USE_GNOME=	gnomesharp20
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
GCONF_SCHEMAS=	blam.schemas

MAN1=		blam.1

.include <bsd.port.mk>
