# New ports collection makefile for:   dillo
# Date created:        23 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=       dillo
PORTVERSION=	0.6.6
CATEGORIES=     www
MASTER_SITES=	http://dillo.auriga.wearlab.de/download/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		intl.4:${PORTSDIR}/devel/gettext

USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--includedir="${LOCALBASE}/include" \
			--libdir="${LOCALBASE}/lib" \
			--with-jpeg-inc="${LOCALBASE}/include"
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"
USE_GMAKE=	yes

post-patch:
	${PERL} -pi -e "s@-D_REENTRANT -D_THREAD_SAFE@@" ${WRKSRC}/configure
	${PERL} -pi -e "s@dillorc@dillorc.sample@g" ${WRKSRC}/Makefile.in
	${MV} ${WRKSRC}/dillorc ${WRKSRC}/dillorc.sample
	${PERL} -pi -e "s@/usr/local/etc/dillorc@${PREFIX}/etc/dillorc@g" \
		${WRKSRC}/src/prefs.c

.include <bsd.port.mk>
