# New ports collection makefile for:    sharefonts
# Version required:     0.10
# Date created:         Thu Mar 26 04:50:00 PST 1998
# Whom:                 dburr@FreeBSD.ORG
#
# $Id: Makefile,v 1.2 1998/08/05 09:31:48 asami Exp $
#

DISTNAME=	sharefonts-0.10
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/fonts/

MAINTAINER=	dburr@FreeBSD.ORG

RESTRICTED=	"Shareware.  Cannot be distributed w/o prior authorization."
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

NO_BUILD=	yes

USE_X_PREFIX=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/X11/fonts/sharefont
	${CP} ${WRKDIR}/sharefont/* ${PREFIX}/lib/X11/fonts/sharefont
	chmod 755 ${PREFIX}/lib/X11/fonts/sharefont
	chmod 644 ${PREFIX}/lib/X11/fonts/sharefont/*

post-install:
	@cat ${PKGDIR}/DESCR

.include <bsd.port.mk>
