# New ports collection makefile for:	gtkspell2
# Date created:				19 Aug 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/textproc/gtkspell/Makefile,v 1.2 2006/09/10 00:51:13 mezz Exp $
#

PORTNAME=	gtkspell
PORTVERSION=	2.0.11
PORTREVISION?=	4
CATEGORIES=	textproc gnome
MASTER_SITES=	http://gtkspell.sourceforge.net/download/
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GTK+ 2 spell checking component

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	pspell.16:${PORTSDIR}/textproc/aspell

USE_AUTOTOOLS=	libtool:15
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|docs||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
