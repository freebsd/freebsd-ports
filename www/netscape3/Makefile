# New ports collection makefile for:	netscape
# Version required:     3.0b5a
# Date created:		21 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.6 1996/07/01 19:03:01 gpalmer Exp $
#

DISTNAME=       netscape-3.0b5a
CATEGORIES+=	www
MASTER_SITES=   ftp://ftp13.netscape.com/pub/navigator/3.0/3.0b5/unix/
DISTFILES=      netscape-v30b5a-export.x86-unknown-bsd.tar.gz

MAINTAINER=	jkh@FreeBSD.ORG

RESTRICTED=	"Commercial software."
NO_WRKSUBDIR=	yes

post-install:
	@cat ${PKGDIR}/DESCR

.include <bsd.port.mk>
