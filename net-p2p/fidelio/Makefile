# New ports collection makefile for:	fidelio
# Date created:				13 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fidelio
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext \
		xml2.5:${PORTSDIR}/textproc/libxml2

XML_CONFIG?=	${LOCALBASE}/bin/xml2-config

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/libxml2 \
			  -I${LOCALBASE}/include \
			  `${GLIB_CONFIG} --cflags gthread`" \
		LDFLAGS="-L${LOCALBASE}/lib `${GLIB_CONFIG} --libs gthread`" \
		XML_CONFIG="${XML_CONFIG}"
CONFIGURE_ARGS=	--without-included-gettext
CFLAGS+=	-DHAVE_STRCASESTR

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\$$(datadir)/gnome/|\$$(datadir)/|g ; \
		 s|\$$(datadir)/locale|\$$(prefix)/share/locale|g'
	@${REINPLACE_CMD} -e 's|-lxml|-lxml2|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|extern int strcasestr|//extern int strcasestr|' \
		${WRKSRC}/src/trackers.c

.include <bsd.port.mk>
