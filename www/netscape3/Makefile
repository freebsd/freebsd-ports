# New ports collection makefile for:	netscape
# Version required:     3.01
# Date created:		21 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.15 1996/11/30 10:50:22 asami Exp $
#

DISTNAME=       netscape-3.01
CATEGORIES=	www
.if defined(GOLD)
MASTER_SITES=   ftp://ftp.netscape.com/pub/navigator/gold/3.01/unix/
DIST_SUBDIR=    gold
.else
MASTER_SITES=   ftp://ftp.netscape.com/pub/navigator/3.01/unix/
.endif
DISTFILES=      netscape-v301-export.x86-unknown-bsd.tar.gz

MAINTAINER=     ache@FreeBSD.ORG

RESTRICTED=	"Commercial software"
NO_WRKSUBDIR=	yes

pre-fetch:
.if !defined(GOLD)
	@${ECHO_MSG} "Note you can make the \"gold\" version by typing \"make GOLD=yes\"."
.else
	@${ECHO_MSG} "Making the \"gold\" version."
.endif

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
