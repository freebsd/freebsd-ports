# Ports collection Makefile for:	heimdal
# Version required:			0.2a
# Date created:				10/23/1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

DISTNAME=		heimdal-0.2a
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.pdc.kth.se/pub/heimdal/src/

MAINTAINER=		nectar@FreeBSD.ORG

RESTRICTED=             "Crypto; export-controlled"

USE_LIBTOOL=		YES
USE_GMAKE=		YES
CONFIGURE_ARGS=		--enable-shared=YES
CONFIGURE_ENV=		INSTALL_TMP="${INSTALL} -m 444"
MAKE_ENV=		INSTALL_TMP="${INSTALL} -m 444"

.if defined(HEIMDAL_HOME)
PREFIX=			${HEIMDAL_HOME}
.endif

.include <bsd.port.mk>
