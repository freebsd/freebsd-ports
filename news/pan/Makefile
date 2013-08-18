# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/news/pan/Makefile,v 1.7 2008/01/19 22:45:42 mezz Exp $

PORTNAME=	pan
PORTVERSION=	0.139
PORTREVISION=	2
CATEGORIES=	news gnome
MASTER_SITES=	http://pan.rebelbase.com/download/releases/${PORTVERSION}/source/
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Threaded GTK+ newsreader based on Agent for Windows

LICENSE=	GPLv2

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre \
		gmime-2.6:${PORTSDIR}/mail/gmime26

USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		pathfix gettext
USE_GNOME=	intlhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgnuregex -liconv

OPTIONS_DEFINE=	GTKSPELL GTK3
OPTIONS_DEFAULT=GTKSPELL
GTKSPELL_DESC=	Spell checking support (gtk+2 only)
GTK3_DESC=	Use gtk+3 based UI instead of gtk+2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK3}
USE_GNOME+=	gtk30
CONFIGURE_ARGS+=--with-gtk3
.else
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=--without-gtk3
.endif

.if !${PORT_OPTIONS:MGTKSPELL} || ${PORT_OPTIONS:MGTK3}
CONFIGURE_ARGS+=	--without-gtkspell
.else
LIB_DEPENDS+=		gtkspell:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=	--with-gtkspell
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in"| ${XARGS} ${REINPLACE_CMD} -e \
		's|noinst_PROGRAMS = |noinst_PROGRAMS = #|g'

.include <bsd.port.mk>
