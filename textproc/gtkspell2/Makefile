# New ports collection makefile for:	gtkspell2
# Date created:				19 Aug 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkspell2
PORTVERSION=	2.0.4
PORTREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	http://gtkspell.sourceforge.net/download/
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GTK+ 2 spell checking component

LIB_DEPENDS=	pspell.15:${PORTSDIR}/textproc/aspell

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
