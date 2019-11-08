# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/misc/gnome-mime-data/Makefile,v 1.14 2007/05/22 04:59:18 marcus Exp $

PORTNAME=	gnome-mime-data
PORTVERSION=	2.18.0
PORTREVISION=	5
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MIME and Application database for GNOME

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake gnome localbase pathfix tar:bzip2
USE_GNOME=	gnomeprefix intlhack
GNU_CONFIGURE=	yes
LIBS+=		-lintl

.include <bsd.port.mk>
