# New ports collection makefile for:	netscape
# Version required:     3.01
# Date created:		21 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.12 1996/11/07 00:03:04 ache Exp $
#

DISTNAME=       netscape-3.01
CATEGORIES+=	www
.if defined(GOLD)
MASTER_SITES=   ftp://ftp.netscape.com/pub/navigator/gold/3.01/unix/
MD5_FILE=       ${FILESDIR}/md5.gold
DIST_SUBDIR=    gold
.else
MASTER_SITES=   ftp://ftp.netscape.com/pub/navigator/3.01/unix/
.endif
DISTFILES=      netscape-v301-export.x86-unknown-bsd.tar.gz

MAINTAINER=     ache@FreeBSD.ORG

RESTRICTED=	"Commercial software."
NO_WRKSUBDIR=	yes

post-install:
	@cat ${PKGDIR}/DESCR

.include <bsd.port.mk>
