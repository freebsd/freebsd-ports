# New ports collection makefile for:	netscape
# Version required:     3.0b3
# Date created:		21 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.2 1996/03/29 23:11:17 asami Exp $
#

DISTNAME=       netscape-3.0b3
CATEGORIES+=	www
MASTER_SITES=   ftp://ftp8.netscape.com/pub/navigator/atlas/pr2/unix/standard/
DISTFILES=      netscape-vAtlas_b3-export.i386-unknown-bsd.tar.gz

MAINTAINER=	jkh@FreeBSD.ORG

NO_WRKSUBDIR=	yes
# commercial package
NO_PACKAGE=	yes

post-install:
	@cat ${PKGDIR}/DESCR

.include <bsd.port.mk>
