# ex:ts=8
# Ports collection makefile for:	wol
# Date created:			Jan 10, 2001
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	wol
PORTVERSION=	0.5.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ahh

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl:${PORTSDIR}/devel/gettext \
		giconv:${PORTSDIR}/converters/libiconv \
		gnugetopt:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgiconv -lgnugetopt"

post-patch:
	@${PERL} -pi -e "s/iconv.h/giconv.h/g" ${WRKSRC}/configure

.include <bsd.port.mk>
