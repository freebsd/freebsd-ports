# New ports collection makefile for:	shared-mime-info
# Date created:        31 May 2002
# Whom:                olgeni@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	shared-mime-info
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	misc gnome
MASTER_SITES=	http://www.marcuscom.com/downloads/ \
		http://www.freedesktop.org/software/shared-mime-info/
DISTNAME=	shared-mime-info-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A MIME type database from the FreeDesktop project

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GNOME=	glib20 libxml2 intltool gnomehack

MAN1=		update-mime-database.1

MIMEDIRS=	${X11BASE}/share/gnome/mime \
		${LOCALBASE}/share/gnome/mime \
		${X11BASE}/share/mime \
		${LOCALBASE}/share/mime \
		/usr/share/mime

post-patch:
	@${REINPLACE_CMD} -e 's|%%MIMEDIRS%%|${MIMEDIRS}|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/update-mime-database.c

.include <bsd.port.mk>
