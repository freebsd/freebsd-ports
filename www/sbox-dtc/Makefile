# Ports collection makefile for:        dtc
# Date created:                 12 January 2005
# Whom:                         Thomas Goirand
#
# $FreeBSD$
#

PORTNAME=	sbox-dtc
PORTVERSION=	1.07.1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.gplhost.com/pub/sbox-dtc/bsd/

MAINTAINER=	thomas@goirand.fr
COMMENT=	A safe CGI wrapper

USE_APACHE=	yes
CFLAGS+=	-DWEB_GROUP='\"nobody\"'
MAKE_ARGS=	CC="${CC}" COPTS="${CFLAGS}" \
		INSTALL_DIRECTORY=${PREFIX}/www/cgi-bin

PLIST_FILES=	www/cgi-bin/sbox

.if defined(WITH_APACHE2)
IGNORE=		Untested
.endif

.include <bsd.port.mk>
