# New ports collection makefile for:	pan2
# Date created:				19 August 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pan2
PORTVERSION=	0.14.2
PORTREVISION=	2
CATEGORIES=	news gnome
MASTER_SITES=	http://pan.rebelbase.com/download/releases/${PORTVERSION}/SOURCE/ \
		http://pan.rebelbase.com/download/obsolete/${PORTVERSION}/SOURCE/
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Threaded GNOME 2 newsreader based on Agent for Windows

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2 \
		gnet-2.0.0:${PORTSDIR}/net/gnet2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex -lcompat"

.include <bsd.port.mk>
