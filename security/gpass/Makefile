# Created by: ports@c0decafe.net <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	gpass
PORTVERSION=	0.5.1
PORTREVISION=	10
CATEGORIES=	security gnome
MASTER_SITES=	http://projects.netlab.jp/gpass/release/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Password manager for GNOME2

LIB_DEPENDS=	mcrypt:${PORTSDIR}/security/mcrypt \
		mhash:${PORTSDIR}/security/mhash

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -export-dynamic

MAN1=		gpass.1 gpass.ja.1 gpass-convert.1 gpass-convert.ja.1

USES=        pathfix gmake pkgconfig
USE_GNOME=	gnomeprefix gtk20 libgnomeui intltool libglade2
GCONF_SCHEMAS=	gpass.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|{packageprefix}/share|{datadir}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/include/gpass/error.h \
		${WRKSRC}/src/helper.h

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
