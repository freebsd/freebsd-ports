# New ports collection makefile for:	netscape
# Version required:     4.0b2
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.16 1996/12/08 01:04:24 max Exp $
#

DISTNAME=       netscape-4.0b2
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.0/4.0b2/unix/other/
DISTFILES=      netscape-v40b2-export.x86-unknown-bsd.tar.gz

MAINTAINER=     ache@FreeBSD.ORG

RESTRICTED=	"Commercial software"
NO_WRKSUBDIR=	yes

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
