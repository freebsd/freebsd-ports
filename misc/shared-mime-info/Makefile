# New ports collection makefile for:	shared-mime-info
# Date created:        31 May 2002
# Whom:                olgeni@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	shared-mime-info
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	misc gnome
MASTER_SITES=	http://www.freedesktop.org/software/shared-mime-info/
DISTNAME=	shared-mime-info-${PORTVERSION}

PATCH_SITES=	${MASTER_SITE_LOCAL} \
		http://people.FreeBSD.org/~marcus/
PATCH_SITE_SUBDIR=	marcus
PATCHFILES=	patch-freedesktop.org.xml

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A MIME type database from the FreeDesktop project

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GNOME=	glib20 libxml2 intltool

MAN1=		update-mime-database.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/update-mime-database.c

.include <bsd.port.mk>
