# New ports collection makefile for:	GeoIP
# Date created:				10 August 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	GeoIP
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://maxmind.com/download/geoip/api/c/

MAINTAINER=	leeym@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-gnu-ld=yes
INSTALLS_SHLIB=	yes

MAN1=		geoiplookup.1 geoipupdate.1

post-install:
	@${CAT} ${PKGMESSAGES}

.include <bsd.port.mk>
