# New ports collection makefile for:	gtkspell2
# Date created:				19 Aug 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/textproc/gtkspell/Makefile,v 1.2 2006/09/10 00:51:13 mezz Exp $
#

PORTNAME=	gtkspell
PORTVERSION=	2.0.16
PORTREVISION?=	3
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	marcus

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GTK+ 2 spell checking component

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	enchant.1:${PORTSDIR}/textproc/enchant

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20 intlhack
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|docs||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
