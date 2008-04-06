# Ports collection makefile for: afflib
#
# Date created: 	15/02/2008
# Whom: 		Chris Calvey <chris@securityforensics.co.uk>
#
# $FreeBSD$
#

PORTNAME=	afflib
PORTVERSION=	3.1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.afflib.org/downloads/

MAINTAINER=	chris@securityforensics.co.uk
COMMENT=	The Advanced Forensics Format library and utilities

LIB_DEPENDS=	fuse:${PORTSDIR}/sysutils/fusefs-libs \
 		expat:${PORTSDIR}/textproc/expat2 \
		curl:${PORTSDIR}/ftp/curl

USE_OPENSSL=	yes
USE_ICONV =	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:261
CONFIGURE_ARGS=	--enable-s3=yes
CONFIGURE_ENV=	CPPFLAGS='-DFUSE_USE_VERSION=26' \
		LDFLAGS='${PTHREAD_LIBS}'
CFLAGS+=	${PTHREAD_LIBS}

.include <bsd.port.mk>
