# New ports collection makefile for:	netscape
# Version required:     3.04
# Date created:		21 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.17 1997/09/23 21:01:13 ache Exp $
#

DISTNAME=       netscape-3.04
CATEGORIES=	www
.if defined(GOLD)
MASTER_SITES=   ftp://ftp.netscape.com/pub/navigator/3.04/shipping/english/unix/bsdi11/navigator_gold_complete/
DIST_SUBDIR=    gold
.else
MASTER_SITES=   ftp://ftp.netscape.com/pub/navigator/3.04/shipping/english/unix/bsdi11/navigator_complete/
.endif
DISTFILES=      netscape-v304-export.x86-unknown-bsd.tar.gz

MAINTAINER=     ports@FreeBSD.ORG

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
