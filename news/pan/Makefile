# New ports collection makefile for:	pan2
# Date created:				19 August 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/news/pan/Makefile,v 1.7 2008/01/19 22:45:42 mezz Exp $
#

PORTNAME=	pan
PORTVERSION=	0.135
PORTREVISION=	1
CATEGORIES=	news gnome
MASTER_SITES=	http://pan.rebelbase.com/download/releases/${PORTVERSION}/source/
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Threaded GTK+ newsreader based on Agent for Windows

LICENSE=	GPLv2

LIB_DEPENDS=	pcre.1:${PORTSDIR}/devel/pcre \
		gmime-2.4.6:${PORTSDIR}/mail/gmime24

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgnuregex

OPTIONS=	GTKSPELL "Enable spell checking support (gtk+2 only)" on \
		GTK3 "Build with gtk+3 based UI instead of gtk+2" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GTK3)
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=--without-gtk3
.else
USE_GNOME+=	gtk30
CONFIGURE_ARGS+=--with-gtk3
.endif

.if defined(WITHOUT_GTKSPELL) || defined(WITH_GTK3)
CONFIGURE_ARGS+=	--without-gtkspell
.else
LIB_DEPENDS+=		gtkspell.0:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=	--with-gtkspell
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in"| ${XARGS} ${REINPLACE_CMD} -e \
		's|noinst_PROGRAMS = |noinst_PROGRAMS = #|g'

.include <bsd.port.post.mk>
