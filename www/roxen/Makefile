# New ports collection makefile for:	Roxen Challenger
# Version required:	1.2final-int
# Date created:		26 February 1999
# Whom:			Kai Voigt (k@123.org)
#
# $Id: Makefile,v 1.2 1999/08/22 23:33:31 mharo Exp $
#

DISTNAME=	Roxen_1.2final-int
PKGNAME=	Roxen-1.2.46
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.roxen.com/roxen/source/

MAINTAINER=	k@123.org

WRKSRC=		${WRKDIR}/roxen_1.2.46
#HAS_CONFIGURE=	yes

INSTALL_TARGET=	install

pre-build:
	(cd ${WRKDIR}/roxen_1.2.46 ; ./configure)

post-install:
	@${CP} ${FILESDIR}/roxen.sh ${PREFIX}/etc/rc.d/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
