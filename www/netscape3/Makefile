# New ports collection makefile for:	netscape
# Version required:     3.0
# Date created:		21 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.10 1996/08/12 16:30:08 ache Exp $
#

DISTNAME=       netscape-3.0
CATEGORIES+=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/navigator/3.0/unix/
DISTFILES=      netscape-v30-export.x86-unknown-bsd.tar.gz

MAINTAINER=	jkh@FreeBSD.ORG

RESTRICTED=	"Commercial software."
NO_WRKSUBDIR=	yes

post-install:
	@cat ${PKGDIR}/DESCR

.include <bsd.port.mk>
