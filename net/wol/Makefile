# ex:ts=8
# Ports collection makefile for:	wol
# Date created:			Jan 10, 2001
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	wol
PORTVERSION=	0.6.0
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ahh

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl:${PORTSDIR}/devel/gettext-old \
		iconv.3:${PORTSDIR}/converters/libiconv \
		gnugetopt:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -liconv -lgnugetopt"

.include <bsd.port.mk>
