# New ports collection makefile for:	netscape
# Version required:     3.04
# Date created:		21 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.27 1999/01/06 04:18:08 simokawa Exp $
#

DISTNAME=       netscape-3.04
CATEGORIES=	www
MASTER_SITES=   ftp://archive:oldies@archive.netscape.com/archive/navigator/3.04/shipping/english/unix/bsdi11/navigator_complete/
DISTFILES=      netscape-v304-export.x86-unknown-bsd.tar.gz

MAINTAINER=     ports@FreeBSD.ORG

Y2K=		http://home.netscape.com/products/year2000/faq/client.html

NOT_FOR_ARCHS=	alpha

NO_LATEST_LINK=	yes
NO_WRKSUBDIR=	yes

.if defined(GOLD)
MASTER_SITES=   ftp://archive:oldies@archive.netscape.com/archive/navigator/3.04/shipping/english/unix/bsdi11/navigator_gold_complete/
DIST_SUBDIR=    gold
PKGNAME=	${DISTNAME}-gold
.endif

.if defined(USE_128BIT) && defined(USA_RESIDENT) && ${USA_RESIDENT} == NO
MASTER_SITES+=	ftp://ftp.fortify.net/pub/Fortify/ \
		ftp://ftp.za.freebsd.org/pub/Fortify/
DISTFILES+=	Fortify-1.3.2-unix-x86.tar.gz
RESTRICTED=     "Contains strong cryptography"
.endif

.if !defined(USE_128BIT)
pre-extract:
		@${ECHO} "You can make Netscape use 128-bit encryption by defining USE_128BIT"
		@${ECHO} "and defining USA_RESIDENT to NO"
.endif

post-install:
.if defined(USE_128BIT) && defined(USA_RESIDENT) && ${USA_RESIDENT} == NO
	cd ${WRKSRC}/Fortify-1.3.2-unix-x86 && \
		(${ECHO} yes ; ${ECHO} no) | ./Fortify.sh ${PREFIX}/lib/netscape/netscape.bin
.endif
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
