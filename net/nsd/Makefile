# New ports collection makefile for:	nsd
# Date created:				08 August 2002
# Whom:					alexis
#
# $FreeBSD$
#

PORTNAME=	nsd
PORTVERSION=	1.0.1
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/

MAINTAINER=	nsd-info@nlnetlabs.nl

MAN8=	nsd.8 zonec.8 nsdc.8

post-install:
	${INSTALL_DATA} ${WRKSRC}/nsd.zones.sample \
		${PREFIX}/etc/nsd/nsd.zones.sample

.include <bsd.port.mk>
