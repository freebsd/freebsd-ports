# New ports collection makefile for:	netscape
# Version required:     3.0b4
# Date created:		21 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.3 1996/04/24 20:41:55 ache Exp $
#

DISTNAME=       netscape-3.0b4
CATEGORIES+=	www
MASTER_SITES=   ftp://ftp13.netscape.com/pub/navigator/3.0/3.0b4/unix/standard/
DISTFILES=      netscape-v30b4-export.i386-unknown-bsd.tar.gz

MAINTAINER=	jkh@FreeBSD.ORG

NO_WRKSUBDIR=	yes
# commercial package
NO_PACKAGE=	yes

post-install:
	@cat ${PKGDIR}/DESCR

.include <bsd.port.mk>
