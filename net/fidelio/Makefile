# New ports collection makefile for:	fidelio
# Date created:				13 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fidelio
PORTVERSION=	0.9.6
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		xml2.5:${PORTSDIR}/textproc/libxml2

XML_CONFIG?=	${LOCALBASE}/bin/xml2-config

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

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'
	@${PERL} -pi -e 's|-lxml|-lxml2|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
