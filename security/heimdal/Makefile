# Ports collection Makefile for:	heimdal
# Version required:			0.2a
# Date created:				10/23/1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

DISTNAME=		heimdal-0.2c
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.pdc.kth.se/pub/heimdal/src/ \
			ftp://ftp.replay.com/pub/replay/crypto/APPS/kerberos/heimdal/ \
			ftp://ftp.tuniv.szczecin.pl/dsk4/ftp.replay.com/pub/crypto/APPS/kerberos/heimdal/ \
			ftp://ftp.hacktic.nl/pub/replay/crypto/APPS/kerberos/heimdal/

MAINTAINER=		nectar@FreeBSD.ORG

RESTRICTED=             "Crypto; export-controlled"

USE_LIBTOOL=		YES
USE_GMAKE=		YES
CONFIGURE_ARGS=		--enable-shared=YES
CONFIGURE_ENV=		INSTALL_TMP="cp"
MAKE_ENV=		INSTALL_TMP="cp"

.if defined(HEIMDAL_HOME)
PREFIX=			${HEIMDAL_HOME}
.endif

# XXX  I patched Makefile*, but I want to avoid rerunning automake
post-patch:
	find ${WRKSRC} -name Makefile.in -print | xargs ${TOUCH}

.include <bsd.port.mk>
