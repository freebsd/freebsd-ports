# New ports collection Makefile for:	proxy-suite
# Date created:				06 April 2001
# Whom:					Thomas Quinot <thomas@cuivre.fr.eu.org>
#
# $FreeBSD$
#

PORTNAME=	proxy-suite
PORTVERSION=	1.7
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.suse.com/pub/projects/proxy-suite/ \
		ftp://ftp.crc.ca/pub/systems/linux/suse/projects/proxy-suite/ \
		ftp://ftp.gwdg.de/pub/linux/suse/ftp.suse.com/projects/proxy-suite/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.suse.com/pub/projects/proxy-suite/

MAINTAINER=	thomas@cuivre.fr.eu.org

CONFIGURE_ARGS=	--with-libwrap=/usr/lib/

USE_AUTOCONF=	yes
USE_GMAKE=	yes

MAN8=		ftp-proxy.8
MAN5=		ftp-proxy.conf.5

pre-install:
	@strip ${WRKSRC}/ftp-proxy/ftp-proxy

.include <bsd.port.mk>
