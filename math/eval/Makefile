# New ports collection makefile for:    eval
# Date created:         24 Sep 1997
# Whom:                 eserte
#
# $FreeBSD$
#

PORTNAME=	eval
PORTVERSION=	113
CATEGORIES=	math
MASTER_SITES=	ftp://wuarchive.wustl.edu/pub/aminet/util/cli/ \
		http://www.netsw.org/math/calc/ \
		http://main.aminet.net/util/cli/
DISTNAME=	Eval${PORTVERSION}
EXTRACT_SUFX=	.lha

MAINTAINER=	slaven@rezic.de
COMMENT=	A full featured floating point expression evaluator

EXTRACT_DEPENDS=lha:${PORTSDIR}/archivers/lha

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
