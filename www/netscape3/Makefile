# New ports collection makefile for:	netscape
# Version required:     3.04
# Date created:		21 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.19 1998/01/26 09:53:03 vanilla Exp $
#

DISTNAME=       netscape-3.04
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/navigator/3.04/shipping/english/unix/bsdi11/navigator_complete/
DISTFILES=      netscape-v304-export.x86-unknown-bsd.tar.gz

MAINTAINER=     ports@FreeBSD.ORG

NO_WRKSUBDIR=	yes

.if defined(GOLD)
MASTER_SITES=   ftp://ftp.netscape.com/pub/navigator/3.04/shipping/english/unix/bsdi11/navigator_gold_complete/
DIST_SUBDIR=    gold
PKGNAME=	${DISTNAME}-gold
.endif

.if defined(USE_128BIT) && ${USA_RESIDENT} == NO
MASTER_SITES+=	ftp://ftp.fortify.net/pub/Fortify/ \
		ftp://ftp.za.freebsd.org/pub/Fortify/
DISTFILES+=	Fortify-1.2.1-unix.tar.gz
RESTRICTED=     "Contains strong cryptography"
.endif

.if !defined(USE_128BIT) && ${USA_RESIDENT} == NO
pre-extract:
		@${ECHO} "You can make Netscape use 128-bit encryption by defining USE_128BIT"
.endif

post-install:
.if defined(USE_128BIT) && ${USA_RESIDENT} == NO
	cd ${WRKSRC}/Fortify-1.2.1-unix && \
		(${ECHO} yes ; ${ECHO} no) | ./Fortify.sh ${PREFIX}/lib/netscape/netscape.bin
.endif
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
