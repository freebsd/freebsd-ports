# New ports collection makefile for:    pilot-link
# Date created:         November, 1997
# Whom:                 Paul Traina <pst@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pilot-link
PORTVERSION=	0.11.7
CATEGORIES=	palm comms tk83
MASTER_SITES=	http://www.pilot-link.org/source/

MAINTAINER=	dima@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		tk83:${PORTSDIR}/x11-toolkits/tk83 \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_PERL5=	yes

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.3
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-perl5=${PERL5} --with-libiconv=${LOCALBASE}
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
MAKE_ARGS+=	LIBTOOL=libtool

.include "${.CURDIR}/manpages.mk"

.include <bsd.port.mk>
