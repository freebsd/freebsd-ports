# New ports collection makefile for:	snort
# Date created:		Mon Aug  2 12:04:08 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snort
PORTVERSION= 	1.6
CATEGORIES=	security net
MASTER_SITES=	http://www.clark.net/~roesch/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.org

GNU_CONFIGURE=	yes
MAN8=		snort.8

post-install:
	${MKDIR} ${PREFIX}/share/snort
.for i in CREDITS RULES.SAMPLE USAGE backdoor-lib misc-lib overflow-lib \
          scan-lib snort-lib web-lib
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/snort
.endfor
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${PREFIX}/man/man8

.include <bsd.port.mk>
