# New ports collection makefile for:	tkcron-2.12
# Version required:	2.12
# Date created:		30 July 1996
# Whom:			Sander Vesik <sander@haldjas.folklore.ee>
#
# $Id$
#

DISTNAME=	tkcron-2.12
DISTFILES=	tkcron-2.12.tcl.gz
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.neosoft.com/languages/tcl/alcatel/code/

MAINTAINER=	sander@haldjas.folklore.ee

RUN_DEPENDS=	wish4\.1:${PORTSDIR}/x11/tk41

EXTRACT_CMD=	/usr/bin/gunzip
EXTRACT_SUFX=	.tcl.gz
EXTRACT_BEFORE_ARGS= -c
EXTRACT_AFTER_ARGS= > tkcron.tcl
NO_WRKSUBDIR=	yes

post-extract:
	@cp	files/Makefile ${WRKDIR}

.include <bsd.port.mk>
