# New ports collection makefile for:	pan2
# Date created:				19 August 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pan2
PORTVERSION=	0.14.2.91
PORTREVISION=	4
CATEGORIES=	news gnome
MASTER_SITES=	http://pan.rebelbase.com/download/releases/${PORTVERSION}/SOURCE/ \
		http://pan.rebelbase.com/download/obsolete/${PORTVERSION}/SOURCE/
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Threaded GNOME 2 newsreader based on Agent for Windows

LIB_DEPENDS=	gnet-2.0.0:${PORTSDIR}/net/gnet2 \
		pcre.0:${PORTSDIR}/devel/pcre-utf8

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget libxml2 gtk20
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex"

OPTIONS=	GTKSPELL "Enable spell checking support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GTKSPELL)
CONFIGURE_ARGS+=	--disable-gtkspell
.else
LIB_DEPENDS+=		gtkspell.0:${PORTSDIR}/textproc/gtkspell2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|apps/Internet|applications|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
