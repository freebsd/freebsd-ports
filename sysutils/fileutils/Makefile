# New ports collection makefile for:	GNU fileutils
# Date created:	Mon Jun  5 22:42:27 CEST 2000
# Whom: ust@cert.siemens.de
#
# $FreeBSD$
#

PORTNAME=	fileutils
PORTVERSION=	4.1
CATEGORIES=	sysutils
MASTER_SITES=   ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	fileutils

MAINTAINER=	cyrille.lefevre@laposte.net

# Global variables
#

LIB_DEPEND=	intl.1:${PORTSDIR}/devel/gettext

USE_PERL5=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
# --program-prefix=g is broken
CONFIGURE_ARGS=	--program-transform-name=s,^,g,
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
# PREFIX isn't honored. force it w/ prefix.
MAKE_ARGS=	prefix=${PREFIX}

MAN1=		gchgrp.1 gchmod.1 gchown.1 gcp.1 gdd.1 gdf.1 gdir.1 \
		gdircolors.1 gdu.1 ginstall.1 gln.1 gls.1 gmkdir.1 gmkfifo.1 \
		gmknod.1 gmv.1 grm.1 grmdir.1 gshred.1 gsync.1 gtouch.1 gvdir.1

.include <bsd.port.mk>
