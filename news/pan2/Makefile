# New ports collection makefile for:	pan2
# Date created:				19 August 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pan2
PORTVERSION=	0.14.0.91
CATEGORIES=	news gnome
MASTER_SITES=	http://pan.rebelbase.com/download/releases/${PORTVERSION}/SOURCE/ \
		http://pan.rebelbase.com/download/obsolete/${PORTVERSION}/SOURCE/ \
		${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/0.14
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Threaded GNOME 2 newsreader based on Agent for Windows

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2 \
		gnet-glib2.7:${PORTSDIR}/net/gnet-glib2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget libxml2
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex -lcompat"
CONFIGURE_ARGS=	--enable-html

post-patch:
	@${REINPLACE_CMD} -e 's|gnet-config|gnet-glib2-config|g ; \
		 s|gnet/gnet\.h|gnet-glib2/gnet.h|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|gnet/gnet\.h|gnet-glib2/gnet.h|g; s|<regex.h>|<gnuregex.h>|'

.include <bsd.port.mk>
