# ex:ts=8
# New ports collection makefile for:	minidom
# Date created:			Aug 13, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	minidom
PORTVERSION=	0.1.4
PORTREVISION=	0
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.unibo.it/helm/mml-widget/sources/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A minimal implementation of the Document Object Model

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	glib12
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-libxml2=yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lglib|-lglib12|g ; \
		 s|glib-config|${GLIB_CONFIG}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
