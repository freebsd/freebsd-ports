# New ports collection makefile for:    eval
# Date created:         24 Sep 1997
# Whom:                 eserte
#
# $FreeBSD$
#

PORTNAME=	eval
PORTVERSION=	113
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.doc.ic.ac.uk/Mirrors/wuarchive.wustl.edu/pub/aminet/util/cli/ \
		ftp://ftp.uni-paderborn.de/ftp/aminet/pub/util/cli/ 
DISTNAME=	Eval${PORTVERSION}
EXTRACT_SUFX=	.lha

MAINTAINER=	eserte@cs.tu-berlin.de
COMMENT=	A full featured floating point expression evaluator

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha

EXTRACT_CMD=		${CAT}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	| lha x -
PLIST_FILES=		bin/Eval

WRKSRC=		${WRKDIR}/Eval/source

post-extract:
	-${LN} -s Makefile.unx ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Eval ${PREFIX}/bin

.include <bsd.port.mk>
