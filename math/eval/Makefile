# New ports collection makefile for:    eval
# Version required:     113
# Date created:         24 Sep 1997
# Whom:                 eserte
#
# $Id: Makefile,v 1.1.1.1 1998/04/26 03:25:09 mph Exp $
#

DISTNAME=	Eval113
PKGNAME=	eval-113
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.doc.ic.ac.uk/Mirrors/wuarchive.wustl.edu/pub/aminet/util/cli/ \
		ftp://ftp.uni-paderborn.de/ftp/aminet/pub/util/cli/ 
EXTRACT_SUFX=	.lha

MAINTAINER=	eserte@cs.tu-berlin.de

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha

EXTRACT_CMD=	lha

WRKSRC=		${WRKDIR}/Eval/source

post-extract:
	-ln -s Makefile.unx ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Eval ${PREFIX}/bin

.include <bsd.port.mk>
