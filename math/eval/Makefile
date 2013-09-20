# Created by: eserte
# $FreeBSD$

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

USE_LHA=	yes

PLIST_FILES=		bin/Eval

WRKSRC=		${WRKDIR}/Eval/source

NO_STAGE=	yes
post-extract:
	-${LN} -s Makefile.unx ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Eval ${PREFIX}/bin

.include <bsd.port.mk>
