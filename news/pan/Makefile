# New ports collection makefile for:	pan2
# Date created:				19 August 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/news/pan/Makefile,v 1.7 2008/01/19 22:45:42 mezz Exp $
#

PORTNAME=	pan
PORTVERSION=	0.133
PORTREVISION=	1
CATEGORIES=	news gnome
MASTER_SITES=	http://pan.rebelbase.com/download/releases/${PORTVERSION}/source/
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Threaded GTK+2 newsreader based on Agent for Windows

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		gmime-2.0.4:${PORTSDIR}/mail/gmime2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget gtk20 intlhack
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex"

OPTIONS=	GTKSPELL "Enable spell checking support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GTKSPELL)
CONFIGURE_ARGS+=	--without-gtkspell
.else
LIB_DEPENDS+=		gtkspell.0:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=	--with-gtkspell
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in"| ${XARGS} ${REINPLACE_CMD} -e \
		's|noinst_PROGRAMS = |noinst_PROGRAMS = #|g'

.include <bsd.port.post.mk>
