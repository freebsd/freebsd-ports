# New ports collection makefile for:	gnomemimedata
# Date created:				22 January 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/misc/gnome-mime-data/Makefile,v 1.14 2007/05/22 04:59:18 marcus Exp $

PORTNAME=	gnome-mime-data
PORTVERSION=	2.18.0
PORTREVISION=	4
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DISTNAME=	gnome-mime-data-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A MIME and Application database for GNOME

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnometarget pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

post-patch:
	@${REINPLACE_CMD} -e 's|[(]datadir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
	    	${WRKSRC}/Makefile.in

.include <bsd.port.mk>
