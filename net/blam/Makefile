# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	blam
PORTVERSION=	1.8.7
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://www.cmartin.tk/${PORTNAME}/ \
		http://romain.blogreen.org/distfiles/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	A simple feed reader for GNOME

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/webkit-sharp-1.0.pc:${PORTSDIR}/www/webkit-sharp
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GMSGFMT="${LOCALBASE}/bin/msgfmt" DATADIRNAME="share"
USE_GNOME=	gnomesharp20
USES=		gettext gmake pkgconfig
INSTALLS_ICONS=	yes
GCONF_SCHEMAS=	blam.schemas

MAN1=		blam.1

NO_STAGE=	yes
.include <bsd.port.mk>
