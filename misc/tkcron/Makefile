# New ports collection makefile for:	tkcron-2.12
# Version required:	2.12
# Date created:		30 July 1996
# Whom:			Sander Vesik <sander@haldjas.folklore.ee>
#
# $Id: Makefile,v 1.1.1.1 1996/11/29 07:08:22 tg Exp $
#

DISTNAME=	tkcron-2.12
DISTFILES=	tkcron-2.12.tcl.gz
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.neosoft.com/languages/tcl/alcatel/code/
EXTRACT_SUFX=	.tcl.gz

MAINTAINER=	sander@haldjas.folklore.ee

RUN_DEPENDS=	wish4\.1:${PORTSDIR}/x11/tk41

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS= -cd
EXTRACT_AFTER_ARGS= > tkcron.tcl
NO_WRKSUBDIR=	yes

post-extract:
	@${CP} files/Makefile ${WRKSRC}

.include <bsd.port.mk>
