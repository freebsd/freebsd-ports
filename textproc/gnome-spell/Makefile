# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/textproc/gnome-spell/Makefile,v 1.13 2007/10/15 17:17:18 mezz Exp $

PORTNAME=	gnome-spell
PORTVERSION=	1.0.8
PORTREVISION=	9
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME/Bonobo component for spell checking

LIB_DEPENDS=	libaspell.so:textproc/aspell

USE_GNOME=	gnomeprefix intlhack libgnomeui
USES=		gettext gmake libtool pathfix pkgconfig perl5 tar:bzip2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB=	VERSION=${PORTVERSION}
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|@mkdir_p@|mkdir -p|g' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
