# New ports collection makefile for:    afm
# Version required:     ?
# Date created:         23 November 1994
# Whom:                 ljo
#
# $Id: Makefile,v 1.3 1995/04/15 04:33:37 asami Exp $
#

DISTNAME=	afm
PKGNAME=	afm-1.0
CATEGORIES+=	printing
MASTER_SITES=	ftp://sgi.com/sgi/fax/source/
EXTRACT_SUFX=   -tar.Z

pre-patch:
	rm -rf ${WRKSRC}/RCS

build: configure

.include <bsd.port.mk>
