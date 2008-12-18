# Ports collection makefile for:  bro
# Date created:			  Sat Feb 28, 1998
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	bro
PORTVERSION=	1.4
CATEGORIES=	security
MASTER_SITES=	ftp://bro-ids.org/
DISTNAME=	${PORTNAME}-${PORTVERSION}-release

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	System for detecting Network Intruders in real-time

USE_PERL5=	yes
WRKSRC=		${WRKDIR}/bro-${PORTVERSION}

LIB_DEPENDS=	GeoIP:${PORTSDIR}/net/GeoIP

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-perftools
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	@${INSTALL_DATA} ${WRKSRC}/aux/broccoli/broccoli.conf \
	   	${PREFIX}/etc/broccoli.conf.sample
	@if [ ! -f ${PREFIX}/etc/broccoli.conf ]; then \
		${CP} -p ${PREFIX}/etc/broccoli.conf.sample \
		${PREFIX}/etc/broccoli.conf ; \
	fi

.include <bsd.port.mk>
