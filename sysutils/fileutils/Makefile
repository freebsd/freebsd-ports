# New ports collection makefile for:	GNU fileutils
# Date created:	Mon Jun  5 22:42:27 CEST 2000
# Whom: ust@cert.siemens.de
#
# $FreeBSD$
#

PORTNAME=	fileutils
PORTVERSION=	4.0
CATEGORIES=	sysutils
MASTER_SITES=   ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	fileutils

MAINTAINER=	clefevre@citeweb.net

#
# Global variables
#

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g

MAN1=		gchgrp.1 gchmod.1 gchown.1 gcp.1 gdd.1 gdf.1 gdir.1 \
		gdircolors.1 gdu.1 ginstall.1 gln.1 gls.1 gmkdir.1 gmkfifo.1 \
		gmknod.1 gmv.1 grm.1 grmdir.1 gsync.1 gtouch.1 gvdir.1

#
# Local variables
#

INSTALL_INFO?=	install-info

post-install:
	@${INSTALL_INFO} ${PREFIX}/info/${PORTNAME}.info ${PREFIX}/info/dir

.include <bsd.port.mk>
