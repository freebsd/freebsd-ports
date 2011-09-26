# New ports collection makefile for:	linux-seamonkey
# Date created:		1 February 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	seamonkey
PORTVERSION=	2.0.14
CATEGORIES=	www
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${PORTVERSION}/linux-i686/en-US

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

FORBIDDEN=	Vulnerable since 2011-09-03, http://portaudit.freebsd.org/aa5bc971-d635-11e0-b3cf-080027ef73ec.html
EXPIRATION_DATE=	2011-10-14

USE_BZIP2=	yes

USE_LINUX_APPS=	dbusglib dbuslibs alsalib

.include "${.CURDIR}/Makefile.common"
.include <bsd.port.mk>
