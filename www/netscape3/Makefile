# New ports collection makefile for:	netscape
# Version required:     3.0b5
# Date created:		21 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.5 1996/06/09 12:29:45 asami Exp $
#

DISTNAME=       netscape-3.0b5
CATEGORIES+=	www
MASTER_SITES=   ftp://ftp13.netscape.com/pub/navigator/3.0/3.0b5/unix/
DISTFILES=      netscape-v30b5-export.x86-unknown-bsd.tar.gz

MAINTAINER=	jkh@FreeBSD.ORG

RESTRICTED=	"Commercial software."
NO_WRKSUBDIR=	yes

post-install:
	@cat ${PKGDIR}/DESCR

.include <bsd.port.mk>
