# New ports collection makefile for:   dillo
# Date created:        23 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=       dillo
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=     www
MASTER_SITES=   http://dillo.cipsga.org.br/download/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	anders@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		intl.2:${PORTSDIR}/devel/gettext

USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--includedir="${LOCALBASE}/include" \
			--libdir="${LOCALBASE}/lib" \
			--with-jpeg-inc="${LOCALBASE}/include"
USE_GMAKE=	yes

post-patch:
	${PERL} -pi -e "s@-lpthread@${PTHREAD_LIBS}@g" ${WRKSRC}/configure

.include <bsd.port.mk>
