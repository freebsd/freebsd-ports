# New ports collection makefile for:	mapedit
# Version required:	2.24
# Date created:		Fr   4 Apr 1997 17:45:31 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.8 1997/10/08 07:51:35 asami Exp $
#

DISTNAME=	mapedit2.3
PKGNAME=	mapedit-2.3
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.boutell.com/pub/boutell/mapedit/

MAINTAINER=	andreas@FreeBSD.ORG

RUN_DEPENDS=	${PREFIX}/java/bin/java:${PORTSDIR}/lang/jdk

NO_BUILD=	yes

pre-install:
	@cat ${WRKSRC}/README.TXT
	@echo ""

do-install:
	${MKDIR} ${PREFIX}/lib/mapedit
	${CP} -r ${WRKSRC}/* ${PREFIX}/lib/mapedit
	${INSTALL_SCRIPT} ${PREFIX}/lib/mapedit/mapedit ${PREFIX}/bin
	${RM} -f ${PREFIX}/lib/mapedit/mapedit

.include <bsd.port.mk>
