# New ports collection makefile for:	snort
# Date created:		Mon Aug  2 12:04:08 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snort
PORTVERSION=	1.6.2.2
CATEGORIES=	security
MASTER_SITES=	http://www.snort.org/Files/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.org

GNU_CONFIGURE=	yes
MAN8=		snort.8

post-install:
	${MKDIR} ${PREFIX}/share/snort
.for i in CREDITS RULES.SAMPLE USAGE backdoor-lib ddos-lib finger-lib ftp-lib \
	  misc-lib netbios-lib overflow-lib ping-lib rpc-lib scan-lib smtp-lib \
	  snort-lib telnet-lib webcf-lib webcgi-lib webfp-lib webiis-lib webmisc-lib
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/snort
.endfor

.include <bsd.port.mk>
