# New ports collection makefile for:	tkcron-2.12
# Date created:		30 July 1996
# Whom:			Sander Vesik <sander@haldjas.folklore.ee>
#
# $FreeBSD$
#

PORTNAME=	tkcron
PORTVERSION=	2.12
CATEGORIES=	misc tk82
MASTER_SITES=	http://www.neosoft.com/tcl/ftparchive/sorted/misc/tkcron-2.12/
EXTRACT_SUFX=	.tcl.gz

MAINTAINER=	sander@haldjas.folklore.ee
COMMENT=	A frontend to crontab

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS= -cd
EXTRACT_AFTER_ARGS= > tkcron.tcl
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/tkcron

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
