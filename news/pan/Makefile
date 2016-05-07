# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/news/pan/Makefile,v 1.7 2008/01/19 22:45:42 mezz Exp $

PORTNAME=	pan
PORTVERSION=	0.140
CATEGORIES=	news gnome
MASTER_SITES=	http://pan.rebelbase.com/download/releases/${PORTVERSION}/source/
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Threaded GTK+ newsreader based on Agent for Windows

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libgmime-2.6.so:mail/gmime26

USES=		gmake iconv pathfix pkgconfig tar:bzip2
USE_GNOME=	intlhack
USE_GCC=	any
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgnuregex ${ICONV_LIB}

OPTIONS_DEFINE=	GTKSPELL GNUTLS NLS
OPTIONS_RADIO=	GTK
OPTIONS_RADIO_GTK=	GTK2 GTK3
OPTIONS_SUB=	yes
OPTIONS_DEFAULT=GTKSPELL GNUTLS GTK2
GTKSPELL_DESC=	Spell checking support (gtk+2 only)

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=	pkgconfig
GNUTLS_CONFIGURE_WITH=	gnutls

GTK3_CONFIGURE_WITH=	gtk3
GTK3_USE=	gnome=gtk30

GTK2_USE=	gnome=gtk20

GTKSPELL_LIB_DEPENDS=	libgtkspell.so:textproc/gtkspell
GTKSPELL_CONFIGURE_WITH=	gtkspell

GTK3_PREVENTS=	GTKSPELL

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in"| ${XARGS} ${REINPLACE_CMD} -e \
		's|noinst_PROGRAMS = |noinst_PROGRAMS = #|g'

.include <bsd.port.mk>
