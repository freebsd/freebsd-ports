# New ports collection makefile for:	nsd
# Date created:				08 August 2002
# Whom:					alexis
#
# $FreeBSD$
#

PORTNAME=	nsd
PORTVERSION=	1.2.2
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An authoratative only non-recursive high performance name server

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-user=bind \
		--enable-ipv6 \
		--with-configdir=${PREFIX}/etc/nsd \
		--with-pidfile=/var/run/nsd.pid \
		--with-dbfile=/var/db/nsd.database \
		--with-namedxfer=/usr/libexec/named-xfer \
		--with-libwrap

MAN8=	nsd.8 zonec.8 nsdc.8

post-install:
	${INSTALL_DATA} ${WRKSRC}/nsd.zones.sample \
		${PREFIX}/etc/nsd/nsd.zones.sample

.include <bsd.port.mk>
