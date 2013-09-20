# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/textproc/gnome-spell/Makefile,v 1.13 2007/10/15 17:17:18 mezz Exp $

PORTNAME=	gnome-spell
PORTVERSION=	1.0.8
PORTREVISION=	7
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME/Bonobo component for spell checking

LIB_DEPENDS=	aspell.16:${PORTSDIR}/textproc/aspell

USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui
USES=		gettext gmake pkgconfig perl5
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB=	VERSION=${PORTVERSION}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|@mkdir_p@|mkdir -p|g' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
