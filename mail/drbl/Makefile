# New ports collection makefile for:	drbl
# Date created:				21 March 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	drbl
PORTVERSION=	1.06
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.drbl.ofisp.org/drbl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	leeym@FreeBSD.org

NO_BUILD=	yes

do-install:
	@${MKDIR} ${DATADIR}
.for file in README header zones
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}
.endfor
.for file in access2drbl build_drbl
	@${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
