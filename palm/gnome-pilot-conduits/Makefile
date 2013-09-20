# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-pilot-conduits
PORTVERSION=	2.0.17
PORTREVISION=	5
CATEGORIES=	palm comms gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.0
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional conduits for gnome-pilot

LIB_DEPENDS=	gpilotd.2:${PORTSDIR}/palm/gnome-pilot

USE_BZIP2=	yes
USES=		bison pathfix gettext gmake pkgconfig
USE_GNOME=	gnomeprefix libgnome
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pisock=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/mal-conduit/mal/client/unix/MAL31DBConfig.c
	@${REINPLACE_CMD} -e 's|@mkdir_p@|mkdir -p|g' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
