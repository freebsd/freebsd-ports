# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/print/ggv/Makefile,v 1.8 2007/09/24 19:40:45 mezz Exp $

PORTNAME=	ggv
PORTVERSION=	2.12.0
PORTREVISION=	11
CATEGORIES=	print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 ghostscript viewer

INSTALLS_OMF=	yes
USE_GNOME=	gnomeprefix intlhack libgnomeui
USES=		desktop-file-utils gettext ghostscript:x11 gmake libtool \
		pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm
INSTALL_TARGET=	install-strip

GCONF_SCHEMAS=	ggv.schemas

post-patch:
	@${REINPLACE_CMD} '/^LIBS =/s/=.*/= @LIBS@/' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
