# ex:ts=8
# Ports collection makefile for:	ccrypt
# Date created:			Feb 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ccrypt
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://quasar.mathstat.uottawa.ca/~selinger/ccrypt/download/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

MAN1=	ccrypt.1
MLINKS=	ccrypt.1 ccencrypt.1 \
	ccrypt.1 ccdecrypt.1 \
	ccrypt.1 ccat.1

post-patch:
	@${PERL} -pi -e "s,gtar,tar,g" ${WRKSRC}/configure

.include <bsd.port.mk>
