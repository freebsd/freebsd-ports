# New ports collection makefile for:	netscape
# Version required:     2.0
# Date created:		21 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.13 1996/03/17 21:52:50 adam Exp $
#

DISTNAME=       netscape-3.0b2
CATEGORIES+=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/navigator/atlas/pr1/
DISTFILES=      netscape-vAtlas_b2-export.i386-unknown-bsd.tar.gz

MAINTAINER=	jkh@FreeBSD.ORG

NO_WRKSUBDIR=	yes
# commercial package
NO_PACKAGE=	yes

post-install:
	@cat ${PKGDIR}/DESCR

.include <bsd.port.mk>
