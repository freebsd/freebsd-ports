# New ports collection makefile for:	snort
# Version required:	1.2
# Date created:		Mon Aug  2 12:04:08 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $Id: Makefile,v 1.1.1.1 1999/08/02 10:14:10 dirk Exp $
#

DISTNAME=	snort-1.2.1
CATEGORIES=	security net
MASTER_SITES=	http://www.clark.net/~roesch/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.org

GNU_CONFIGURE=	yes

post-install:
	${MKDIR} ${PREFIX}/share/snort
.for i in CREDITS RULES.SAMPLE USAGE backdoor-lib misc-lib overflow-lib \
          scan-lib snort-lib web-lib
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/snort
.endfor

.include <bsd.port.mk>
