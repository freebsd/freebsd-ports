# New ports collection makefile for:	www/web-traceroute
# Date created:		Sun Oct 26 12:00:00 WST 2003
# Whom:			Dean Hollister <dean@odyssey.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	web-traceroute
PORTVERSION=	3.0
CATEGORIES=	www
MASTER_SITES=	http://www.carpe.net/src/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/
DISTNAME=	${PORTNAME}

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	WWW Traceroute CGI script written in C

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

PLIST_FILES=	www/cgi-bin/trace
USE_APACHE=	13

#pre-configure:
#	${SH} ${SCRIPTDIR}/locate-template.sh

.include <bsd.port.mk>
