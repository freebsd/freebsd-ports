# ex:ts=8
# New ports collection makefile for:	minidom
# Date created:			Aug 13, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	minidom
PORTVERSION=	0.1.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.unibo.it/helm/mml-widget/sources/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		giconv:${PORTSDIR}/converters/libiconv

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
USE_GLIB=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e "s,-lglib,-lglib12,g ; \
		s,glib-config,${GLIB_CONFIG},g" ${WRKSRC}/configure.in

.include <bsd.port.mk>
