# New ports collection makefile for:	netscape
# Version required:     3.01
# Date created:		21 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.2 1996/11/01 22:06:42 ache Exp $
#

DISTNAME=       netscape-3.01
CATEGORIES+=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/navigator/3.01/unix/
DISTFILES=      netscape-v301-export.x86-unknown-bsd.tar.gz

MAINTAINER=     ache@FreeBSD.ORG

RESTRICTED=	"Commercial software."
NO_WRKSUBDIR=	yes

post-install:
	@cat ${PKGDIR}/DESCR

.include <bsd.port.mk>
