# New ports collection makefile for:	virtualpaper
# Version required:	1.2
# Date created:		13 June 1996
# Whom:			jkh
#
# $Id: Makefile,v 1.6 1996/04/18 07:58:21 tg Exp $
#

DISTNAME=	virtualpaper-1.3
CATEGORIES+=	print
DISTFILES=	sources.tar.Z
MASTER_SITES=	http://www.research.digital.com:80/SRC/virtualpaper/cgi-bin/nph-download.tcl/sources.tar.Z?object=Virtual+Paper/
BUILD_DEPENDS=	m3build:${PORTSDIR}/lang/modula-3
RUN_DEPENDS=	m3ship:${PORTSDIR}/lang/modula-3

do-build:
	@(cd ${WRKSRC}/lecternclient ; m3build)
	@(cd ${WRKSRC}/lecterndoc; m3build)
	@(cd ${WRKSRC}/lectern; m3build)
	@(cd ${WRKSRC}/ocr; m3build)
	@(cd ${WRKSRC}/buildlectern; m3build)
	@(cd ${WRKSRC}/editlectern; m3build)

do-install:
	@(cd ${WRKSRC}/lecternclient ; m3ship)
	@(cd ${WRKSRC}/lecterndoc; m3ship)
	@(cd ${WRKSRC}/lectern; m3ship)
	@(cd ${WRKSRC}/ocr; m3ship)
	@(cd ${WRKSRC}/buildlectern; m3ship)
	@(cd ${WRKSRC}/editlectern; m3ship)
	@/sbin/ldconfig -m ${PREFIX}/lib/m3/FreeBSD2

.include <bsd.port.mk>
